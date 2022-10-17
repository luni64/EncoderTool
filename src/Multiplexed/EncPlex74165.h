#pragma once

#include "../HAL/directReadWrite.h"
#include "../delay.h"
#include "Arduino.h"
#include "Bounce2.h"
#include "EncPlexBase.h"

namespace EncoderTool
{
    template <typename counter_t>
    class EncPlex74165_tpl : public EncPlexBase<counter_t>
    {
     public:
        inline EncPlex74165_tpl(unsigned nrOfEncoders, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned pinBtn = -1);
        inline ~EncPlex74165_tpl();

        inline void begin(CountMode mode = CountMode::quarter);
        inline void tick(); // call as often as possible

     protected:
        HAL::pinRegInfo_t A, B, Btn, LD, CLK;
    };
    

    // IMPLEMENTATION ============================================

    template <typename counter_t>
    EncPlex74165_tpl<counter_t>::EncPlex74165_tpl(unsigned nrOfEncoders, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned pinBtn)
        : EncPlexBase<counter_t>(nrOfEncoders), A(pinA), B(pinB), Btn(pinBtn), LD(pinLD), CLK(pinCLK)
    {
    }

    template <typename counter_t>
    EncPlex74165_tpl<counter_t>::~EncPlex74165_tpl()
    {
        pinMode(LD.pin, INPUT);
        pinMode(CLK.pin, INPUT);
    }

    template <typename counter_t>
    void EncPlex74165_tpl<counter_t>::begin(CountMode mode)
    {
        using HAL::directRead;
        using HAL::directWrite;

        EncPlexBase<counter_t>::begin(mode);

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
        EncPlexBase<counter_t>::encoders[0].begin(directRead(A), directRead(B));

        for (unsigned i = 1; i < EncPlexBase<counter_t>::encoderCount; i++) // shift in the the rest of the encoders
        {
            directWrite(CLK, HIGH);
            delay50ns();
            EncPlexBase<counter_t>::encoders[i].begin(directRead(A), directRead(B));
            directWrite(CLK, LOW);
            delay50ns();
        }
    }

    template <typename counter_t>
    void EncPlex74165_tpl<counter_t>::tick()
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
        int a = directRead(A);
        int b = directRead(B);
        int btn = Btn.pin < NUM_DIGITAL_PINS ? directRead(Btn) : LOW;

        int delta = EncPlexBase<counter_t>::encoders[0].update(a, b, btn);

        if (delta != 0 && EncPlexBase<counter_t>::callback != nullptr)
        {
            EncPlexBase<counter_t>::callback(0, EncPlexBase<counter_t>::encoders[0].getValue(), delta);
        }
        for (unsigned i = 1; i < EncPlexBase<counter_t>::encoderCount; i++) // shift in the the rest of the encoders
        {
            directWrite(CLK, HIGH);
            delay50ns();
            int delta = EncPlexBase<counter_t>::encoders[i].update(directRead(A), directRead(B), Btn.pin < NUM_DIGITAL_PINS ? directRead(Btn) : LOW);
            if (delta != 0 && EncPlexBase<counter_t>::callback != nullptr)
            {
                EncPlexBase<counter_t>::callback(i, EncPlexBase<counter_t>::encoders[i].getValue(), delta);
            }
            directWrite(CLK, LOW);
            delay50ns();
        }
    }

    using EncPlex74165 = EncPlex74165_tpl<int>;
} // namespace EncoderTool