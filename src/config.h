#pragma once

// un-comment the following line if you prefer plain function pointers for callbacks
#define PLAIN_ENC_CALLBACK

//================================================================================================================

#include <stdint.h>

#if not defined(PLAIN_ENC_CALLBACK)
  #include <functional>
#endif

