#pragma once

#include "Arduino.h"

#if __has_include("wiring_private.h")
#include "wiring_private.h"
#endif

#if defined(EXTERNAL_NUM_INTERRUPTS)
#define CORE_NUM_INTERRUPT EXTERNAL_NUM_INTERRUPTS
#endif

#if !defined(CORE_NUM_INTERRUPT)

    #if defined(ARDUINO_SAMD_ZERO)
    #define CORE_NUM_INTERRUPT 16

    #elif defined(xxxx)
    //...


    #else
    #error No interrupt capable pins found
    #endif
#endif


