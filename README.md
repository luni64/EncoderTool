
# EncoderTool

*Rotary Encoder + Teensy ARM readout / management library*

<br>

---

[<kbd> <br> Examples <br> </kbd>][Examples]
[<kbd> <br> Schematics <br> </kbd>][Schematics]
[<kbd> <br> Documentation <br> </kbd>][Documentation]

---

<br>

## Features

- Class structure allows for easy extension of other multiplexer

- Schematics and Eagle files available for multiplexed encoders

- Fully bounce free without additional hardware

- Provides hard and cyclic count limits

<br>

## Supports

- Direct / Multiplexed Encoders

- All Common Encoders:

    | Type | Detents | Counts per Period
    |:----:|:-------:|:----------------:
    | ***Full***    | ` 0 ` | ` 4 `
    | ***Half***    | ` 2 ` | ` 2 `
    | ***Quarter*** | ` 1 ` | ` 1 `
    
    *+ Some variants of those*

- Encoder Push Buttons

    *Auto-debounces & makes callbacks available*
    
- Mutliplexed Encoders:

    - `74165`
    
    - `4067`
    
    - `4051`
    
    
<!----------------------------------------------------------------------------->

[Documentation]: https://github.com/luni64/EncoderTool/wiki
[Schematics]: extras/Boards
[Examples]: examples


