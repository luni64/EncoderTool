#pragma once

//#include <cstddef>
#include <initializer_list>

class Channel
{
 public:
    inline void setPin(uint8_t pin);
    inline void enable(bool on);
    inline void setFrequency(int f); // Hz
    inline void setDutyCycle(int d); // 0 - 100

    uint8_t getPin() const { return pin; }
    int getFrequency() const { return frequency; }
    int getDutyCycle() const { return dutyCycle; }

 protected:
    uint8_t pin = UINT8_MAX;
    unsigned dutyCycle = 128;
    unsigned frequency = 50;
};

void Channel::setPin(uint8_t p)
{
    pin = p;
    analogWrite(pin, 0); // switch off
    frequency = 0;
    dutyCycle = 50;
}

void Channel::enable(bool on)
{
    if (on)
        setDutyCycle(dutyCycle); // set last stored duty cycle
    else
        analogWrite(pin, 0); // switch off output
}

void Channel::setFrequency(int f)
{
    frequency = max(0, f);
    analogWriteFrequency(pin, frequency);
}

void Channel::setDutyCycle(int d) // percent
{
    dutyCycle = min(99, max(0, d)); // limit to [0, 100[
    analogWrite(pin, dutyCycle * 2.56f);
}
