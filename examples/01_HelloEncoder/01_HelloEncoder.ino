#include "EncPlex.h"
//#include "pins.h"

//using namespace pins;

EncPlex::Encoder enc1(0, 1, INPUT_PULLUP);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(14, OUTPUT);
    enc1.begin();

    // pin<0>().slowSlewRateEnable(true);
    // pin<1>().slowSlewRateEnable(true);
}

elapsedMillis stopwatch;

void loop()
{
    enc1.tick();

    if(stopwatch > 50)
    {
        Serial.println(enc1.read());
        stopwatch = 0;
    }
    delayMicroseconds(100);
}