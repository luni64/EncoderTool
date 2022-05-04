#pragma once

#include "../EncoderBase.h"
#include "Bounce2.h"
#include "Arduino.h"
#include "../HAL/directReadWrite.h"

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
        bool hasButton = false;
        HAL::pinRegInfo_t piA, piB, piBtn;
    };

    // Inline implementation ===============================================

    void PolledEncoder::tick()
    {
        int A =  HAL::drFast(piA);
        int B = HAL::drFast(piB);
        int btn = hasButton ? HAL::drFast(piBtn) : LOW;

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
        pinMode(pinA, inputMode);
        pinMode(pinB, inputMode);

        piA = HAL::getPinRegInfo(pinA); // store pin infos for fast I/O
        piB = HAL::getPinRegInfo(pinB);

        setCountMode(countMode);
        EncoderBase::begin(HAL::drFast(piA), HAL::drFast(piB)); // set start state
    }
} // namespace EncoderTool