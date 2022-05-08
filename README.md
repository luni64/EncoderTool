
[![Badge License]][License] [![Badge Arduino]][Arduino] [![Badge PlatformIO]][PlatformIO]
 # EncoderTool

*+ Bounce-Free Rotary Encoder Library + Push Button Support + Standard or Multiplexed Wiring + Callback System*

<br>

<div align = center>

---

<br>
<details>
  <summary><kbd>Examples</kbd></summary>
  <ul>
    <li> [Hello Encoder (most simple usage)](examples/01_HelloEncoder/01_HelloEncoder.ino) </li>
    <li> [Using a 74HC165 Multiplexer](examples/02_Multiplexed_74165/02_Multiplexed_74165.ino) </li>
  </ul>
</details>
</br>

[<kbd> <br> Documentation <br> </kbd>][Documentation]
[<kbd> <br> Schematics <br> </kbd>][Schematics] 

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

- Interupt based or polled readout strategies

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

<!-- [Badge Arduino]: https://img.shields.io/badge/Arduino-EncoderTool-00979D.svg?logo=arduino -->
[Badge Arduino]: https://www.ardu-badge.com/badge/EncoderTool.svg
[Badge PlatformIO]: https://badges.registry.platformio.org/packages/luni64/library/EncoderTool.svg
[Badge License]: https://img.shields.io/github/license/luni64/EncoderTool

[Arduino]: https://www.ardu-badge.com/EncoderTool
[PlatformIO]: https://registry.platformio.org/libraries/luni64/EncoderTool/

[Documentation]: https://github.com/luni64/EncoderTool/wiki
[Schematics]: extras
[Examples]: examples
[License]: LICENSE
[MPLEX74165]:extras/Boards/MPX_74165
[MPLEX4067]:extras/Boards/MPX_4067
[MPLEX4051]:extras/Boards/MPX_4051


