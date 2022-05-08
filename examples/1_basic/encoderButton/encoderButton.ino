#include "EncoderTool.h"
using namespace EncoderTool;

constexpr uint8_t pinA = 0, pinB = 1, pinBtn = 2;

PolledEncoder enc;

void setup()
{
    enc.begin(pinA, pinB, pinBtn);
}

void loop()
{
    enc.tick();                         // polled encoder -> call tick() as often as possible

    if (enc.valueChanged())             // do we have a new encoder value?
    {
        Serial.print("new value: ");
        Serial.println(enc.getValue());
    }
    if (enc.buttonChanged())            // do we have a new button state?
    {
        Serial.print("button state: ");
        Serial.println(enc.getButton() == LOW ? "pressed" : "released");
    }
}
