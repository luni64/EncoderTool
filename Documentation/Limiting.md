
# Limiting Encoder Output

*You can restrict encoder values to arbitrary intervals.*

<br>

![Limits]

<br>

## Interval

You can set the limits interval with:

```C++
setLimit( <Minimum> , <Maximum> );
```

This is equivalent to:

```
Minimum ≤ Values ≤ Maximum
```

<br>

## Example

```C++
void setup(){
    encoder.begin(0,9);
    encoder.setLimits(0,24);
    ...
}
```

<br>

## Cycling Limits

If you want your interval to wrap around, simply write:

```C++
setLimits( <Minimum> , <Maximum> , true );
```

<br>

## Application

A common example application would be a menu with `n` <br>
menu items, in which case you could use a range of `0 - n`.


<!----------------------------------------------------------------------------->

[Limits]: ../Resources/Image/Limits.png