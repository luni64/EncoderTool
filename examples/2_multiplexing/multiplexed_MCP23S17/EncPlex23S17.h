/************************************************************
 *
 * Use a MCP23S17 multiplexer to read out up to 8 attached encoders
 * The A/B pins of the encoders go to the A/B inputs of the MCP
 *
 ************************************************************/

#pragma once

#include <Adafruit_MCP23X17.h> //https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
#include "EncoderTool.h"

namespace EncoderTool
{
    class EncPlex23S17 : public EncPlexBase<int>
    {
     public:
        inline EncPlex23S17(unsigned EncoderCount);

        inline void begin(CountMode mode);
        inline void tick(); // call as often as possible

     protected:
        Adafruit_MCP23X17 mcp21S17;
        bool isSetup = false;
    };

    //================================================================================
    // INLINE IMPLEMENTATION

    EncPlex23S17::EncPlex23S17(unsigned encoderCount) // nothing to do but telling the base class the number of encoders
        : EncPlexBase(encoderCount)
    {}

    void EncPlex23S17::begin(CountMode mode = CountMode::quarter)
    {
        EncPlexBase::begin(mode);                   // setup the base class
        mcp21S17.begin_SPI(10);                     // setup the Adafruit MCP21S17 interface: SPI, CS on pin 10
        for (unsigned i = 0; i < encoderCount; i++) // configure all needed pins as input. We start with A_0/B_0 up to the required number of pin pairs
        {
            mcp21S17.pinMode(i, INPUT_PULLUP);
            mcp21S17.pinMode(i + 8, INPUT_PULLUP);
        }
        isSetup = true;
    }

    void EncPlex23S17::tick() // call this as often as possible
    {
        if (isSetup)  // tick might be called from a timer or yield before it is setup
        {
            uint16_t data = mcp21S17.readGPIOAB();       // read the data from the 23S17 multiplexer
            for (unsigned i = 0; i < encoderCount; i++)  // for all configured encoders
            {                                            // extract the A/B
                unsigned A = (data & 1 << i) != 0;       //
                unsigned B = (data & 1 << (i + 8)) != 0; //
                int delta = encoders[i].update(A, B);    // the base class will take care of the decoding

                if (delta != 0 && callback != nullptr) callback(i, encoders[i].getValue(), delta); // if something changed, invoke the callback
            }
        }
    }
} // namespace EncoderTool