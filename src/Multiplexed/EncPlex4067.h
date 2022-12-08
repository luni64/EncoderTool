#pragma once

#include "../HAL/directReadWrite.h"
#include "EncPlexBase.h"

namespace EncoderTool
{
    template <typename counter_t>
    class EncPlex4067_tpl : public EncPlexBase<counter_t>
    {
     public:
        inline EncPlex4067_tpl(unsigned EncoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinS3, unsigned pinA, unsigned pinB);

        inline void tick(); // call as often as possible
        inline void begin(CountMode mode = CountMode::quarter);

     protected:
        const HAL::pinRegInfo_t S0, S1, S2, S3, A, B;
    };

    // IMPLEMENTATION =====================================================================================================

    template <typename counter_t>
    EncPlex4067_tpl<counter_t>::EncPlex4067_tpl(unsigned EncoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinS3, unsigned pinA, unsigned pinB)
        : EncPlexBase<counter_t>(EncoderCount),
          S0(pinS0), S1(pinS1), S2(pinS2), S3(pinS3),
          A(pinA), B(pinB)
    {
    }

    template <typename counter_t>
    void EncPlex4067_tpl<counter_t>::begin(CountMode mode)
    {
        EncPlexBase<counter_t>::begin(mode);
        pinMode(S0.pin, OUTPUT);
        pinMode(S1.pin, OUTPUT);
        pinMode(S2.pin, OUTPUT);
        pinMode(S3.pin, OUTPUT);

        pinMode(A.pin, INPUT);
        pinMode(B.pin, INPUT);
    }

    template <typename counter_t>
    void EncPlex4067_tpl<counter_t>::tick()
    {
        using HAL::directRead;
        using HAL::directWrite;

        for (unsigned i = 0; i < EncPlexBase<counter_t>::encoderCount; i++)
        {
            directWrite(S0, i & 0b0001);
            directWrite(S1, i & 0b0010);
            directWrite(S2, i & 0b0100);
            directWrite(S3, i & 0b1000);
            delayMicroseconds(1);

            int delta = EncPlexBase<counter_t>::encoders[i].update(directRead(A), directRead(B));
            if (delta != 0 && EncPlexBase<counter_t>::callback != nullptr)
            {
                EncPlexBase<counter_t>::callback(i, EncPlexBase<counter_t>::encoders[i].getValue(), delta);
            }
        }
    }

    using EncPlex4067 = EncPlex4067_tpl<int>;

} // namespace EncoderTool