
[![Banner]][Overview]

# Content
* **Directly connected encoders**
  * [Construction](#construction)
  * [Getting and setting the position counter](#getting-and-setting-the-position-counter)  
  * [Limiting the count range](#limiting-the-count-range)
  * [Attaching callbacks](#attaching-callbacks)
* [Multiplexed encoders](#multiplexed-encoders)
  * Construction
    * [74xx165 based multiplexer](#74xx165-based-multiplexer)
    * [CD4067 based multiplexer](#cd4067-based-multiplexer)
  * [Accessing multiplexed encoders](#accessing-multiplexed-encoders)
  * [Attaching a callback](#attaching-a-callback)
* **Miscellaneous**
  * [Namespace](#namespace)
  * [Count Modes](count-modes)

# Directly connected encoders
## Construction

```c++
using namespace EncoderTool;

Encoder enc1, enc2, enc3;  // Interrupt based encoder see 
PollEncoder enc4, enc5;    // Polling encoder, please call corresponding tick() functions as often as possible, e.g. in loop

void setup()
{
    enc1.begin(0, 1);                                  // A=0, B=1, default count mode quarter (4 counts per detent)
    enc2.begin(2, 3, CountMode::half);                 // A=2, B=3, count mode half (2 counts per detent)
    enc3.begin(4, 5, posDisp);                         // A=4, B=5, uses callback posDisp, default count mode
    enc3.begin(6, 7, posDisp, CountMode::quarterInv);  // A=5, B=6, uses callback posDisp, count mode quarterInv (common VCC instead of common GND)
    enc4.begin(8, 9, CountMode::quarter, INPUT_PULLUP);// A=7, B=8, count mode quarterInv, pinMode set to INPUT_PULLDOWN (any INPUT mode possible here)
    //...
}
```
[Back](#content)

## Getting and setting the position counter
```c++
int val = encoder.getValue(); // read the current position counter
encoder.setValue(0);          // set the counter to a position
```
[Back](#content)

## Limiting the count range
```c++
encoder1.setLimits(3, 13);            // limits the count range to [3..13]
encoder2.setLimits(0, 12, true);      // cyclic count range from [0..12] 
encoder3.setLimits(-1999, 2000, true) // limit a 4000ppr encoder for easy angle calculation: float angle = (180.0f/2000.0f)*encoder3.getValue();
```
[Back](#content)

## Attaching callbacks
```c++
void myCallback(int position, int delta)
{
   Serial.println("pos:%d delta:%d\n", position, delta);
}

void setup()
{ 
  encoder1.attachCallback(myCallback);                              // attach a callback which takes the current position and the delta to the last position
  encoder2.attachCallback([](int p, int delta){Serial.println(p);}) // lambda expression callback
}
```
Embedd an encoder in a user class:
```c++
class Menu
{
 public:
    void begin(){
        encoder.begin(0, 1);
        encoder.setLimits(0, 2, true);
        encoder.attachCallback([this](int v, int d) { displayText(v); }); // attach member function
    }

    void displayText(int value){
        switch (value){
            case 0: Serial.println("First");  break;
            case 1: Serial.println("Second"); break;
            case 2: Serial.println("Third");  break;
            default: break; // can never happen
        }
    }

 protected:
    Encoder encoder;
};
//-----------

Menu testMenu;

void setup(){
    testMenu.begin();
}

void loop(){
}

```

[Back](#content)

# Multiplexed encoders

See here https://github.com/luni64/EncoderTool/tree/master/extras for schematics and boards.

## Construction
#### 74xx165 based multiplexer
```c++
//...
constexpr unsigned cnt =    6; // number of attached encoders (daisy chain shift registers for more than 8)
constexpr unsigned QH_A =   0; // output pin QH of shift register A
constexpr unsigned QH_B =   1; // output pin QH of shift register B
constexpr unsigned pinLD =  3; // load pin for all shift registers)
constexpr unsigned pinCLK = 4; // clock pin for all shift registers
                               // 74165 datasheet: http://www.ti.com/product/SN74HC165

EncPlex74165 encoders(cnt, pinLD, pinCLK, QH_A, QH_B, CountMode::quarterInv);

void setup()
{
    encoders.begin();
    //...
}
```
[Back](#content)

#### CD4067 based multiplexer
```c++
//...
constexpr unsigned cnt =  16; // number of attached encoders
constexpr unsigned S0 =    0; //address pin 0
constexpr unsigned S1 =    1; //...
constexpr unsigned S2 =    2; //...
constexpr unsigned S3 =    3; //address pin 3
constexpr unsigned SIG_A = 4; //output pin SIG of multiplexer A
constexpr unsigned SIG_B = 5; //output pin SIG of multiplexer B
                              //breakout:  https://www.sparkfun.com/products/9056
                              //datasheet: https://www.ti.com/lit/gpn/CD74HC4067

EncPlex4067 encoders(cnt, S0, S1, S2, S3, SIG_A, SIG_B);

void setup()
{    
    encoders.begin();
   //...
}
```
[Back](#content)

## Accessing multiplexed encoders
```c++
//...
EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B);

void setup()
{   
    encoders.begin();

    encoders[0].setLimits(0,10);         // access first multiplexed encoder
    encoders[1].setLimits(0,24,true);    // access second multiplexed encoder

    encoders[4]                          // same with fluent interface  
        .setCountMode(CountMode::half)   // override count mode
        .setLimits(0, 10)
        .attachCallback(myCallback);     // attach a callback to encoder[4]

   int currentValue5 = encoders[5].getValue();
}

```
[Back](#content)

## Attaching a callback
In addition to callbacks for the dedicated encoders you can also attach a callback which will be invoked if any of the multiplexed encoders changes:
```c++
void globalCallback(unsigned enc_idx, int value, int delta)
{
    Serial.printf("enc[%u]: v=%d, d=%d\n", enc_idx, value, delta);
}

EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B);

void setup()
{
    encoders.begin();
    encoders.attachCallback(globalCallback);  // this will be called if any encoder changes its values
}
```

[Back](#content)


# Miscellaneous
## Namespace

The EncoderTool uses the namespace `EncoderTool` to prevent clashes with commonly used symbol names like `Encoder`. Thus, you can either use fully qualified names: 
```c++
#include "EncoderTool.h"

EncoderTool::Encoder encoder;  // <-- Fully qualified name
//...
```
or, alternatively, you can import all symbols from the EncoderTool namespace with a `using namepsace EncoderTool` statement:
```c++
#include "EncoderTool.h"
using namespace EncoderTool;

Encoder encoder;  
//...
```
[Back](#content)


 
<!----------------------------------------------------------------------------->

[Overview]: Overview.md
[Banner]: ../Resources/Image/Banner.png





