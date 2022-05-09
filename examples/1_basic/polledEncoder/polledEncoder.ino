#include "EncoderTool.h"
using namespace EncoderTool;

PolledEncoder encoder;

void setup()
{
    encoder.begin(2, 3); // using pins 2 and 3 to connect encoder; make sure they are interrupt capable
}

void loop()
{
    encoder.tick();             // polled encoders need to be ticked 

    if (encoder.valueChanged()) // do we have a new value?
    {
        Serial.println(encoder.getValue());
    }
}