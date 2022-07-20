#pragma once

#include "../EncoderBase.h"
//#include "../HAL/iPin_t.h"
#include "../HAL/directReadWrite.h"
#include "../HAL/pinInterruptHelper.h"

namespace EncoderTool
{
    /***********************************************************************
     *  Simple interupt based encoder implementation which reads
     *  phase A and B from two interupt capable pins
     ************************************************************************/
    class Encoder : public EncoderBase
    {
     public:
        inline Encoder();
        inline ~Encoder();

        inline bool begin(int pinA, int pinB, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        inline bool begin(int pinA, int pinB, encCallback_t cb, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);

        void doUpdate() { update(HAL::directRead(A), HAL::directRead(B)); }

     protected:
        HAL::pinRegInfo_t A, B;

        using iHelper = HAL::PinInterruptHelper<Encoder, &Encoder::doUpdate>;
    };

    // Inline implementation ===============================================

    Encoder::Encoder()
    {
        // Pin::setCallbackMember(&Encoder::doUpdate);
    }

    bool Encoder::begin(int pinA, int pinB, encCallback_t cb, CountMode countMode, int inputMode)
    {
        bool ret = begin(pinA, pinB, countMode, inputMode);
        attachCallback(cb);
        return ret;
    }

    bool Encoder::begin(int pinA, int pinB, CountMode countMode, int inputMode)
    {
        using namespace HAL;

        if (!iHelper::hasInterrupt(pinA) || !iHelper::hasInterrupt(pinB))
            return false;

        A = pinRegInfo_t(pinA);
        B = pinRegInfo_t(pinB);

        pinMode(A.pin, inputMode);
        pinMode(B.pin, inputMode);

        setCountMode(countMode);
        EncoderBase::begin(directRead(A), directRead(B)); // set start state

        iHelper::attachInterrupt(A.pin, this, CHANGE);
        iHelper::attachInterrupt(B.pin, this, CHANGE);
        return true;
    }

    Encoder::~Encoder()
    {
        iHelper::detachInterrupt(A.pin);
        iHelper::detachInterrupt(B.pin);
    }
} // namespace EncoderTool