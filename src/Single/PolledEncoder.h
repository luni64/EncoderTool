#pragma once

#include "../EncoderBase.h"
#include "../HAL/directReadWrite.h"
#include "Arduino.h"
#include "Bounce2.h"

namespace EncoderTool
{
    // Simple encoder implementation which reads phase A and B from two digital pins
    class PolledEncoder : public EncoderBase
    {
     public:
        inline void begin(int pinA, int pinB, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);
        inline void begin(int pinA, int pinB, int pinBtn, CountMode = CountMode::quarter, int inputMode = INPUT_PULLUP);

        inline void tick(); // call tick() as often as possible. For mechanical encoders a call frequency of > 5kHz should be sufficient

     protected:
        bool hasButton = false;
        HAL::pinRegInfo_t piA, piB, piBtn;
    };

    // Inline implementation ===============================================

    void PolledEncoder::tick()
    {
        using namespace HAL;

        int A   = directRead(piA);
        int B   = directRead(piB);
        int btn = hasButton ? directRead(piBtn) : LOW;

        update(A, B, btn);
    }

    void PolledEncoder::begin(int _pinA, int _pinB, int pinBtn, CountMode countMode, int inputMode)
    {
        hasButton = true;
        pinMode(pinBtn, inputMode);
        piBtn = HAL::getPinRegInfo(pinBtn);
        begin(_pinA, _pinB, countMode, inputMode);
    }

    void PolledEncoder::begin(int pinA, int pinB, CountMode countMode, int inputMode)
    {
        using namespace HAL;

        pinMode(pinA, inputMode);
        pinMode(pinB, inputMode);

        piA = HAL::getPinRegInfo(pinA); // store pin infos for fast I/O
        piB = HAL::getPinRegInfo(pinB);

        // char buf[100];
        // snprintf(buf, 100, "a:%d b:%d\n", piA.pin, piB.pin);
        // Serial.print(buf);

        setCountMode(countMode);
        EncoderBase::begin(directRead(piA), directRead(piB)); // set start state
    }
} // namespace EncoderTool