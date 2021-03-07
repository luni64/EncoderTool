#pragma once

#include "EncoderTool.h"

class Metronome
{
 public:
    void begin(void (*ppqCallback)(void), unsigned encA, unsigned encB, unsigned maxBPM)
    {
        cb = ppqCallback;
        bpmEncoder.begin(encA, encB, [this](int v, int d) { this->EncoderChanged(v, d); });
        bpmEncoder.setLimits(0, maxBPM);
    }

 private:

    void EncoderChanged(int encValue, int d)          // called whenever the encoder value changes
    {
        float bpm = encValue;                         // change this if you want bpm calculated from encoder value in an other way (e.g. bmp = encValue * 0.1f)

        Serial.printf("%.1f bpm\n", bpm);

        if (bpm == 0.0f)                              // switch timer off
        {
            Serial.println("stop");
            ppqTimer.end();
            isRunning = false;
        } else
        {
            constexpr float pFac = 60.0E6f / (4 * 24); // calculate timer period from bpm, assuming  1/24th of a quarter note at the given bpm
            float period = pFac / bpm;                 // microseconds

            if (isRunning)
                ppqTimer.update(period);               // timer already running -> updating period only
            else                                       // if the timer doesn't run yet we need to start it
            {
                ppqTimer.begin(cb, period);            // call the passed in function to do whatever needs to be done every 1/24 quarter note
                isRunning = true;
            }
        }
    }

    void (*cb)(void);                                  // storage for the passed in handling function
    bool isRunning = false;                            // we don't have a simple method to check if the timer runs. So, we keep track ourselves

    EncoderTool::Encoder bpmEncoder;                   // encoder to select bpm
    IntervalTimer ppqTimer;                            // timer to call the  handling function every 1/24th of a quarter note
};
