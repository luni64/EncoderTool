#include "EncoderTool.h"
using namespace EncoderTool;

Encoder encoder;          // interrupt based encoder

void setup()
{
    encoder.begin(2, 3); // using pins 2 and 3 to connect encoder; make sure they are interrupt capable
}

void loop()
{
    if (encoder.valueChanged()) // do we have a new value?
    {
        Serial.println(encoder.getValue());
    }
}