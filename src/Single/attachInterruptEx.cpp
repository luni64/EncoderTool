#include "attachInterruptEx.h"
#include "core_pins.h"

using namespace std;

namespace
{
    // We need to attach a memberfunction of the encoder class to a pin interrupt. Since attachInterrupt only accepts  state less void(*)(void) callbacks
    // this is not possible directly.
    // Instead,we generate an array of void(*)() relay functions to attach to the pin interrupts. Those relays will invoke the actual callbacks.
    // see https://stackoverflow.com/q/63730007/1842762

    function<void()> callbacks[NUM_DIGITAL_PINS];

    template <unsigned nr>
    constexpr void relay()
    {
        callbacks[nr]();
    }

    template <unsigned... nr>
    constexpr array<void (*)(), NUM_DIGITAL_PINS> MakeRelays(index_sequence<nr...>)
    {
        return array<void (*)(), NUM_DIGITAL_PINS>{relay<nr>...};
    }

    constexpr auto relays = MakeRelays(make_index_sequence<NUM_DIGITAL_PINS>{});
}

void attachInterruptEx(unsigned pin, function<void(void)> callback, int mode)
{
    callbacks[pin] = callback;
    attachInterrupt(pin, relays[pin], mode);
}
