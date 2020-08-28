#include "Arduino.h"
#include "EncoderTool.h"
using namespace EncoderTool;

constexpr unsigned encoderCount = 8; // number of attached  (daisy chain shift regesters for more than 8)

constexpr unsigned QH_A   = 0; //output pin QH of shift register B
constexpr unsigned QH_B   = 1; //output pin QH of shift register A
constexpr unsigned pinLD  = 3; //load pin for all shift registers)
constexpr unsigned pinCLK = 4; //clock pin for all shift registers
                               //74165 datasheet: http://www.ti.com/product/SN74HC165

EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B, CountMode::quarterInv);


void setup()
{
    encoders.begin();
}

elapsedMillis stopwatch = 0;


void loop()
{
    encoders.tick();

    if (stopwatch > 100)  // display encoder values every 100 ms
    {
        for (unsigned i = 0; i < encoderCount; i++)
        {
            Serial.printf("E%u:%3d ", i, encoders[i].getValue());
        }
        Serial.println();
        stopwatch = 0;
    }
}