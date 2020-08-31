#pragma once

#include "EncPlexBase.h"
#include "core_pins.h"

namespace EncoderTool
{
   class EncPlex4067 : public EncPlexBase
   {
   public:
      inline EncPlex4067(unsigned EncoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinS3, unsigned pinA, unsigned pinB);

      inline void tick();                // call as often as possible
      inline void begin(CountMode mode); // optional, call in setup if other code grabed the pins after construction

   protected:
      const unsigned S0, S1, S2, S3, A, B;
   };

   // IMPLEMENTATION =====================================================================================================

   EncPlex4067::EncPlex4067(unsigned encoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinS3, unsigned pinA, unsigned pinB)
       : EncPlexBase(encoderCount),
         S0(pinS0), S1(pinS1), S2(pinS2), S3(pinS3),
         A(pinA), B(pinB)
   {
   }

   void EncPlex4067::begin(CountMode mode = CountMode::quarter)
   {
      EncPlexBase::begin(mode);
      pinMode(S0, OUTPUT);
      pinMode(S1, OUTPUT);
      pinMode(S2, OUTPUT);
      pinMode(S3, OUTPUT);

      pinMode(A, INPUT);
      pinMode(B, INPUT);
   }

   void EncPlex4067::tick()
   {
      for (unsigned i = 0; i < encoderCount; i++)
      {
         digitalWriteFast(S0, i & 0b0001);
         digitalWriteFast(S1, i & 0b0010);
         digitalWriteFast(S2, i & 0b0100);
         digitalWriteFast(S3, i & 0b1000);
         delayMicroseconds(1);

         int delta = encoders[i].update(digitalReadFast(A), digitalReadFast(B));
         if (delta != 0 && callback != nullptr)
         {
            callback(i, encoders[i].getValue(), delta);
         }
      }
   }

} // namespace EncoderTool