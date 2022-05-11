
# Quadrature Signals

Manually operated encoders typically generate a <br>
quadrature output consisting of two rectangular <br>
signals which are phase shifted by `90°` .

<br>

<img 
    src = '../Resources/Image/Quadrature.png' 
    title = 'quadrature signal' 
    width = 450 
/>

<br>

Each edge of the two phases can be used to generate a count pulse. <br>
**⤷** `4 Counts / Period`

   *The direction of the rotation defines what phase is leading.*

<br>

---

<br>



# Bouncing

The graph shows that at each transition:

| Type                    | Observation
|:-----------------------:|:-----------
| <kbd>    Digital    </kbd> | Only one signal changes its state
| <kbd> Mechanical </kbd> | Only one switch is operated 

<br>
<br>

<img 
    src = '../Resources/Image/Bounce.png' 
    title = 'Bouncing Signal'
    width = 450 
/>

<br>

## Uses

Counting algorithms take advantage of this fact and can <br>
thus provide absolutely bounce free encoder position, if <br>
implemented correctly.

Libraries like the standard [Encoder library] do exactly this.

<br>

## Interpretation

Basically this works as one switch will always bounce <br>
at the transition while the other has a stable state.

Because of this, the counter automatically interprets <br>
the bouncing as rapid up / down counts but after the <br>
bouncing stops it will always end up at the correct position.

<br>

## Clarification

At first glance it may look like it would be necessary to <br>
catch every bounce pulse to determine the correct result.

Despite some libraries using pin change interrupts <br>
to catch them, this is in fact not actually necessary.

### Example

Missing a bounce transition is the same as <br>
erasing the transition in the above graph.

Thus if you were to sum up the new `±1` sequence <br>
you'd still end up with the same result as before.


<!---------------------------------------------------------------->

[Encoder Library]: https://github.com/PaulStoffregen/Encoder
