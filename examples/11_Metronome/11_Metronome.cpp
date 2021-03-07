#include "Arduino.h"
#include "metronome.h"

Metronome metronome;

// the metronome will call this function every 1/24th of a quarter note.
void ppqCallback()
{
    static int quarters = 0;
    static int beat = 0;

    digitalWriteFast(2, HIGH);      // every 1/24th quarter
    delayMicroseconds(1);
    digitalWriteFast(2, LOW);

    if (quarters == 0)              // every quarter
    {
        digitalWriteFast(3, HIGH);
        delayMicroseconds(1);
        digitalWriteFast(3, LOW);
    }
    if (beat == 0)                  // every beat
    {
        digitalWriteFast(4, HIGH);
        delayMicroseconds(1);
        digitalWriteFast(4, LOW);
    }

    quarters = (quarters+1) % 24;
    beat = (beat + 1) % 96;
}


void setup()
{
    for(int pin: {2,3,4, LED_BUILTIN}){      // we need pin 2,3,4 for the debugging output in ppqCallback
        pinMode(pin, OUTPUT);
    }

    metronome.begin(ppqCallback, 0, 1, 200); // attach an encoder at pins 0,1 to the metronome and limit its range to 200
                                             // tell the metronome to call "handleTimer" on each 1/24th quarter note
}

void loop()
{
    digitalToggleFast(LED_BUILTIN);          // heart beat
    delay(500);
}