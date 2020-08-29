#include "EncoderTool.h"
#include "FreqGen.h"
using namespace EncoderTool;

void onFrequencyChanged(int encVal, int encDelta);
void onChannelChanged(int encVal, int encDelta);
void onDutyCycleChanged(int encVal, int encDelta);

FreqGen_t generator;
Encoder frequencyEncoder;
Encoder dutyCycleEncoder;
Encoder chnSelectEncoder;

void setup()
{
    while (!Serial && millis() < 1000) {} // wait for USB to connect

    generator.addOutputPins({9, 10, 11, 12, 14, 15}); // define up to 8 output pins (here for a T4.0)

    chnSelectEncoder.begin(0, 1, onChannelChanged);                 // encoder to select current channel on pin 0/1 using onChannelChanged callback
    frequencyEncoder.begin(2, 3, onFrequencyChanged);               // encoder to select freqency
    dutyCycleEncoder.begin(4, 5, onDutyCycleChanged);               // encoder to select duty cylce
    chnSelectEncoder.setLimits(0, generator.getNrOfChannels() - 1); // limit channel encoder range to actual number of defined channels

    onChannelChanged(0, 0); // print some info at startup
}

void loop()
{
    frequencyEncoder.tick();
    chnSelectEncoder.tick();
    dutyCycleEncoder.tick();
}

// Helpers ===================================================
void printChannelInfo(unsigned ch)
{
    int pin = generator.getPin(ch);
    int frq = generator.getFrequency(ch);
    int dty = generator.getDutyCycle(ch);

    Serial.printf("Pin: %u -> f=%u Hz d=%u %%\n", pin, frq, dty);
}

void onFrequencyChanged(int encVal, int encDelta)
{
    unsigned ch = chnSelectEncoder.getValue();
    unsigned f = generator.getFrequency(ch) + encDelta * 1000;
    generator.setFrequency(ch, f);

    printChannelInfo(ch);
}

void onDutyCycleChanged(int encVal, int encDelta)
{
    unsigned ch = chnSelectEncoder.getValue(); // get the currently active channel
    unsigned d = generator.getDutyCycle(ch) + encDelta * 5;
    generator.setDutyCycle(ch, d);

    printChannelInfo(ch);
}

void onChannelChanged(int encVal, int encDelta)
{
    Serial.printf("\nSetup pin %u\n", generator.getPin(encVal));
    printChannelInfo(encVal);
}
