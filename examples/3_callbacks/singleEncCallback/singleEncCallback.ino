#include "Arduino.h"
#include "EncoderTool.h"
using namespace EncoderTool;

constexpr uint8_t A = 2, B = 3, Btn = 4; // pins
PolledEncoder enc;

void onValueChanged(int32_t value, int32_t delta)
{
    Serial.print("New value: ");
    Serial.println(value);
    Serial.print(" Difference to last value: ");
    Serial.print(delta);
}

void onButtonChanged(int32_t state)
{
    Serial.print("Current button state: ");
    Serial.println(state == LOW ? "pressed" : "released");
}

void setup()
{
    enc.begin(A, B, Btn);
    enc.attachCallback(onValueChanged);        // call 'onValueChanged' whenever the encoder value changed
    enc.attachButtonCallback(onButtonChanged); // call 'onButtonChanged' whenever the button state changed
}

void loop()
{
    enc.tick(); // polled encoders need to be ticked
}
