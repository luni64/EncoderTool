#include "EncoderTool.h"
using namespace EncoderTool;

PolledEncoder enc;

void setup()
{
    constexpr int pinA = 0, pinB = 1, pinBtn = 2;
    enc.begin(pinA, pinB, pinBtn);
}

void loop()
{
    enc.tick();

    if (enc.valueChanged())  { Serial.printf("value:  %d\n", enc.getValue()); }
    if (enc.buttonChanged()) { Serial.printf("button: %s\n", enc.getButton() == LOW ? "pressed" : "released"); }
}
