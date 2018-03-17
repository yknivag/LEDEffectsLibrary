/* -------------------------------------------------------------------------
   LEDEffects Library Examples
   LEDEffects is a library for showing fade effects on a single LED.
   Created by Gavin Smalley, March 7th 2018.
   Released into the public domain.

   Example 7 - Flicker
     Requires an LED (and appropriate resistor) on pin 9.

     In this example the LED will flicker for a few seconds, wait a little
     and then flicker for ever.  This demostrates the two possible syntaxes.
   ------------------------------------------------------------------------- */

#include <LEDEffects.h>

/*The constructor takes three values:
  1. The pin number of the LED (must be a PWM pin)
     - So long as they are on different pins there can be as many LEDs involved as possible
  2. The minimum desired brightness (default is 0)
  3. The maximum desired brightness (on an Arduino this can't be higher than
     255, on an ESP8266 the maximum is 1023). It defaults to 255. */

LEDEffect ledeffect(9, 5, 127);

void setup() {
  /* The flicker() method takes one optional value:
     1. The value in milliseconds of the total duration of the flickering required.
        - If the value is ommitted it will run indefinitely.
        - NB: This is a blocking call and takes the entire duration to return. */

  // In the set up we will run for 3 seconds and then pause for two.
  ledeffect.flicker(3000);
  delay(2000);
  //Now in the flicker forever.
  ledeffect.flicker();
}

// the loop function runs over and over again forever
void loop() {

}
