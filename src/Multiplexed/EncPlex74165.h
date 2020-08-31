#pragma once

#include "../EncPlexBase.h"
#include "../delay.h"
#include "core_pins.h"
#include <initializer_list>

namespace EncoderTool
{
    class EncPlex74165 : public EncPlexBase
    {
    public:
        inline EncPlex74165(unsigned nrOfEncoders, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB);
        inline ~EncPlex74165();

        inline void begin(CountMode mode = CountMode::quarter);                      // optional, call in setup if other code grabed the pins after construction
        inline void begin(allCallback_t callback, CountMode m = CountMode::quarter); // optional, call in setup if other code grabed the pins after construction
        inline void tick();                                                          // call as often as possible

    protected:
        const unsigned A, B, LD, CLK;
    };

    // IMPLEMENTATION ============================================

    EncPlex74165::EncPlex74165(unsigned nrOfEncoders, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB)
        : EncPlexBase(nrOfEncoders), A(pinA), B(pinB), LD(pinLD), CLK(pinCLK)
    {
        // begin(); // usually calling begin from the constructor works... if not you can always call it in setup()
    }

    EncPlex74165::~EncPlex74165()
    {
        pinMode(A, INPUT_DISABLE);
        pinMode(B, INPUT_DISABLE);
        pinMode(LD, INPUT_DISABLE);
        pinMode(CLK, INPUT_DISABLE);
    }

    void EncPlex74165::begin(allCallback_t cb, CountMode mode)
    {
        begin(mode);
        attachCallback(cb);
    }

    void EncPlex74165::begin(CountMode mode)
    {
        EncPlexBase::begin(mode);
        pinMode(A, INPUT);
        pinMode(B, INPUT);
        pinMode(LD, OUTPUT);
        pinMode(CLK, OUTPUT);

        digitalWriteFast(LD, HIGH); // active low
        delayMicroseconds(1);

        // load current values to shift register
        digitalWriteFast(LD, LOW);
        delay50ns();
        delay50ns();
        delay50ns();
        digitalWriteFast(LD, HIGH);

        // first values are available directly after loading
        encoders[0].begin(digitalReadFast(A), digitalReadFast(B));

        for (unsigned i = 1; i < encoderCount; i++) // shift in the the rest of the encoders
        {
            digitalWriteFast(CLK, HIGH);
            delay50ns();
            encoders[i].begin(digitalReadFast(A), digitalReadFast(B));
            digitalWriteFast(CLK, LOW);
            delay50ns();
        }
    }

    void EncPlex74165::tick()
    {
        // load current values to shift register
        digitalWriteFast(LD, LOW);
        delay50ns();
        delay50ns();
        delay50ns();
        digitalWriteFast(LD, HIGH);

        // first values are available directly after loading
        int delta = encoders[0].update(digitalReadFast(A), digitalReadFast(B));
        if (delta != 0 && callback != nullptr)
        {
            callback(0, encoders[0].getValue(), delta);
        }
        for (unsigned i = 1; i < encoderCount; i++) // shift in the the rest of the encoders
        {
            digitalWriteFast(CLK, HIGH);
            delay50ns();
            delta = encoders[i].update(digitalReadFast(A), digitalReadFast(B));
            if (delta != 0 && callback != nullptr)
            {
                callback(i, encoders[i].getValue(), delta);
            }
            digitalWriteFast(CLK, LOW);
            delay50ns();
        }
    }

} // namespace EncoderTool