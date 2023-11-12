#pragma once

#include "EncoderButton.h"
#include "HAL/SimplyAtomic/SimplyAtomic.h"
#include "HAL/directReadWrite.h"
#include "config.h"

namespace EncoderTool
{
    enum class CountMode { // cnt per quad period | input at detents | remark
        quarter,           //          1          |       0/0        | standard for mech encoders
        quarterInv,        //          1          |       1/1        |
        half,              //          2          |   0/0 and 1/1    | seldom used
        halfAlt,           //          2          |   1/0 and 0/1    | seldom used
        full               //          4          |       n.a.       | standard for optical encoders w/o detents
    };

    template <typename ct>
    class EncoderBase
    {
     public:
        using counter_t = ct;
#if defined(USE_MODERN_CALLBACKS)
        using encCallback_t    = stdext::inplace_function<void(counter_t value, counter_t delta)>;
        using encBtnCallback_t = stdext::inplace_function<void(int_fast8_t state)>;
#else
        using encCallback_t    = void (*)(counter_t value, counter_t delta);
        using encBtnCallback_t = void (*)(int_fast8_t state);
#endif

        void begin(uint_fast8_t phaseA, uint_fast8_t phaseB);

        EncoderBase& setCountMode(CountMode);
        EncoderBase& attachCallback(encCallback_t);
        EncoderBase& attachButtonCallback(encBtnCallback_t);
        EncoderBase& setLimits(counter_t min, counter_t max, bool periodic = false);

        void setValue(counter_t val);
        counter_t getValue() const;
        bool valueChanged();

        uint8_t getButton();
        bool buttonChanged();

        counter_t update(uint_fast8_t phaseA, uint_fast8_t phaseB, uint_fast8_t btn = 0);
        counter_t updateBtn(uint_fast8_t btn);

     protected:
        EncoderBase()                              = default;
        EncoderBase& operator=(EncoderBase const&) = delete;
        EncoderBase(EncoderBase const&)            = delete;

        counter_t value  = 0;
        counter_t minVal = std::numeric_limits<counter_t>::min();
        counter_t maxVal = std::numeric_limits<counter_t>::max();
        bool valChanged  = false;

        EncoderButton button;
        bool btnChanged = false;

        bool periodic   = true;
        unsigned invert = 0x00;

        encCallback_t callback       = nullptr;
        encBtnCallback_t btnCallback = nullptr;

        static const uint8_t stateMachineQtr[7][4];
        static const uint8_t stateMachineHalf[7][4];
        static const uint8_t stateMachineFull[7][4];
        const uint8_t (*stateMachine)[7][4] = &stateMachineFull;
        uint8_t curState                    = 0;

        enum states : uint8_t {
            A     = 0x00,
            B_cw  = 0x01,
            C_cw  = 0x03,
            D_cw  = 0x02,
            B_ccw = 0x04,
            C_ccw = 0x06,
            D_ccw = 0x05,

            UP   = 0x10,
            DOWN = 0x20,
            ERR  = 0x30,
        };

        template <typename T>
        friend class EncPlexBase;

#if defined(USE_ERROR_CALLBACKS)
     protected:
        encCallback_t errCallback = nullptr;

     public:
        void attachErrorCallback(encCallback_t cb) { errCallback = cb; }
#endif

        static_assert(is_integral<counter_t>::value && is_signed<counter_t>::value, "Only signed integral types allowed");
    };

    // INLINE IMPLEMENTATION ==========================================================================

    template <typename counter_t>
    bool EncoderBase<counter_t>::valueChanged()
    {
        bool ret   = valChanged;
        valChanged = false;
        return ret;
    }

    template <typename counter_t>
    counter_t EncoderBase<counter_t>::getValue() const
    {
        if (sizeof(__SIG_ATOMIC_TYPE__) == sizeof(counter_t)) // compile time evaluation
            return value;
        else
        {
            ATOMIC()
            {
                return value;
            }
        }
        return value; // make the compiler happy
    }

    template <typename counter_t>
    void EncoderBase<counter_t>::setValue(counter_t val)
    {
        value = val;
    }

    template <typename counter_t>
    bool EncoderBase<counter_t>::buttonChanged()
    {
        bool ret   = btnChanged;
        btnChanged = false;
        return ret;
    }

    template <typename counter_t>
    uint8_t EncoderBase<counter_t>::getButton()
    {
        return button.read();
    }

    template <typename counter_t>
    EncoderBase<counter_t>& EncoderBase<counter_t>::setCountMode(CountMode mode)
    {
        switch (mode)
        {
            case CountMode::quarter:
                stateMachine = &stateMachineQtr;
                invert       = 0b11;
                break;
            case CountMode::quarterInv:
                stateMachine = &stateMachineQtr;
                invert       = 0b00;
                break;
            case CountMode::half:
                stateMachine = &stateMachineHalf;
                invert       = 0b00;
                break;
            case CountMode::halfAlt:
                stateMachine = &stateMachineHalf;
                invert       = 0b01;
                break;
            default:
                stateMachine = &stateMachineFull;
                invert       = 0b00;
        }
        return *this;
    }

    template <typename counter_t>
    EncoderBase<counter_t>& EncoderBase<counter_t>::attachCallback(encCallback_t cb)
    {
        callback = cb;
        return *this;
    }

