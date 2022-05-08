Manually operated encoders often have mechanical detents to give a tactile feedback to the user. Commonly the detents are placed to be synchronized with one period of the quadrature signal. 

## x4 Type encoders
Most often the detents are placed at rotational positions where both switches are open. 

<br><br>
<img src="image/detent.png" alt="x4 detents" width=350 >
<br><br>

Therefore the standard counting algorithm would return a change of 4 counts between detents. Those encoders are sometimes called x4-type. The advantage of this configuration is that at the stable detent position both switches are open and no current flows through the pull up resistors. The disadvantage is, that you can only use one quarter of the available pulses. 

## x2 Type encoders
One can also find encoders which place their detents at every second count pulse (x2 type). The advantage is the increased resolution, the disadvantage is that at the detent position always one switch is closed. The standard counting algorithm will give increments of 2 between detents. 

<br><br>
<img src="image/detent2.png" alt="x2 detents" width=350 >
<br><br>

## Encoder jittering
Sometimes the detents are placed not *between* the quadrature edges but exactly *at* the edges. Thus, at the detent position the encoder can easily generate jitter pulses. 

<br><br>
<img src="image/detent3.png" alt="x2 detents" width=350 >
<br><br>


Here a cut out of the ALPS EC11 datasheet showing the different detent types: 
<br><br>
<img src="image/alpsEC11.jpg" alt="alps ec11">
<br><br>

The encoders in the left column are x2 type encoders with their detents at stable positions of phase A and phase B. The encoders in the middle column are x2 types where the detents sit on the edge of the phase B. The datasheet explicitly mentions that at the detent position the stability for the B signal can not be guaranteed. 

