#pragma once

#include "Arduino.h"

#if !defined(CORE_NUM_INTERRUPT)

    #if __has_include("wiring_private.h")
        #include "wiring_private.h"
    #endif

    #define CORE_NUM_INTERRUPT EXTERNAL_NUM_INTERRUPTS

#endif

#if !defined(CORE_NUM_INTERRUPT)
static_assert(false, "No information about external interrupts found for this board! Please consider using PolledEncoder instead")
#endif