#pragma once
#pragma once

#include "Channel.h"

class FreqGen_t
{
  public:
    static constexpr unsigned nrOfChannels = 8;

    void addOutputPins(std::initializer_list<int> pins)
    {
      for (auto pin : pins) {
        addChannels(pin);
      }
    }

    void addChannels(int pin)
    {
      if (usedChannels >= nrOfChannels || pin > CORE_NUM_DIGITAL) panic();

      channel[usedChannels].setPin(pin);
      usedChannels++;
    }

    int getNrOfChannels() {
      return usedChannels;
    }

    void setFrequency(unsigned ch, int f)
    {
      if (ch >= usedChannels) panic();

      channel[ch].setFrequency(f);
      channel[ch].enable(true);
    }

    void setDutyCycle(unsigned ch, int d)
    {
      if (ch >= usedChannels) panic();

      channel[ch].setDutyCycle(d);
    }

    unsigned getFrequency(unsigned ch)
    {
      if (ch >= usedChannels) panic();
      return channel[ch].getFrequency();
    }

    unsigned getDutyCycle(unsigned ch)
    {
      if (ch >= usedChannels) panic();
      return channel[ch].getDutyCycle();
    }

    uint8_t getPin(unsigned ch)
    {
      if (ch >= usedChannels) panic();
      return channel[ch].getPin();
    }

  protected:
    Channel channel[nrOfChannels];

    unsigned usedChannels = 0;

    void panic()
    {
      pinMode(LED_BUILTIN, OUTPUT);
      while (true)
      {
        digitalWriteFast(LED_BUILTIN, !digitalReadFast(LED_BUILTIN));
        delay(50);
      }
    }
};
