#pragma once

#include "../EncoderBase.h"
//#include "../HAL/iPin_t.h"
#include "../HAL/directReadWrite.h"
#include "../HAL/pinInterruptHelper.h"

namespace EncoderTool
{
    /***********************************************************************
     *  Simple interrupt based encoder implementation which reads
     *  phase A and B from two interrupt capable pins
     ************************************************************************/
    template <typename counter_t>
    class Encoder_tpl : public EncoderBase<counter_t>
    {
     public:
        inline Encoder_tpl();
        inline ~Encoder_tpl();

        inline bool begin(int pinA, int pinB, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        inline bool begin(int pinA, int pinB, encCallback_t cb, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);

        void doUpdate() {EncoderBase<counter_t>::update(HAL::directRead(A), HAL::directRead(B)); }

     protected:
        HAL::pinRegInfo_t A, B;

        using iHelper = HAL::PinInterruptHelper<Encoder_tpl, &Encoder_tpl::doUpdate>;
    };

    // Inline implementation ===============================================

    template <typename counter_t>
    Encoder_tpl<counter_t>::Encoder_tpl()
    {
        // Pin::setCallbackMember(&Encoder_tpl::doUpdate);
    }

    template <typename counter_t>
    bool Encoder_tpl<counter_t>::begin(int pinA, int pinB, encCallback_t cb, CountMode countMode, int inputMode)
    {
        bool ret = begin(pinA, pinB, countMode, inputMode);
        EncoderBase<counter_t>::attachCallback(cb);
        return ret;
    }

    template <typename counter_t>
    bool Encoder_tpl<counter_t>::begin(int pinA, int pinB, CountMode countMode, int inputMode)
    {
        using namespace HAL;

        if (!iHelper::hasInterrupt(pinA) || !iHelper::hasInterrupt(pinB))
            return false;

        A = pinRegInfo_t(pinA);
        B = pinRegInfo_t(pinB);

        pinMode(A.pin, inputMode);
        pinMode(B.pin, inputMode);

        EncoderBase<counter_t>::setCountMode(countMode);
        EncoderBase<counter_t>::begin(directRead(A), directRead(B)); // set start state

        iHelper::attachInterrupt(A.pin, this, CHANGE);
        iHelper::attachInterrupt(B.pin, this, CHANGE);
        return true;
    }

    template <typename counter_t>
    Encoder_tpl<counter_t>::~Encoder_tpl()
    {
        iHelper::detachInterrupt(A.pin);
        iHelper::detachInterrupt(B.pin);
    }

    using Encoder = Encoder_tpl<int>;
} // namespace EncoderTool