#pragma once

// comment the following line if you prefer plain vanilla function pointers for callbacks
#define WANT_MODERN_CALLBACKS

//================================================================================================================

#if defined(__AVR__)
   #include "HAL/avr_c++/limits"
   #include "HAL/avr_c++/type_traits"

   using std::tr1::is_integral;
   using std::tr1::is_signed;
#else
   #include <limits>
   #include <type_traits>

   using std::is_integral;
   using std::is_signed;
#endif

// we can not use staticFunctional with too old compilers
#if defined(WANT_MODERN_CALLBACKS)
    #if (__GNUC__ < 7)
        #warning "can't use staticFunctional with GCC < V7! Fallback to function pointer callbacks"
    #else
        #define USE_MODERN_CALLBACKS
        #include "staticFunctional.h"
    #endif
#endif


namespace EncoderTool
{
#if defined(USE_MODERN_CALLBACKS)
    using staticFunctional::function;
    using encCallback_t    = function<void(int value, int delta)>;                  // encoder value
    using encBtnCallback_t = function<void(int state)>;                             // encoder button
    using allCallback_t    = function<void(uint8_t channel, int value, int delta)>; // all encoder values

    // using allBtnCallback_t = function<void(uint32_t channel, int32_t state)>;       // all encoder buttons
#else
    using encCallback_t    = void (*)(int value, int delta);
    using encBtnCallback_t = void (*)(int state);
    using allCallback_t    = void (*)(uint8_t channel, int value, int delta);
    // using allBtnCallback_t = void (*)(int32_t state);
#endif
}

#undef WANT_MODERN_CALLBACKS
#undef USE_MODERN_CALLBACKS