#pragma once

#include "../EncoderBase.h"
#include "core_pins.h"

namespace EncoderTool
{
    // Simple encoder implementation which reads phase A and B from two digital pins
    class PolledEncoder : public EncoderBase
    {
     public:
        inline void begin(int pinA, int pinB, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        inline void begin(int pinA, int pinB, encCallback_t cb, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        inline void tick(); //call tick() as often as possible. For mechanical encoders a call frequency of > 5kHz should be sufficient

     protected:
        int pinA, pinB;
    };

    // Inline implementation ===============================================

    void PolledEncoder::tick()
    {
        update(digitalReadFast(pinA), digitalReadFast(pinB));
    }

    void PolledEncoder::begin(int pinA, int pinB, encCallback_t cb, CountMode countMode, int inputMode)
    {
        begin(pinA, pinB, countMode, inputMode);
        attachCallback(cb);
    }

    void PolledEncoder::begin(int pinA, int pinB, CountMode countMode, int inputMode)
    {
        this->pinA = pinA;
        pinMode(pinA, inputMode);

        this->pinB = pinB;
        pinMode(pinB, inputMode);

        setCountMode(countMode);
        EncoderBase::begin(digitalReadFast(pinA), digitalReadFast(pinB)); // set start state
    }
} // namespace EncoderTool