#include "EncoderTool.h"
using namespace EncoderTool;

constexpr unsigned encoderCount = 8;  // number of attached encoders

constexpr unsigned S0 = 0;            //address pin 0
constexpr unsigned S1 = 1;            //...
constexpr unsigned S2 = 2;            //address pin 2
constexpr unsigned SIG_A = 3;         //output pin SIG of multiplexer A
constexpr unsigned SIG_B = 4;         //output pin SIG of multiplexer B
                                      //breakout:  https://www.sparkfun.com/products/13906
                                      //datasheet: https://www.ti.com/lit/gpn/CD74HC4051

EncPlex4051 encoders(encoderCount, S0, S1, S2, SIG_A, SIG_B);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    encoders.begin();
}

unsigned t0 = 0;

void loop()
{
    encoders.tick();

    if (millis() - t0 > 100)  // display encoder values every 100 ms
    {
        for (unsigned i = 0; i < encoderCount; i++)
        {
            Serial.printf("E%u:%3d ", i, encoders[i].getValue());
        }
        Serial.println();
        t0 = millis();
    }
}
