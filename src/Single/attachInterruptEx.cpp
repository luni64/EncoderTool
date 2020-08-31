#include "attachInterruptEx.h"
#include "core_pins.h"

// This is a lame workaround for the problem that the Arduino attachInterrupt function does not allow passing any status to the callbacks.
// attachInterruptEx allows to attach a std::function<void(void)> callback to the pin interrupts
//
// How does it work:
// We generate an array of std::function<void(void)> to store the callbacks and an array of pointers to void functions as relays.
// Since the relay functions are of type void(*f)() they can be used in the standard attachInterrupt function. The relays simply call the std::function callbacks stored in the 'cb' array.
// Using lambdas to fill the array saves the hassle of explicitely declaring each of those functions.


namespace // private namespace, avoid pollution
{
    std::function<void(void)> cb[CORE_NUM_INTERRUPT];

    void (* const relays[CORE_NUM_INTERRUPT])(void)  // array of pointers to void(*relay)(void) functions (defined as lambda expressions)
    {
        [] { cb[0](); },  [] { cb[1](); },  [] { cb[2](); },  [] { cb[3](); },  [] { cb[4](); },
        [] { cb[5](); },  [] { cb[6](); },  [] { cb[7](); },  [] { cb[8](); },  [] { cb[9](); },
        [] { cb[10](); }, [] { cb[11](); }, [] { cb[12](); }, [] { cb[13](); }, [] { cb[14](); },
        [] { cb[15](); }, [] { cb[16](); }, [] { cb[17](); }, [] { cb[18](); }, [] { cb[19](); },
        [] { cb[20](); }, [] { cb[21](); }, [] { cb[22](); }, [] { cb[23](); }, [] { cb[24](); },
        [] { cb[25](); }, [] { cb[26](); }, [] { cb[27](); }, [] { cb[28](); }, [] { cb[29](); },
        [] { cb[30](); }, [] { cb[31](); }, [] { cb[32](); }, [] { cb[33](); },
#if defined(ARDUINO_TEENSY31) || defined(ARDUINO_TEENSY32)
    };
#else
        [] { cb[34](); }, [] { cb[35](); }, [] { cb[36](); }, [] { cb[37](); }, [] { cb[38](); }, [] { cb[39](); },
#if defined(ARDUINO_TEENSY40)
    };
#else
        [] { cb[40](); }, [] { cb[41](); }, [] { cb[42](); }, [] { cb[43](); }, [] { cb[44](); },
        [] { cb[45](); }, [] { cb[46](); }, [] { cb[47](); }, [] { cb[48](); }, [] { cb[49](); },
        [] { cb[50](); }, [] { cb[51](); }, [] { cb[52](); }, [] { cb[53](); }, [] { cb[54](); },
#if defined(ARDUINO_TEENSY41)
    };
#else
        [] { cb[55](); }, [] { cb[56](); }, [] { cb[57](); }, [] { cb[58](); }, [] { cb[59](); },
        [] { cb[60](); }, [] { cb[61](); }, [] { cb[62](); }, [] { cb[63](); },
    };
#endif
#endif
#endif
}; // namespace


void attachInterruptEx(unsigned pin, std::function<void(void)> callback, int mode)
{
    cb[pin] = callback;
    attachInterrupt(pin, relays[pin], mode);
}
