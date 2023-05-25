
# EncoderTool  [![Badge License]][License]  [![Badge Arduino]][Arduino]  [![Badge PlatformIO]][PlatformIO]

*Bounce-Free Rotary Encoder Library* <br>
 **+** *Standard or Multiplexed Wiring* <br>
 **+** *Push Button Support* <br>
 **+** *Callback System*

<br>

<div align = center>

---

[<kbd> <br> Examples <br> </kbd>][Examples] 
[<kbd> <br> Schematics <br> </kbd>][Schematics] 
[<kbd> <br> Documentation <br> </kbd>][Documentation] 
[<kbd> <br> Contributors <br> </kbd>][Contributors]

---
</div>

<br>

## Supports

<br>

- All common encoders with and without push buttons

- Directly connected encoders (A+B+Button to pins)

- Multiplexed encoders using

    - [`74HC165 (up to 32 encoders)`][MPLEX74165]

    - [`40HC67  (up to 16 encoders)`][MPLEX4067]

    - [`40HC51  (up to 8 encoders)`][MPLEX4051]

    - Easy to adapt for your preferred multiplexer

- Interrupt based or polled readout strategies

<br>

## Board Compatibility

<br>

- PJRC Teensy (Teensy-LC, Teensy 3.x, Teensy 4.x, MicroMod)

- SAMD (SEEED XIAO, Nano33 ...)

- 8bit Arduino AVR (UNO, Nano, Mega...)

- ESP32

- Fallback solution for other boards (using slow digitalRead/Write)

<br>

## Features

- Fully bounce free readout without additional hardware

- Provides hard and cyclic count limits

- Supports and debounces encoder push buttons

- Modern callback system for event driven applications

- Encoders can be connected directly (A / B / Btn connected to pins)

- Encoder connection using various multiplexers (up to 32 encoders on only 4 control pins)

- Schematics and Gerbers available for multiplexed encoder boards (Eagle/KiCad).


<!----------------------------------------------------------------------------->

[PlatformIO]: https://registry.platformio.org/libraries/luni64/EncoderTool/
[Arduino]: https://www.arduino.cc/reference/en/libraries/encodertool/

[License]: LICENSE
[MPLEX74165]:Resources/extras/Boards/MPX_74165
[MPLEX4067]:Resources/extras/Boards/MPX_4067
[MPLEX4051]:Resources/extras/Boards/MPX_4051



[Documentation]: Documentation/Overview.md
[Contributors]: Documentation/Contributors.md
[Schematics]: Resources/Extras
[Examples]: examples

[MPLEX74165]: Resources/Extras/Boards/MPX_74165
[MPLEX4067]: Resources/Extras/Boards/MPX_4067
[MPLEX4051]: Resources/Extras/Boards/MPX_4051


<!--------------------------------{ Badges }----------------------------------->

[Badge PlatformIO]: https://img.shields.io/badge/PlatformIO-EncoderTool-fd7e14.svg?style=for-the-badge
[Badge Arduino]: https://img.shields.io/badge/EncoderTool-00979D.svg?style=for-the-badge&logo=Arduino&logoColor=white&labelColor=gray
[Badge License]: https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge

