#pragma once

#include "config.h"
#include "EncoderBase.h"

namespace EncoderTool
{
    class EncPlexBase
    {
     public:
        void attachCallback(allCallback_t callback);
        EncoderBase& operator[](std::size_t idx);

     protected:
        EncPlexBase(unsigned EncoderCount);
        ~EncPlexBase();

        void begin(CountMode mode = CountMode::quarter);
        void begin(allCallback_t, CountMode mode = CountMode::quarter);

        const uint32_t encoderCount;
        EncoderBase* encoders;

        allCallback_t callback = nullptr;
    };
}
