Manually operated encoders typically generate a quadrature output which consists of two rectangular signals which are phase shifted by 90°.
<br><br>
<img src="image/quadrature.png" alt="quadrature signal" width=450 >
<br><br>
Each edge of the two phases can be used to generate a count pulse. I.e., one gets 4 counts per signal period. The rotation direction defines if phase A or phase B is leading. 

## Bouncing
The graph shows that at each transition only one signal changes its state. Or, for a mechanical encoder, only one switch is operated at each transition. Counting algorithms take advantage of this fact and, if implemented correctly, provide an absolutely bounce free encoder position. Basically this works since one switch will bounce at the transitions. The other one has a stable state. Thus, the counter automatically interprets the bouncing as rapid up/down counts but, after the bouncing stops it will always end up at the correct position. Libraries like the standard [Encoder library](https://github.com/PaulStoffregen/Encoder) do exactly this.

<br><br>
<img src="image/bounce1.png" alt="bouncing" width=450>
<br><br>

At a first glance it looks like it is necessary to catch all of the bounce pulses to get the correct result. Some libraries use pin change interrupts to catch the bounce pulses. Actually, this is not necessary at all. Here a simple argument: Missing a bounce transition is obviously the same as erasing the transition in the graph above. If you do that and sum up the new +/- 1 steps you will still end up with a total count of +1 after the bouncing.

