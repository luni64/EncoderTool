#pragma once

#include "Multiplexed/EncPlexBase.h"
#include <array>

namespace EncoderTool
{
    template <size_t rows, size_t cols>
    class DirectMux : public EncPlexBase
    {
        // some typedefs for less verbose code
        using cArr_t = std::array<uint_fast8_t, cols>;
        using rArr_t = std::array<uint_fast8_t, rows>;

     public:
        DirectMux() : EncPlexBase(rows * cols) {}

        void begin(rArr_t arPins, rArr_t brPins, rArr_t srPins, cArr_t cPins, CountMode mode = CountMode::quarter)
        {
            EncPlexBase::begin(mode); // setup the base class
            this->arPins = arPins;    // copy passed in pin numbers
            this->brPins = brPins;
            this->srPins = srPins;
            this->cPins  = cPins;

            for (auto pin : arPins) pinMode(pin, INPUT_PULLUP);
            for (auto pin : brPins) pinMode(pin, INPUT_PULLUP);
            for (auto pin : srPins) pinMode(pin, INPUT_PULLUP);
            for (auto pin : cPins)
            {
                pinMode(pin, OUTPUT);
                digitalWriteFast(pin, HIGH);  // board is implemented as active LOW 
            }
        }

        inline void tick() // call as often as possible
        {
            unsigned curEnc = 0;
            for (auto cPin : cPins)
            {
                digitalWriteFast(cPin, LOW);
                delayNanoseconds(500);

                for (unsigned row = 0; row < rows; row++)
                {
                    uint_fast8_t A = digitalReadFast(arPins[row]);
                    uint_fast8_t B = digitalReadFast(brPins[row]);
                    uint_fast8_t S = digitalReadFast(srPins[row]);

                    int delta = encoders[curEnc].update(A, B, S);
                    if (delta != 0 && callback != nullptr)
                    {
                        callback(curEnc, encoders[curEnc].getValue(), delta); // if something changed, invoke the callback
                    }
                    curEnc++;
                }
                digitalWriteFast(cPin, HIGH);
            }
        }

     protected:
        rArr_t arPins, brPins, srPins;
        cArr_t cPins;
    };
}