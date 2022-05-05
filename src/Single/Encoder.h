#pragma once

#include "../EncoderBase.h"
#include "../HAL/iPin_t.h"
#include "../HAL/directReadWrite.h"

namespace EncoderTool
{
    /***********************************************************************
     *  Simple interupt based encoder implementation which reads
     *  phase A and B from two interupt capable pins
     ************************************************************************/
    class Encoder : public EncoderBase
    {
     public:
        Encoder();
        inline ~Encoder();

        inline bool begin(int pinA, int pinB, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        inline bool begin(int pinA, int pinB, encCallback_t cb, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);

        void doUpdate() { update(HAL::directRead(A), HAL::directRead(B)); }

     protected:
        HAL::pinRegInfo_t A, B;
        // using Pin = iPin_t<Encoder>;
    };

    // Inline implementation ===============================================

    Encoder::Encoder()
    {
        //Pin::setCallbackMember(&Encoder::doUpdate);
    }

    bool Encoder::begin(int pinA, int pinB, encCallback_t cb, CountMode countMode, int inputMode)
    {
        bool ret = begin(pinA, pinB, countMode, inputMode);
        attachCallback(cb);
        return ret;
    }

    bool Encoder::begin(int pinA, int pinB, CountMode countMode, int inputMode)
    {
        A = HAL::pinRegInfo_t(pinA);
        B = HAL::pinRegInfo_t(pinB);


        // if (!A.hasInterrupt() || !B.hasInterrupt()) return false;

        pinMode(A.pin,inputMode);
        pinMode(B.pin, inputMode);
        // B.pinMode(inputMode);
        // A.attachInterrupt(this, CHANGE);
        // B.attachInterrupt(this, CHANGE);

        setCountMode(countMode);
        EncoderBase::begin(HAL::directRead(A), HAL::directRead(B)); // set start state

        return true;
    }

    Encoder::~Encoder()
    {
        // A.detachInterrupt();
        // B.detachInterrupt();
    }
} // namespace EncoderTool