#include "Arduino.h"
#include "EncoderTool.h"

#if defined(ESP32)
#    define LED_BUILTIN 2
#endif

using namespace EncoderTool;

constexpr unsigned encoderCount = 8; // number of attached  (daisy chain shift regesters for more than 8)

constexpr unsigned QH_A = 2;   // output pin QH of shift register B
constexpr unsigned QH_B = 3;   // output pin QH of shift register A
constexpr unsigned pinLD = 4;  // load pin for all shift registers)
constexpr unsigned pinCLK = 5; // clock pin for all shift registers
                               // 74165 datasheet: http://www.ti.com/product/SN74HC165

EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B);

void onFirstEncoder(int value, int delta)
{
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void onAnyEncoder(uint8_t channel, int value, int delta)
{
    Serial.print("Encoder: ");
    Serial.print(channel);
    Serial.print(" value: ");
    Serial.print(value);
    Serial.print(" delta: ");
    Serial.print(delta);
    Serial.println();
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    encoders.begin(CountMode::quarterInv);

    encoders[0].attachCallback(onFirstEncoder); // standard callback
    encoders.attachCallback(onAnyEncoder);
}

void loop()
{
    encoders.tick();
}
