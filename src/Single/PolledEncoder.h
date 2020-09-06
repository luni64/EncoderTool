#pragma once

#include "../EncoderBase.h"
#include "Bounce2.h"
#include "core_pins.h"

namespace EncoderTool
{
    // Simple encoder implementation which reads phase A and B from two digital pins
    class PolledEncoder : public EncoderBase
    {
     public:
        inline void begin(int pinA, int pinB, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        inline void begin(int pinA, int pinB, int pinBtn, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);

        inline void tick(); //call tick() as often as possible. For mechanical encoders a call frequency of > 5kHz should be sufficient

     protected:
        int pinA, pinB, pinBtn = UINT32_MAX;
    };

    // Inline implementation ===============================================

    void PolledEncoder::tick()
    {
        int A = digitalReadFast(pinA);
        int B = digitalReadFast(pinB);
        int btn = pinBtn < NUM_DIGITAL_PINS ? digitalReadFast(pinBtn) : LOW;

        update(A, B, btn);
    }

    void PolledEncoder::begin(int pinA, int pinB, int pinBtn, CountMode countMode, int inputMode)
    {
        this->pinBtn = pinBtn;
        begin(pinA, pinB, countMode, inputMode);
    }

    void PolledEncoder::begin(int pinA, int pinB, CountMode countMode, int inputMode)
    {
        this->pinA = pinA;
        this->pinB = pinB;
        for (uint8_t pin : {this->pinA, this->pinB, this->pinBtn})
        {
            pinMode(pin, inputMode);
        }

        setCountMode(countMode);
        EncoderBase::begin(digitalReadFast(pinA), digitalReadFast(pinB)); // set start state
    }
} // namespace EncoderTool