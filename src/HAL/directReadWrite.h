#pragma once

#include "Arduino.h"
#include "cores.h"
#include "SimplyAtomic/SimplyAtomic.h"


namespace HAL
{
    constexpr uint8_t not_a_pin = -1;

    struct pinRegInfo_t;
    extern pinRegInfo_t getPinRegInfo(uint8_t pin);
    extern uint8_t directRead(const pinRegInfo_t &info);
    extern void directWrite(const pinRegInfo_t &info, uint8_t value);

#if defined(CORE_AVR_ARDUINO) //----------------------------------------------------------------------------

    struct pinRegInfo_t
    {
        uint8_t pin           = -1;
        volatile uint8_t *in  = nullptr;
        volatile uint8_t *out = nullptr;
        uint8_t mask          = 0;

        pinRegInfo_t() = default;
        inline pinRegInfo_t(uint8_t pin);
    };

    pinRegInfo_t::pinRegInfo_t(uint8_t _pin)
    {
        if (_pin >= NUM_DIGITAL_PINS) return;
        pin  = _pin;
        in   = portInputRegister(digitalPinToPort(pin));
        out  = portOutputRegister(digitalPinToPort(pin));
        mask = digitalPinToBitMask(pin);
    };

    inline pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }

    inline uint8_t directRead(const pinRegInfo_t &info)
    {
        return *info.in & info.mask ? 1 : 0;
    }

    inline void directWrite(const pinRegInfo_t &info, uint8_t value)
    {
        ATOMIC()
        {
            value ? *info.out |= info.mask : *info.out &= ~info.mask;
        }
    }

#elif defined(CORE_TEENSY__TEENSY3) //--------------------------
    struct pinRegInfo_t
    {
        uint8_t pin           = -1;
        volatile uint8_t *in  = nullptr;
        volatile uint8_t *clr = nullptr;
        volatile uint8_t *set = nullptr;

        pinRegInfo_t() = default;
        inline pinRegInfo_t(uint8_t pin);
    };

    pinRegInfo_t::pinRegInfo_t(uint8_t _pin)
    {
        pin = _pin;
        in  = portInputRegister(pin);
        clr = portClearRegister(pin);
        set = portSetRegister(pin);
    }

    inline pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }

    inline void directWrite(const pinRegInfo_t &info, uint8_t value)
    {
        value ? *info.set = 1 : *info.clr = 1; // is atomic
    }

    inline uint8_t directRead(const pinRegInfo_t &info)
    {
        return *info.in;
    }

#elif defined(CORE_TEENSY__TEENSY4) //--------------------------------------------

    struct pinRegInfo_t
    {
        uint8_t pin            = -1;
        volatile uint32_t *in  = nullptr;
        volatile uint32_t *clr = nullptr;
        volatile uint32_t *set = nullptr;
        uint32_t mask          = 0;

        inline pinRegInfo_t() = default;
        inline pinRegInfo_t(uint8_t pin);
    };

    pinRegInfo_t::pinRegInfo_t(uint8_t _pin)
    {
        if (_pin > NUM_DIGITAL_PINS) return;

        const struct digital_pin_bitband_and_config_table_struct *p = digital_pin_to_info_PGM + _pin;

        IMXRT_GPIO_t *gpio = (IMXRT_GPIO_t *)p->reg;
        pin                = _pin;
        in                 = &gpio->DR;
        clr                = &gpio->DR_CLEAR;
        set                = &gpio->DR_SET;
        mask               = p->mask;
    };

    inline pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }

    inline void directWrite(const pinRegInfo_t &info, uint8_t value)
    {
        value ? *info.set = info.mask : *info.clr = info.mask; // atomic
    }

    inline uint8_t directRead(const pinRegInfo_t &info)
    {
        return (*info.in & info.mask) ? 1 : 0;
    }

#elif defined(CORE_SAMD_SEED__ARDUINO) || defined(ARDUINO_SAMD__ARDUINO) //------------------------------------------------

    struct pinRegInfo_t
    {
        uint8_t pin            = UINT8_MAX;
        volatile uint32_t *in  = nullptr;
        volatile uint32_t *clr = nullptr;
        volatile uint32_t *set = nullptr;
        uint32_t mask          = 0;

        pinRegInfo_t() = default;
        inline pinRegInfo_t(uint8_t pin);
    };

    pinRegInfo_t::pinRegInfo_t(uint8_t _pin)
    {
        if (_pin >= NUM_DIGITAL_PINS) return;
        pin       = _pin;
        auto port = g_APinDescription[pin].ulPort;
        in        = &PORT->Group[port].IN.reg;
        clr       = &PORT->Group[port].OUTCLR.reg;
        set       = &PORT->Group[port].OUTSET.reg;
        mask      = (uint32_t)1 << g_APinDescription[pin].ulPin;
        // Serial.printf("pin: %d %p %p %p\n", pin, in, clr, set);
    }

    inline pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }

    inline void directWrite(const pinRegInfo_t &info, uint8_t value)
    {
        value ? *info.set = info.mask : *info.clr = info.mask;
    }
    inline uint8_t directRead(const pinRegInfo_t &info)
    {
        return (*info.in & info.mask) ? 1 : 0;
    }

#else // Fallback ----------------------------------------------------------------------------------

    struct pinRegInfo_t
    {
        uint8_t pin           = -1;
        inline pinRegInfo_t() = default;
        inline pinRegInfo_t(uint8_t _pin) { pin = _pin; }
    };

    inline pinRegInfo_t getPinRegInfo(uint8_t pin)
    {
        return pinRegInfo_t(pin);
    }
    inline void directWrite(const pinRegInfo_t &pin, uint8_t value)
    {
        digitalWrite(pin.pin, value);
    }
    inline uint8_t directRead(const pinRegInfo_t &pin)
    {
        return digitalRead(pin.pin);
    }
#endif

}