    template <typename counter_t>
    EncoderBase<counter_t>& EncoderBase<counter_t>::attachButtonCallback(encBtnCallback_t cb)
    {
        btnCallback = cb;
        return *this;
    }

    template <typename counter_t>
    EncoderBase<counter_t>& EncoderBase<counter_t>::setLimits(counter_t min, counter_t max, bool periodic)
    {
        if (min < max)
        {
            this->minVal   = min;
            this->maxVal   = max;
            this->periodic = periodic;
        } else
        {
            this->minVal   = std::numeric_limits<counter_t>::min();
            this->maxVal   = std::numeric_limits<counter_t>::max();
            this->periodic = true;
        }
        return *this;
    }

    template <typename counter_t>
    void EncoderBase<counter_t>::begin(uint_fast8_t phaseA, uint_fast8_t phaseB)
    {
        curState = (phaseA << 1 | phaseB) ^ invert;
    }

    template <typename counter_t>
    counter_t EncoderBase<counter_t>::update(uint_fast8_t phaseA, uint_fast8_t phaseB, uint_fast8_t btn)
    {
        unsigned input = (phaseA << 1 | phaseB) ^ invert; // invert signals if necessary
        if (stateMachine == nullptr) return 0;            // tick might get called from yield before class is initialized

        curState          = (*stateMachine)[curState][input]; // get next state depending on new input
        uint8_t direction = curState & 0xF0;                  // direction is set if we need to count up / down or got an error
        curState &= 0x0F;                                     // remove the direction info from state

        if (direction == UP)
        {
            if (value < maxVal) // maxVal = INT_MAX if no limits set
            {
                value++;
                valChanged = true;
                if (callback != nullptr)
                    callback(value, +1);
                return +1;
            }
            if (periodic) // if periodic, wrap to minVal, else stop counting
            {
                value      = minVal;
                valChanged = true;

                if (callback != nullptr)
                    callback(value, +1);
                return +1;
            }
            value = maxVal;
            return false;
        }

        if (direction == DOWN)
        {
            if (value > minVal) // minVal = "counter_t min" if no limits set
            {
                value--;
                valChanged = true;
                if (callback != nullptr)
                    callback(value, -1);
                return -1;
            }
            if (periodic) // if periodic, wrap to maxVal, else stop counting
            {
                valChanged = true;
                value      = maxVal;
                if (callback != nullptr)
                    callback(value, -1);
                return -1;
            }
            value = minVal;
            return 0;
        }

#if defined(USE_ERROR_CALLBACKS)
        if (direction == ERR)
        {
            if (errCallback != nullptr)
                errCallback(value);
        }
#endif
        return false;
    }

    template <typename counter_t>
    counter_t EncoderBase<counter_t>::updateBtn(uint_fast8_t btn)
    {
        if (button.update(btn)) //button changed
        {
            btnChanged = true;
            if (btnCallback != nullptr)
            { 
              btnCallback(button.read());
              return -1;
            }
            else{
              return button.read();
            }
        }
        else
        {
          return -1;
        }

    //#if defined(USE_ERROR_CALLBACKS)
    // TODO: implement error callback for button
    // #endif
    }

    template <typename counter_t>
    const uint8_t EncoderBase<counter_t>::stateMachineQtr[7][4]{
        //             00         01          10         11
        /*0 A   */ {A, B_cw, D_ccw, A | ERR},
        /*1 B_cw*/ {A, B_cw, B_cw | ERR, C_cw},
        /*2 D_cw*/ {A | UP, D_cw | ERR, D_cw, C_cw},
        /*3 C_cw*/ {C_cw | ERR, B_cw, D_cw, C_cw},

        /*4 B_ccw*/ {A | DOWN, B_ccw, B_ccw | ERR, C_ccw},
        /*5 D_ccw*/ {A, D_ccw | ERR, D_ccw, C_ccw},
        /*6 C_ccw*/ {C_ccw | ERR, B_ccw, D_ccw, C_ccw},
    };

    template <typename counter_t>
    const uint8_t EncoderBase<counter_t>::stateMachineHalf[7][4]{
        //              00        01         10        11
        /*0 A   */ {A, B_cw, D_ccw, A | ERR},
        /*1 B_cw*/ {A, B_cw, B_cw | ERR, C_cw | UP},
        /*2 D_cw*/ {A | UP, D_cw | ERR, D_cw, C_cw},
        /*3 C_cw*/ {C_cw | ERR, B_ccw, D_cw, C_cw}, // C_ccw = C_cw

        /*4 B_ccw*/ {A | DOWN, B_ccw, B_ccw | ERR, C_cw},
        /*5 D_ccw*/ {A, B_ccw | ERR, D_ccw, C_cw | DOWN},
        /*6 C_ccw*/ {C_ccw | ERR, C_ccw | ERR, C_ccw | ERR, C_ccw | ERR}, // should never be in this state...
    };

    template <typename counter_t>
    const uint8_t EncoderBase<counter_t>::stateMachineFull[7][4]{
        //              00        01         10        11
        /*0 A   */ {A, B_cw | UP, D_cw | DOWN, A | ERR},
        /*1 B_cw*/ {A | DOWN, B_cw, B_cw | ERR, C_cw | UP},
        /*2 D_cw*/ {A | UP, D_cw | ERR, D_cw, C_cw | DOWN},
        /*3 C_cw*/ {C_cw | ERR, B_cw | DOWN, D_cw | UP, C_cw},
    };
} // namespace EncoderTool
