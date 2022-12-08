#pragma once

#include "Arduino.h"

#if !defined(CORE_NUM_INTERRUPT)

    #if __has_include("wiring_private.h")
        #include "wiring_private.h"
    #endif
    #if defined(EXTERNAL_NUM_INTERRUPTS)
        #define CORE_NUM_INTERRUPT EXTERNAL_NUM_INTERRUPTS
    #elif defined(NUM_INTERRUPT)
        #define CORE_NUM_INTERRUPT NUM_INTERRUPT
    #elif defined(NUM_DIGITAL_PINS)
        #define CORE_NUM_INTERRUPT NUM_DIGITAL_PINS
    #endif

#endif

#if !defined(CORE_NUM_INTERRUPT)
//#define CORE_NUM_INTERRUPT 2
// static_assert(false, "No information about external interrupts found for this board! Please consider using PolledEncoder instead")
#endif