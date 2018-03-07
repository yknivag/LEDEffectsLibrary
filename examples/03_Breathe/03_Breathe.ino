/* -------------------------------------------------------------------------
   LEDEffects Library Examples
   LEDEffects is a library for showing fade effects on a single LED.
   Created by Gavin Smalley, March 7th 2018.
   Released into the public domain.

   Example 3 - Breathe
     Requires an LED (and appropriate resistor) on pin 9 and also on the
     LEDBUILTIN pin (13 on a standard Uno).
   ------------------------------------------------------------------------- */

#include <LEDEffects.h>

/*The constructor takes three values:
  1. The pin number of the LED (must be a PWM pin)
     - So long as they are on different pins there can be as many LEDs involved as possible
  2. The minimum desired brightness (default is 0)
  3. The maximum desired brightness (on an Arduino this can't be higher than
     255, on an ESP8266 the maximum is 1023). It defaults to 255. */

LEDEffect ledeffect(9, 5, 255);

void setup()
{
}

void loop()
{

  /*The breathe() method takes two optional values:
    1. The value in milliseconds of the total duration of the breath.
       - If not supplied this will be 1.
       - NB: This is a blocking call and takes the entire duration to return.
    2. The breathing rate in breaths per minute.
       - If not specified this defaults to 11 as an average human respiratory rate. */

  breathe(10);      // Ten breaths at the default rate
  breathe(10, 20);  // Ten very fast breaths
  breathe(5, 6);    // Five very slow breaths

/* The groupedBreathe() method takes three optional values:
   1. The number of breaths (defaults to 1).
      - If using the second value then for the best visual effect this one should be divisible by that.
   2. The number of breaths to group together (defaults to 1).
      - Setting this to 2, for example, will group the breaths in pairs.
      - Setting to 3 will group them in threes, etc.
   3. The respiritory rate in breaths per minute (defaults to 11).
      - NB: This is a blocking call, it will return only after ((60000 / bpm) * breaths) milliseconds. */

  groupedBreathe(6);            // Six standard breaths
  groupedBreathe(6, 2);         // Six standard breaths, grouped in pairs.
  groupedBreathe(6, 3, 20);     // Six fast breaths, grouped in threes.
}
