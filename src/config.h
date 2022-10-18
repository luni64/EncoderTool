#pragma once

// un-comment the following line if you prefer plain function pointers for callbacks
#define PLAIN_ENC_CALLBACK

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

#if not defined(PLAIN_ENC_CALLBACK)
#    include <functional>
#endif
