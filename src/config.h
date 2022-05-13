#pragma once

// un-comment the following line if you prefer plain function pointers for callbacks
#define PLAIN_ENC_CALLBACK

//================================================================================================================

#include <stdint.h>

#if not defined(PLAIN_ENC_CALLBACK)
  #include <functional>
#endif

namespace EncoderTool
{
#if defined(PLAIN_ENC_CALLBACK)
    using encCallback_t = void (*)(int value, int delta);
    using encBtnCallback_t = void (*)(int state);

    using allCallback_t = void (*)(uint8_t channel, int value, int delta);
   // using allBtnCallback_t = void (*)(int32_t state);
#else
    using encCallback_t = std::function<void(int32_t value, int32_t delta)>; // encoder value
    using encBtnCallback_t = std::function<void(int32_t state)>;             // encoder button

    using allCallback_t = std::function<void(uint32_t channel, int32_t value, int32_t delta)>; // all encoder values
    using allBtnCallback_t = std::function<void(uint32_t channel, int32_t state)>;             // all encoder buttons
#endif
}