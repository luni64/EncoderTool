#pragma once


// un-comment the following line if you prefer plain function pointers for callbacks
//#define PLAIN_ENC_CALLBACK

// un-comment the following line if you need callbacks for code errors
//#define USE_ERROR_CALLBACKS


//================================================================================================================

#include <cstdint>

#if not defined(PLAIN_ENC_CALLBACK)
    #include <functional>
   // inline void std::__throw_bad_function_call(){while (1) {}}  // do whatever you want to do instead of an exception
#endif

namespace EncoderTool
{
    #if defined(PLAIN_ENC_CALLBACK)
        using encCallback_t = void (*)(int32_t value);
        using allCallback_t = void (*)(uint32_t nr, int32_t value);
    #else
        using encCallback_t = std::function<void(int32_t value, int32_t delta)>;   // encoder value
        using encBtnCallback_t = std::function<void(int32_t state)>;               // encoder button

        using allCallback_t = std::function<void(uint32_t channel, int32_t value, int32_t delta)>;  // all encoder values
        using allBtnCallback_t = std::function<void(uint32_t channel, int32_t state)>;              // all encoder buttons
    #endif
}