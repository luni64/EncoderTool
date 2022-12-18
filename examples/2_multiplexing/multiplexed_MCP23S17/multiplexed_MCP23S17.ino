
/************************************************************
 *
 * Use a MCP23S17 multiplexer to read out up to 8 attached encoders
 * The A/B pins of the encoders go to the A/B inputs of the MCP
 *
 ************************************************************/
#include <Adafruit_MCP23X17.h>
#include "EncPlex23S17.h"
#include "EncoderTool.h"

using namespace EncoderTool;

EncPlex23S17 encoder(8); // use all 8 (A/B) inputs of the 23S17 to connect encoders

// this will be called whenever one of the connected encoders changes
void onChange(byte ch, int value, int delta)
{
    char buf[50];
    snprintf(buf,50,"Encoder #: %d, value: %3d, delta: %2d\n", ch, value, delta);
    Serial.println(buf);
}

void setup()
{
    digitalWrite(LED_BUILTIN, OUTPUT);

    encoder.begin();
    encoder.attachCallback(onChange); // attach a common callback for all encoders
}

void loop()
{
    encoder.tick();
}
