#pragma once
#include "Arduino.h"
#include "EncPlexBase.h"
#include "HAL/directReadWrite.h"

namespace EncoderTool
{
    template <typename counter_t>
    class EncPlex4051_tpl : public EncPlexBase<counter_t>
    {
     public:
        inline EncPlex4051_tpl(unsigned encoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinA, unsigned pinB);

        inline void tick(); // call as often as possible
        inline void begin(CountMode mode = CountMode::quarter);

     protected:
        const HAL::pinRegInfo_t S0, S1, S2, A, B;
    };

    // IMPLEMENTATION =====================================================================================================

    template <typename counter_t>
    EncPlex4051_tpl<counter_t>::EncPlex4051_tpl(unsigned encoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinA, unsigned pinB)
        : EncPlexBase<counter_t>(encoderCount),
          S0(pinS0), S1(pinS1), S2(pinS2),
          A(pinA), B(pinB)
    {
    }

    template <typename counter_t>
    void EncPlex4051_tpl<counter_t>::begin(CountMode mode)
    {
        EncPlexBase<counter_t>::begin(mode);
        pinMode(S0.pin, OUTPUT);
        pinMode(S1.pin, OUTPUT);
        pinMode(S2.pin, OUTPUT);
        pinMode(A.pin, INPUT);
        pinMode(B.pin, INPUT);
    }

    template <typename counter_t>
    void EncPlex4051_tpl<counter_t>::tick()
    {
        using HAL::directRead;
        using HAL::directWrite;

        for (unsigned i = 0; i < EncPlexBase<counter_t>::encoderCount; i++)
        {
            directWrite(S0, i & 0b0001);
            directWrite(S1, i & 0b0010);
            directWrite(S2, i & 0b0100);
            delayMicroseconds(1);

            int delta = EncPlexBase<counter_t>::encoders[i].update(directRead(A), directRead(B));
            if (delta != 0 && EncPlexBase<counter_t>::callback != nullptr)
            {
                EncPlexBase<counter_t>::callback(i, EncPlexBase<counter_t>::encoders[i].getValue(), delta);
            }
        }
    }

    using EncPlex4051 = EncPlex4051_tpl<int>;

} // namespace EncoderTool
