Basically, there are two types of quadrature decoding strategies. 
- The first and most widely used strategy is to attach **interrupts** to the input pins and try to catch all the bounce transitions to keep track of the final position. 
- The second one is a **polling** approach. 
As shown in the [[chapter about bouncing|Quadrature signals and bouncing]], there is no need to catch each and every bounce signal. The fact that only one of the two phases can change at a time enables us decoding by simple polling as long as the polling rate is larger than double the maximal possible *count rate* (not the *bounce rate*). We will always get the correct position after the switches stopped bouncing. 

As always, both methods have their advantages and disadvantages: 

- Interrupt based algorithms have to process many calls during the bouncing period. Depending on the quality of the switches, hundreds of interrupts may be generated during each transition.  Especially with slow processors this can generate a high, not predictable processor load. However, if the encoder is not operated, no load is generated at all. 
- In contrast, polling algorithms always generate a processor load. But this load is predictable and does not change while the encoder is being operated. Also, since a polling rate of several kHz is typically sufficient for manually operated encoders, the generated load is not very high. The main disadvantage is of course, well, that you have to poll. 
- Opposed to interrupt based algorithms, polling algorithms can handle multiplexed encoders without problems. 

The EncoderTool provides classes for both strategies: 

**Interrupt based:**

```c++
EncoderTool::Encoder encoder;  // interrupt based encoder

void setup()
{
    encoder.begin(0, 1);       // A=0, B=1, count mode: quarter
}

void loop()
{   
    Serial.println(encoder.getValue()); // print value every 100ms    
    delay(100);
}
```
Please note: For the Teensy-LC not all pins are interrupt capable. Please check the pin-out card.

**Polling:**
```c++
EncoderTool::PollingEncoder encoder;  // polled encoder

void setup()
{
    encoder.begin(0, 1);
}

elapsedMillis stopwatch = 0;

void loop() 
{ 
    encoder.tick();                 // need to call tick() as often as possible
    if(stopwatch > 100){            // print value every 100ms    
        stopwatch = 0;
        Serial.println(encoder.getValue());
    }
}
```

