/* -------------------------------------------------------------------------
   LEDEffects Library Examples
   LEDEffects is a library for showing fade effects on a single LED.
   Created by Gavin Smalley, March 7th 2018.
   Released into the public domain.

   Example 4 - Breathe Delay
     Requires an LED (and appropriate resistor) on pin 9 and also on the
     LEDBUILTIN pin (13 on a standard Uno).

     The example is simply a copy of the delay() example sketch.  This is not
     an ideal demostration, but it covers the syntax. A real-life example may
     be for instance breathing an LED for a given time whilst a motor is
     running or whilst a door catch is being held open etc.
   ------------------------------------------------------------------------- */

#include <LEDEffects.h>

/*The constructor takes three values:
  1. The pin number of the LED (must be a PWM pin)
     - So long as they are on different pins there can be as many LEDs involved as possible
  2. The minimum desired brightness (default is 0)
  3. The maximum desired brightness (on an Arduino this can't be higher than
     255, on an ESP8266 the maximum is 1023). It defaults to 255. */

LEDEffect ledeffect(9, 5, 255);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

/* The breatheDelay() method takes one mandatory and one optional values:
   1. The value in milliseconds of the total duration of the delay required.
      - NB: This is a blocking call and takes the entire duration to return.
   2. The breathing rate in breaths per minute.
      - If not specified this defaults to 11 as an average human respiratory rate. */

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  ledeffect.breatheDelay(12000, 12);                // wait for 12 seconds (breathing the second LED)
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  ledeffect.breatheDelay(6000, 6);             // wait for 6 seconds (breathing the second LED) (we use a lower respiration rate this time.
}
