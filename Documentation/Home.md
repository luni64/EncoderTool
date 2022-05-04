![banner](image/encoder.png)

The EncoderTool is an Arduino library for reading encoders with the ARM-based PJRC Teensy boards [T-LC and T3.0 - T4.1](https://www.pjrc.com/teensy/). It works with encoders connected directly to digital pins and with encoders connected to the controller via a **multiplexer**. The library targets manually operated, mechanical encoders, but also works with motor-driven, optical or magnetic encoders.

The underlying algorithms for single (1x) and dual (2x) edge evaluation are completely insensitive to contact bounce. The 4x algorithm is mainly used for mechanical encoders without detents or for bounce free high resolution encoders. 

For high speed encoders specialized libraries like the [QUAD-Encoder-Library](https://github.com/mjs513/Teensy-4.x-Quad-Encoder-Library)  from  [mjs513](https://github.com/mjs513)  might be a better choice.

----

* **[[Quick start guide]]**
* **Basics**
   * [[Encoder types]]
   * [[Connecting encoders]]
   * [[Quadrature signals and bouncing]]
   * [[Encoders with detents]]

* **[[Reference]]**
    

