
[![Banner]][Overview]

# Interrupts vs Polling

*There are two quadrature decoding strategies.*

<br>

## Interrupts

The most widely used strategy is to attach interrupts to <br>
input pins and try to catch all the bounce transitions to <br>
keep track of the final position.

<br>

### Cons

- Many calls have to be processed during a bounce period.

    *Depending on the quality of the switches, hundreds of interrupts* <br>
    *may be generated during each transition which can, especially* <br>
    *on slow processors, generate high, unpredictable processor loads.*

<br>

### Pros

- No Load is generated if the encoder isn't operated.

<br>

### Example

```C++
EncoderTool::Encoder encoder;

void setup(){
    
    /*
     *  A = 0
     *  B = 0
     *  Count Mode : Quarter
     */
    
    encoder.begin(0,1);
}

void loop(){   

    //  Print the encoders value every 100ms    

    Serial.println(encoder.getValue());

    delay(100);
}
```

<br>

***Note:***

  *For the `Teensy-LC` not all pins are interrupt capable.* <br>
  *Please check the pin-out card.*

<br>

---

<br>

## Polling

As seen in the **[Chapter On Bouncing][Bouncing]**, there is <br>
no need to catch each and every bounce signal.

Because only one of the two phases can change <br>
at a time, we can decode the signal with simple <br>
polling, under the condition that:

`Polling Rate > 2 x Maximum Count Rate` <br>
*( Not Maximum Bounce Rate )*

<br>

### Cons

- Always generate a processor load.

- You always have to poll.

<br>

### Pros

- The load is predictable as it doesn't change <br>
  during the operation of the encoder.

- Small load on manually operated encoders, as <br>
  these usually use a polling rate of only several ㎑.

- Handles multiplexed encoders without problem.

- The correct switch position can always <br>
  be determined after it stops bouncing.

<br>

### Example

```C++
EncoderTool::PollingEncoder encoder;

void setup(){
    
    /*
     *  A = 0
     *  B = 0
     *  Count Mode : Quarter
     */
    
    encoder.begin(0, 1);
}

elapsedMillis stopwatch = 0;

void loop(){
    
    //  You will need to call `tick()` as often as possible
    
    encoder.tick();
    
    //  Print the encoders value every 100ms
    
    if(stopwatch > 100){                
        stopwatch = 0;
        Serial.println(encoder.getValue());
    }
}
```


<!----------------------------------------------------------------------------->

[Bouncing]: Bouncing.md
[Overview]: Overview.md
[Banner]: ../Resources/Image/Banner.png