
[![Banner]][Overview]

<br>

<div align = center>

# Quick Starter Guide

</div>

<br>
<br>

## Installation

Simply follow  the **[Installation Instructions]**.

<br>
<br>


## Testing

As a first introductory test of the library, here is an <br>
example of how to connect a standard mechanical <br>
encoder directly to digital pins.

<br>

![Simple Encoder]

<br>

Simply connect the pins in the following manner:

<kbd>      A      </kbd>  **⟼**  <kbd>  0  </kbd> <br>
<kbd>      B      </kbd>  **⟼**  <kbd>  1  </kbd> <br>
<kbd> Encoder Pin </kbd>  **⟼**  <kbd> GND </kbd>

<br>

### Setup

Check out the following example code <br>
for how to initialize a basic encoder.

```C++
#include "EncoderTool.h"

using namespace EncoderTool;


//  Single, directly connected encoder

Encoder encoder;

//  Time since last reading

elapsedMillis stopwatch = 0;


void setup(){
    
    /*
     *  Standard Configuration
     *  A = 0
     *  B = 1
     */
    
    encoder.begin(0,1);
}


void loop(){
    
    if(stopwatch < 250)
        return;
    
    //  Reads the current encoder value
    
    int value encoder.getValue();
    
    Serial.println(value);
    
    stopwatch = 0;
}
```

<br>

#### Problems

If you observe the counter jumping or not <br>
counting at all, it is most likely the related <br>
to the type of encoder you are using.

Please refer to the **[Reference]** section.

<br>

### Limited Output

If you want to limit the interval in which your <br>
encoder outputs, please check the **[Example][Limiting]**.

<br>

### Callbacks

You can also attach callbacks to your encoders:

<br>

*The EncoderTool will invoke the callback* <br>
*on any change of the current value.* <br>

*For your convenience it will pass in the current* <br>
*value and the difference to the last value.*

<br>

```c++
#include "EncoderTool.h"

using namespace EncoderTool;


//  Single, directly connected encoder

Encoder encoder;

//  Time since last reading

elapsedMillis stopwatch = 0;


void showValue(int value,int delta){
    Serial.printf("Value: %d Delta:%d \n",value,delta);
}

void setup(){
    
    /*
     *  Standard Configuration
     *  A = 0
     *  B = 1
     */
     
    encoder.begin(0,1);

    //  Attaches the callback function to the encoder
    
    encoder.attachCallback(showValue);
}


void loop(){}
```

<br>
<br>

### Further Reading

For more information please refer to the **[Reference]** documentation.

<br>


<!----------------------------------------------------------------------------->

[Installation Instructions]: Installation.md
[Reference]: Reference.md
[Overview]: Overview.md
[Limiting]: Limiting.md

[Simple Encoder]: ../Resources/Image/Simple.png
[Banner]: ../Resources/Image/Banner.png

