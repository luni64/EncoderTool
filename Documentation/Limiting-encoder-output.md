### Limiting encoder output

![limits](/image/limits.png)

You can restrict the encoder values to some arbitrary interval:
```c++
void setup()
{
    encoder.begin(0, 9);
    encoder.setLimits(0, 24);
    \\...
}
```
In this case the encoder will stop counting up if the current value is 9 and stop counting down if its value is 0. If you need cyclic limits, i.e., if you want the value wrap around at the upper or lower bounds you can say e.g.:
```c++
\\...
    encoder.setLimits(1, 12, true);
\\...
```
Now the encoder value will wrap to 1 if your current value is 12 and you count up and it will wrap to 12 if your current value is 1 and you count down.

Those settings are especially useful if you use the encoder to drive some menu system. If the menu has `n` entries you can hard limit the values to `n` or if you prefer use cyclic limits.