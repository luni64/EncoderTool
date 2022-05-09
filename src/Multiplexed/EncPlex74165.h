#pragma once

#include "../HAL/directReadWrite.h"
#include "../delay.h"
#include "Arduino.h"
#include "Bounce2.h"
#include "EncPlexBase.h"

namespace EncoderTool
{
    class EncPlex74165 : public EncPlexBase
    {
     public:
        inline EncPlex74165(unsigned nrOfEncoders, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned pinBtn = -1);
        inline ~EncPlex74165();

        inline void begin(CountMode mode = CountMode::quarter);
        inline void begin(allCallback_t callback, CountMode m = CountMode::quarter);
        inline void tick(); // call as often as possible

     protected:
        HAL::pinRegInfo_t A, B, Btn, LD, CLK;
    };

    // IMPLEMENTATION ============================================

    EncPlex74165::EncPlex74165(unsigned nrOfEncoders, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned pinBtn)
        : EncPlexBase(nrOfEncoders), A(pinA), B(pinB), Btn(pinBtn), LD(pinLD), CLK(pinCLK)
    {
    }

    EncPlex74165::~EncPlex74165()
    {
        pinMode(LD.pin, INPUT);
        pinMode(CLK.pin, INPUT);
    }

    void EncPlex74165::begin(allCallback_t cb, CountMode mode)
    {
        begin(mode);
        attachCallback(cb);
    }

    void EncPlex74165::begin(CountMode mode)
    {
        using HAL::directRead;
        using HAL::directWrite;
        // Serial.printf("%d %d %d %d %d\n", A.pin, B.pin, Btn.pin, LD.pin, CLK.pin);

        EncPlexBase::begin(mode);

        pinMode(A.pin, INPUT);
        pinMode(B.pin, INPUT);
        if (Btn.pin < NUM_DIGITAL_PINS) pinMode(Btn.pin, INPUT);
        pinMode(LD.pin, OUTPUT);
        pinMode(CLK.pin, OUTPUT);

        directWrite(LD, HIGH); // active low
        delayMicroseconds(1);

        // load current values to shift register
        directWrite(LD, LOW);
        delay50ns();
        delay50ns();
        delay50ns();
        directWrite(LD, HIGH);

        // first values are available directly after loading
        encoders[0].begin(directRead(A), directRead(B));

        for (unsigned i = 1; i < encoderCount; i++) // shift in the the rest of the encoders
        {
            directWrite(CLK, HIGH);
            delay50ns();
            encoders[i].begin(directRead(A), directRead(B));
            directWrite(CLK, LOW);
            delay50ns();
        }
    }

    void EncPlex74165::tick()
    {
        using HAL::directRead;
        using HAL::directWrite;

        // load current values to shift register
        directWrite(LD, LOW);
        delay50ns();
        delay50ns();
        delay50ns();
        directWrite(LD, HIGH);


        // first values are available directly after loading
        int a   = directRead(A);
        int b   = directRead(B);
        int btn = Btn.pin < NUM_DIGITAL_PINS ? directRead(Btn) : LOW;

        int delta = encoders[0].update(a, b, btn);

        if (delta != 0 && callback != nullptr)
        {
            callback(0, encoders[0].getValue(), delta);
        }
        for (unsigned i = 1; i < encoderCount; i++) // shift in the the rest of the encoders
        {
            directWrite(CLK, HIGH);
            delay50ns();
            int delta = encoders[i].update(directRead(A), directRead(B), Btn.pin < NUM_DIGITAL_PINS ? directRead(Btn) : LOW);
            if (delta != 0 && callback != nullptr)
            {
                callback(i, encoders[i].getValue(), delta);
            }
            directWrite(CLK, LOW);
            delay50ns();
        }
    }
} // namespace EncoderTool