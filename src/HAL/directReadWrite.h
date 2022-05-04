#pragma once

#include "Arduino.h"

namespace HAL
{
    struct pinRegInfo_t;
    extern pinRegInfo_t getPinRegInfo(uint8_t pin);
    extern uint8_t drFast(const pinRegInfo_t& info);
    extern void dwFast(const pinRegInfo_t& info, uint8_t value);

#if defined(__AVR__) //----------------------------------------------------------------------------

#    include "util/atomic.h"

    struct pinRegInfo_t
    {
        uint8_t pin;
        volatile uint8_t* in;
        volatile uint8_t* out;
        uint8_t mask;

        inline pinRegInfo_t(uint8_t pin = -1);
    };

    pinRegInfo_t::pinRegInfo_t(uint8_t _pin)
    {
        pin  = _pin;
        in   = portInputRegister(digitalPinToPort(pin));
        out  = portOutputRegister(digitalPinToPort(pin));
        mask = digitalPinToBitMask(pin);
    };

    inline pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }

    inline uint8_t drFast(const pinRegInfo_t& info)
    {
        return *info.in & info.mask;
    }

    inline void dwFast(const pinRegInfo_t& info, uint8_t value)
    {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            value ? * info.out |= info.mask : * info.out &= ~info.mask;
        }
    }

#elif defined(TEENSYDUINO) && (defined(KINETISK) || defined(KINETISL)) //--------------------------
    struct pinRegInfo_t
    {
        uint8_t pin;
        volatile uint8_t* in;
        volatile uint8_t* clr;
        volatile uint8_t* set;

        inline pinRegInfo_t(uint8_t pin = -1);
    };

    pinRegInfo_t::pinRegInfo_t(uint8_t _pin)
    {
        pin = _pin;
        in  = portInputRegister(pin);
        clr = portClearRegister(pin);
        set = portSetRegister(pin);
    }

    pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }

    inline void dwFast(const pinRegInfo_t& info, uint8_t value)
    {
        value ? * info.set = 1 : * info.clr = 1; // is atomic
    }

    inline uint8_t dwFast(const pinRegInfo_t& info)
    {
        return *info.in;
    }

#elif defined(TEENSYDUINO) && defined(__IMXRT1062__) //--------------------------------------------

    struct pinRegInfo_t
    {
        uint8_t pin;
        volatile uint32_t* in;
        volatile uint32_t* clr;
        volatile uint32_t* set;
        uint32_t mask;

        inline pinRegInfo_t(uint8_t pin = -1);
    };

    pinRegInfo_t::pinRegInfo_t(uint8_t _pin)
    {
        const struct digital_pin_bitband_and_config_table_struct* p = digital_pin_to_info_PGM + pin;
        IMXRT_GPIO_t* gpio = (IMXRT_GPIO_t*)p->reg;

        pin  = _pin;
        in   = &gpio->DR;
        clr  = &gpio->DR_CLEAR;
        set  = &gpio->DR_SET;
        mask = p->mask;
    };

    pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }

    inline void dwFast(const pinRegInfo_t& info, uint8_t value)
    {
        value ? * info.set = info.mask : * info.clr = info.mask; // atomic
    }

    inline uint8_t drFast(const pinRegInfo_t& info)
    {
        return (*info.in & info.mask) ? 1 : 0;
    }

#elif defined(__SAMD51__) || defined(__SAMD21__) //------------------------------------------------

    struct pinRegInfo_t
    {
        volatile uint32_t* in;
        volatile uint32_t* clr;
        volatile uint32_t* set;
        uint32_t mask;
    };

    inline pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        auto port = g_APinDescription[pin].ulPort;
        return pinRegInfo_t{
            &PORT->Group[port].IN.reg,
            &PORT->Group[port].OUTCLR.reg,
            &PORT->Group[port].OUTSET.reg,
            (uint32_t)1 << g_APinDescription[pin].ulPin};
    }

    inline void ddWrite(const pinRegInfo_t& info, uint8_t value)
    {
        value ? * info.set = info.mask : * info.clr = info.mask;
    }
    inline uint8_t ddRead(const pinRegInfo_t& info)
    {
        return (*info.in & info.mask) ? 1 : 0;
    }

    // #else // generic ----------------------------------------------------------------------------------

    //     using pinRegInfo_t = uint8_t;
    //     inline pinRegInfo_t getPinRegInfo(uint8_t pin) { return pin; }
    //     inline void ddWrite(const pinRegInfo_t& pin, uint8_t value) { digitalWrite(pin, value); }
    //     inline uint8_t ddRead(const pinRegInfo_t& pin) { return digitalRead(pin); }

#endif

}