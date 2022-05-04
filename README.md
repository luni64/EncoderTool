
# EncoderTool [![Badge License]][License] [![Badge PlatformIO]][PlatformIO]

*Rotary Encoder + Teensy ARM Readout / Management Library*

<br>

<div align = center>

---

[<kbd> <br> Examples <br> </kbd>][Examples] 
[<kbd> <br> Schematics <br> </kbd>][Schematics] 
[<kbd> <br> Documentation <br> </kbd>][Documentation]

---
</div>

<br>

## Supports

<br>

- Directly conneced encoders using interupt or polled readout

- Multiplexed Encoders using

    - [`74HC165` Shift Registers][MPLEX74165]

    - [`40HC67` 16x Analog Switch][MPLEX4067]

    - [`40HC51` 8x Analog Switch][MPLEX4051]

<br>

- All Common Encoders with and w/o push buttons:

    | Type | Detents | Counts per Period
    |:----:|:-------:|:----------------:
    | ***Full***    | ` 0 ` | ` 4 `
    | ***Half***    | ` 2 ` | ` 2 `
    | ***Quarter*** | ` 1 ` | ` 1 `

    *+ Some variants of those*


 <br>

- Optimized for

    - Teensy ARM boards (LC, Teensy 3.x, Teensy 4.x)

    - ESP32

    - SEEED XIAO

    - 8bit Arduino AVR boards (UNO, Nano, Mega...)

  *+ Fallback for all boards supporting digitalWrite/digitalRead*

<br>

## Features

- Class structure allows for easy extension to other multiplexers

- Schematics and Eagle files available for multiplexed encoder boards

- Fully bounce free without additional hardware

- Provides hard and cyclic count limits

- Modern callback system for event based applications

<br>
<br>


- Encoder Push Buttons

    *Auto - debounces & makes callbacks available*

<br>




<!----------------------------------------------------------------------------->

[Badge PlatformIO]: https://img.shields.io/badge/PlatformIO-luni64/TeensyEncoderTool-ff7e00.svg?style=for-the-badge
[Badge License]: https://img.shields.io/github/license/luni64/EncoderTool?style=for-the-badge

[PlatformIO]: https://registry.platformio.org/libraries/luni64/TeensyEncoderTool/

[Documentation]: https://github.com/luni64/EncoderTool/wiki
[Schematics]: extras
[Examples]: examples
[License]: LICENSE
[MPLEX74165]:extras/Boards/MPX_74165
[MPLEX4067]:extras/Boards/MPX_4067
[MPLEX4051]:extras/Boards/MPX_4051


