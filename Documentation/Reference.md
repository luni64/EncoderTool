
[![Banner]][Overview]

<br>

<div align = center>

# Direct Encoders

*Directly connected encoders.*

</div>
    
<br>

## Basic Examples

```C++
#include "EncoderTool.h"

using namespace EncoderTool;


// Interrupt Based Encoders 

Encoder
    encoderA,
    encoderB,
    encoderC;

/*
 *  Polling Based Encoder
 *
 *  Call the tick() function as often 
 *  as possible -> In a loop
 */ 


PollEncoder
    encoderD,
    encoderE;    


void setup(){
    
    /*
     *  Count Mode : Default ( 4 Counts / Detent )
     *  A = 0
     *  B = 1
     */

    encoderA.begin(0,1);

    /*
     *  Count Mode = Half ( 2 Counts / Detent )
     *  A = 2
     *  B = 3
     */

    encoderB.begin(2,3,CountMode::half);

    /*
     *  Count Mode : Default
     *  A = 4
     *  B = 5
     *  Callback = posDisp
     */

    encoderC.begin(4,5,posDisp);
    
    /*
     *  Count Mode : quarterInv
     *  A = 6
     *  B = 7
     *  Callback = posDisp
     *
     *  Common VCC instead of common GND
     */
    
    encoderD.begin(6,7,posDisp,CountMode::quarterInv);
    
    /*
     *  Count Mode : quarterInv
     *  A = 7
     *  B = 8
     *  PinMode = INPUT_PULLDOWN
     */
    
    encoderE.begin(8,9,CountMode::quarter,INPUT_PULLUP);
}
```

<br>

## Get

*Read the current position counter.*

```C++
int value = encoder.getValue();
```

<br>

## Set

*Set the counter to a position.*

```C++
encoder.setValue(0);
```

<br>

## Limit

*Set the limit for the count range.*

<br>

*Limits the count range to ` 3 → 13 `*

```C++
encoder.setLimits(3,13);
```

<br>

*Cyclic count range from ` 0 → 12 `*

```C++
encoder.setLimits(0,12,true); 
```

<br>

*Limit a `4000ppr` encoder for easy angle calculation*

```C++
encoder.setLimits(-1999,2000,true);
```
```C++
float angle = ( 180.0f / 2000.0f ) * encoder.getValue();
```


<br>

## Callbacks
```C++
void myCallback(int position,int delta){
    Serial.println("Position:%d Delta:%d\n",position,delta);
}

void setup(){
    
    //  Attach a callback which takes the current position and the delta to the last position
    
    encoderA.attachCallback(myCallback);
    
    // Lambda expression callback
    
    encoderB.attachCallback([](int position,int delta){
        Serial.println(position);
    });
}
```

<br>

Embedded an encoder in a user class:

```c++
class Menu {
    
    protected:
        
        Encoder encoder;

    public:
        
        void begin(){
            encoder.begin(0,1);
            encoder.setLimits(0,2,true);
            encoder.attachCallback([this](int value,int delta){
                displayText(value);
            });
        }

        void displayText(int value){
            switch(value){
            case 0 : 
                Serial.println("First");
                return;
            case 1 : 
                Serial.println("Second");
                return;
            case 2 :
                Serial.println("Third");
                return;
            }
        }
};
```
```C++
Menu menu;

void setup(){
    menu.begin();
}

void loop(){}
```

<br>
<br>
<br>
<br>

<div align = center>

# Multiplexed Encoders

You may want to check the **[Boards & Schematics]**.

</div>

<br>

## Basic Examples

#### 74xx165 Based Multiplexer

```C++
/*
 * 74165 Datasheet
 * http://www.ti.com/product/SN74HC165
 */

EncPlex74165 encoders(
    6 , //  Number of Encoders
    3 , //  Load Pin
    4 , //  Clock Pin
    0 , //  Output Pin ( Register A )
    1 , //  Output Pin ( Register B )
    CountMode::quarterInv
);


void setup(){
    encoders.begin();
}
```

<br>

#### CD4067 Based Multiplexer

```C++
/*
 *  Breakout : https://www.sparkfun.com/products/9056
 *  Datasheet : https://www.ti.com/lit/gpn/CD74HC4067
 */

EncPlex4067 encoders(
    16 , //  Number of Encoders
     0 , //  Address Pin 0
     1 , //  Address Pin 1
     2 , //  Address Pin 2
     3 , //  Address Pin 3
     4 , //  Output Pin ( Multiplexer A )
     5   //  Output Pin ( Multiplexer B )
);


void setup(){
    encoders.begin();
}
```

<br>

## Accessing Multiplexed Encoders

```C++
void setup(){
    
    encoders.begin();

    //  Access first multiplexed encoder
    
    encoders[0].setLimits(0,10);
    
    //  Access second multiplexed encoder
    
    encoders[1].setLimits(0,24,true);

    //  Same with fluent interface

    encoders[4]
        .setCountMode(CountMode::half)
        .attachCallback(myCallback)
        .setLimits(0,10);

    //  Read value of 6th encoder

    int value = encoders[5].getValue();
}
```

<br>

## Attaching A Callback

In addition to callbacks for the dedicated encoders <br>
you can also attach a callback which will be invoked <br>
if any of the multiplexed encoders changes.

```C++
void callback(unsigned int encoderIndex,int value,int delta){
    Serial.printf("Encoder[%u]: Value = %d | Delta = %d\n",encoderIndex,value,delta);
}

void setup(){

    encoders.begin();
    
    // This attaches the callback to all encoders
    
    encoders.attachCallback(callback);
}
```

<br>
<br>
<br>
<br>

<div align = center>

# Miscellaneous

</div>

<br>

## Namespace

The library uses the namespace `EncoderTool` to prevent <br>
clashes with commonly used symbol names like `Encoder`.

<br>

Thus, you can either use fully qualified names: 

```C++
EncoderTool::Encoder encoder;
```

<br>

or alternatively you can import all symbols from the namespace.

```C++
using namespace EncoderTool;
```
```C++
Encoder encoder;  
```

 
<!----------------------------------------------------------------------------->

[Overview]: Overview.md

[Boards & Schematics]: ../Resources/Extras
[Banner]: ../Resources/Image/Banner/Current.png






