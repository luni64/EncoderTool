#pragma once
#include "EncoderButton.h"
#include "HAL/directReadWrite.h"
#include "HAL/SimplyAtomic/SimplyAtomic.h"
#include "config.h"
#include <limits.h>

namespace EncoderTool
{
    enum class CountMode { // cnt per quad period | input at detents | remark
        quarter,           //          1          |       0/0        | standard for mech encoders
        quarterInv,        //          1          |       1/1        |
        half,              //          2          |   0/0 and 1/1    | seldom used
        halfAlt,           //          2          |   1/0 and 0/1    | seldom used
        full               //          4          |       n.a.       | standard for optical encoders w/o detents
    };

    class EncoderBase
    {
     public:
        void begin(uint_fast8_t phaseA, uint_fast8_t phaseB);

        EncoderBase &setCountMode(CountMode);
        EncoderBase &attachCallback(encCallback_t);
        EncoderBase &attachButtonCallback(encBtnCallback_t);
        EncoderBase &setLimits(int min, int max, bool periodic = false);

        void setValue(int val) { value = val; }

        int getValue() const
        {
            if (sizeof(__SIG_ATOMIC_TYPE__) == sizeof(int)) // compile time evaluation
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

        bool valueChanged()
        {
            bool ret   = valChanged;
            valChanged = false;
            return ret;
        }

        uint8_t getButton() { return button.read(); }
        bool buttonChanged()
        {
            bool ret   = btnChanged;
            btnChanged = false;
            return ret;
        }

        int update(uint_fast8_t phaseA, uint_fast8_t phaseB, uint_fast8_t btn = 0);

     protected:
        EncoderBase()   = default;
        int value       = 0;
        bool valChanged = false;

        EncoderButton button;
        bool btnChanged = false;

        int minVal = INT_MIN, maxVal = INT_MAX;
        bool periodic    = false;
        unsigned invert  = 0x00;
        uint8_t curState = 0;

        encCallback_t callback       = nullptr;
        encBtnCallback_t btnCallback = nullptr;

        static const uint8_t stateMachineQtr[7][4];
        static const uint8_t stateMachineHalf[7][4];
        static const uint8_t stateMachineFull[7][4];
        const uint8_t (*stateMachine)[7][4] = &stateMachineFull;

        EncoderBase &operator=(EncoderBase const &) = delete;
        EncoderBase(EncoderBase const &)            = delete;

        friend class EncPlexBase;

#if defined(USE_ERROR_CALLBACKS)
     protected:
        encCallback_t errCallback = nullptr;

     public:
        void attachErrorCallback(encCallback_t cb) { errCallback = cb; }
#endif
    };
}