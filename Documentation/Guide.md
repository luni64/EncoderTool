
[![Banner]][Overview]

# Quick Starter Guide

- [Install The Library]

## First test

Let's see how to use the library with a standard mechanical encoder connected directly to digital pins. For the test we simply connect the encoder phases A and B to pins 0 and 1 and ground the common encoder pin as shown in the following schematic.

![Simple Encoder 1](../Resources/Image/SimpleEnc1.png)

### Construction and read out

To construct an encoder on pins 0/1 and periodically print its value to Serial you can use the following code:
```c++
#include "EncoderTool.h"
using namespace EncoderTool;

Encoder encoder;                     // single, directly connected encoder

void setup()
{
    encoder.begin(0,1);              // A=0, B=1
}

elapsedMillis stopwatch = 0;

void loop()
{
    if(stopwatch > 250)             // print value every 250ms
    {
        int p = encoder.getValue(); // get current value
        Serial.println(p);
        stopwatch = 0;
    }
  }
```

Please note: If you observe strange counting behavior (jumps, not counting at all etc.), this is most probably related to the encoder type your are using. See [[here|Encoder types]] for more information about common encoder types and how to setup the EncoderTool to support them.

### Limiting encoder output

You can limit the encoder output to an arbitrary interval or make the encoder output periodic.
![limits](image/limits.png)
See [[here|Limiting Encoder Output]] for details.

### Callbacks
You can also attach callbacks to your encoders:
```c++
#include "EncoderTool.h"
using namespace EncoderTool;

Encoder encoder;            // simple directly connected encoder

void showValue(int value, int delta)
{
    Serial.printf("value: %d delta:%d \n" value, delta);
}

void setup()
{
    encoder.begin(0,1);     // Pins 0 and 1, use standard configuration
    encoder.attachCallback(showValue);
}

elapsedMillis stopwatch = 0;

void loop()
{   
}
```
The EncoderTool will invoke the callback on any change of the current value. For your convenience it will pass in the current value and the difference to the last value.

### Further reading
* [[Information about common types of encoders and how to use them with the Encoder tool|Encoder Types]]
* [[Used algorithms for counting and debouncing|Algorithms]]
* [[How to use various multiplexers to connect your encoders|Multiplexed Encoders]]
* [[Details about the implemented callback system|Callbacks]]


<!----------------------------------------------------------------------------->

[Install The Library]: Installation.md
[Overview]: Overview.md
[Banner]: ../Resources/Image/Banner.png

