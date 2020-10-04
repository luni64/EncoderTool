#pragma once

namespace EncoderTool
{
    class Encoder;

    using state_t = Encoder*;             // we directly use an Encoder* as state variable to avoid casts from void* to Encoder* in the ISR
    using cb_t = void (*)(state_t state); // callback type

    void attachInterruptEx(unsigned pin, cb_t callback, state_t state, int mode);
}