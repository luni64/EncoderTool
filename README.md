
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

## Features

- Class structure allows for easy extension of other multiplexer

- Schematics and Eagle files available for multiplexed encoders

- Fully bounce free without additional hardware

- Provides hard and cyclic count limits

<br>
<br>

## Supports

<br>

- Direct / Multiplexed Encoders

<br>

- All Common Encoders:

    | Type | Detents | Counts per Period
    |:----:|:-------:|:----------------:
    | ***Full***    | ` 0 ` | ` 4 `
    | ***Half***    | ` 2 ` | ` 2 `
    | ***Quarter*** | ` 1 ` | ` 1 `
    
    *+ Some variants of those*
    
<br>

- Encoder Push Buttons

    *Auto - debounces & makes callbacks available*
    
<br>
    
- Multiplexed Encoders:

    - `74165`
    
    - `4067`
    
    - `4051`
    
    
<!----------------------------------------------------------------------------->

[Badge PlatformIO]: https://img.shields.io/badge/PlatformIO-luni64/TeensyEncoderTool-ff7e00.svg?style=for-the-badge
[Badge License]: https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge

[PlatformIO]: https://registry.platformio.org/libraries/luni64/TeensyEncoderTool/

[Documentation]: https://github.com/luni64/EncoderTool/wiki
[Schematics]: extras/Boards
[Examples]: examples
[License]: LICENSE


