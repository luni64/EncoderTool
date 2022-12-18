/***********************************************************************
 * This example uses a directly connected encoder matrix.
 * The matrix is described in the Resources/Extras folder. This folder
 * also contains KiCad files and Gerbers for a test board.
 *
 * !!! NEEDS ADAPTIONS FOR NON TEENSY BOARDS !!!
 ***********************************************************************/

#if __has_include (<array>)


#include "Arduino.h"
#include "EncoderTool.h"
#include "DirectMux.h"

using namespace EncoderTool;

DirectMux<3, 5> matrix;

// define used pins
constexpr unsigned AR0 = 2, BR0 = 3, SR0 = 4;                   // row 0
constexpr unsigned AR1 = 5, BR1 = 6, SR1 = 7;                   // row 1
constexpr unsigned AR2 = 8, BR2 = 9, SR2 = 10;                  // row 2
constexpr unsigned C0 = 23, C1 = 22, C2 = 21, C3 = 20, C4 = 19; // columns

void onEncoderChanged(uint_fast8_t channel, int value, int delta)
{
    Serial.printf("CH%d: %d\n", channel, value);
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    matrix.begin({AR0, AR1, AR2}, {BR0, BR1, BR2}, {SR0, SR1, SR2}, {C0, C1, C2, C3, C4});
    matrix.attachCallback(onEncoderChanged);
}

void loop()
{
    matrix.tick();
}

#else
    #warning Board not compatible
    void setup(){} // don't want compile errors to pass CI runs
    void loop(){}
#endif