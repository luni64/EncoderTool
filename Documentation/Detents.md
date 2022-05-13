
[![Banner]][Overview]

<br>

<div align = center>

# Encoders With Detents


*Manually operated encoders often have mechanical detents* <br>
*to give tactile feedback to the user and are usually placed <br>
to be synchronized with one period of the quadrature signal.*

</div>

<br>
<br>

## x4 Type Encoders

Usually the detents are placed at rotational <br>
positions where both switches are open. 

Therefore the standard counting algorithm would <br>
return a change of 4 counts between detents.

Those encoders are sometimes called `x4-type`.

<br>

<img
    src = '../Resources/Image/Detent/A.png'
    title = 'x4 Detents'
    width = 350
/>

<br>

### Pro

At the stable detent position both switches are open <br>
and no current flows through the pull up resistors.

<br>

### Con

You can only use one quarter of the available pulses. 

<br>

---

<br>

## x2 Type Encoders

One can also find encoders which place their <br>
detents at every second count pulse, `x2 Type`.

The standard counting algorithm will <br>
give increments of 2 between detents. 

<br>

<img
    src = '../Resources/Image/Detent/B.png'
    title = 'x2 Detents'
    width = 350
/>

<br>

### Pro

Allows for increased resolution.

<br>

### Con

The detent position is always when one switch is closed.

<br>

---

<br>

## Encoder Jitter

Sometimes the detents are placed not *between* <br>
the quadrature edges but exactly *at* the edges.

Because of that, the detent position the <br>
encoder can easily generate jitter pulses.

<br>

<img
    src = '../Resources/Image/Detent/C.png'
    title = 'x2 Detents'
    width = 350
/>

<br>

In the following you can find a cutout of the `ALPS EC11` <br>
datasheet showing the different detent types available.

<br>

<img
    src = '../Resources/Image/AlpsEC11.jpg'
    title = 'Alps EC11'
    width = 350
/>

<br>

The encoders in the left column are  `x2 Type`  encoders <br>
with their detents at stable positions of phase  ` A `  &  ` B ` .

The encoders in the middle column are  `x2 Type`  encoders <br>
with their detents sitting on the edge of the phase  ` B ` .

The datasheet explicitly mentions that the stability for the<br>
` B `  signal can not be guaranteed at the detent position.


<!----------------------------------------------------------------------------->

[Overview]: Overview.md
[Banner]: ../Resources/Image/Banner/Current.png

