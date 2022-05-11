#include "Arduino.h"
#include "EncoderTool.h"

using namespace EncoderTool;

constexpr unsigned encoderCount = 8; // number of attached  (daisy chain shift regesters for more than 8)

constexpr unsigned QH_A = 0;   //output pin QH of shift register B
constexpr unsigned QH_B = 1;   //output pin QH of shift register A
constexpr unsigned pinLD = 3;  //load pin for all shift registers)
constexpr unsigned pinCLK = 4; //clock pin for all shift registers
                               //74165 datasheet: http://www.ti.com/product/SN74HC165

EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B);

void myCallback(int value, int delta)
{
    Serial.printf("Current value: %d, delta = %d\n", value, delta);
}

void setup()
{
    pinMode(13, OUTPUT);
    encoders.begin(CountMode::quarterInv);

    encoders[0].attachCallback(myCallback); // standard callback
    encoders[1].attachCallback([](int v, int d) { digitalToggleFast(13); }); // a simple lambda expression to toggle the LED on every change
    encoders[2].attachCallback([](int v, int d) { Serial.printf("enc 2: %s\n", d > 0 ? "UP" : "DOWN"); });
}

elapsedMillis stopwatch = 0;

void loop()
{
    encoders.tick();
}



