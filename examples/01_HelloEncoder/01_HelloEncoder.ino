#include "EncoderTool.h"
using namespace EncoderTool;

Encoder encoder;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    encoder.begin(0, 1);
}

elapsedMillis stopwatch;

void loop()
{
    encoder.tick();

    if (stopwatch > 50)
    {
        Serial.println(encoder.getValue());
        stopwatch = 0;
    }
}