# EncoderTool
EncoderTool is a library to manage and read out rotary encoders with Teensy ARM boards.

## Key features
* Supports directly connected and multiplexed encoders
* Supports all common types of encoders, i.e., **full** (no detents, 4 counts per period), **half** (two detents and two counts per period)  and **quarter** (1 detent and one count per period) and some variants of those. 
* A callback mechanism allows for easy event based menu systems. Callbacks use std::function and can call non static member functions.
* Fully bounce free without additional hardware
* Provides hard and cyclic count limits
* Currently 74165 and 4067 based multiplexers are supported but the class structure allows for easy extension to any other multiplexer.
* Schematics and Eagle files for multiplexed encoders available in the Extras folder

### -> [Documentation](https://github.com/luni64/EncoderTool/wiki)

