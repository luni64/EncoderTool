/*------------------------------------------------------------------------------------

  This example uses the hardware shown here
  https://github.com/luni64/EncoderTool/tree/master/Resources/Extras#test-boards

------------------------------------------------------------------------------------ */

#include "Arduino.h"
#include "EncoderTool.h"
using namespace EncoderTool;

constexpr unsigned encoderCount = 8; // number of attached  (daisy chain shift regesters for more than 8)

constexpr unsigned QH_A = 0;   // output pin QH of shift register A
constexpr unsigned QH_B = 1;   // output pin QH of shift register B
constexpr unsigned pinLD = 3;  // load pin for all shift registers)
constexpr unsigned pinCLK = 4; // clock pin for all shift registers
                               // 74165 datasheet: http://www.ti.com/product/SN74HC165

EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B);

void setup()
{
    encoders.begin(CountMode::quarterInv);
}

void loop()
{
    encoders.tick();

    for (unsigned i = 0; i < encoderCount; i++)
    {
        if (encoders[i].valueChanged())
        {
            Serial.print("Encoder:");
            Serial.print(i);
            Serial.print(" value:");
            Serial.println(encoders[i].getValue());
        }
    }
}
