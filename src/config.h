#pragma once

// comment the following line out if you prefer plain vanilla function pointers for callbacks
#define WANT_MODERN_CALLBACKS

//================================================================================================================

#if defined(__AVR__)
    #include "HAL/avr_c++/limits"
    #include "HAL/avr_c++/type_traits"

    using std::tr1::is_integral;
    using std::tr1::is_signed;
    #if defined(WANT_MODERN_CALLBACKS)
        #warning "can't use modern callbacks for AVR processors! falling back to function pointer callbacks"
    #endif

#else
    #include <limits>
    #include <type_traits>
    using std::is_integral;
    using std::is_signed;

    #if defined(WANT_MODERN_CALLBACKS)
        #define USE_MODERN_CALLBACKS
        #include "inplace_function.h"
    #endif
#endif

#undef WANT_MODERN_CALLBACKS
