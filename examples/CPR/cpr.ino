/* -------------------------------------------------------------------------
   LEDEffects Library Examples
   LEDEffects is a library for showing fade effects on a single LED.
   Created by Gavin Smalley, March 6th 2018.
   Released into the public domain.

   Example 3 - Multiple Effects on different the same LED.
     Requires an LED (and appropriate resistor) on pin 9.
   ------------------------------------------------------------------------- */

#include <LEDEffects.h>

/*The constructor takes three values:
  1. The pin number of the LED (must be a PWM pin)
     - So long as they are on different pins there can be as many LEDs involved as possible
  2. The minimum desired brightness (default is 0)
  3. The maximum desired brightness (on an Arduino this can't be higher than
     255, on an ESP8266 the maximum is 1023). It defaults to 255. */

LEDEffect ledeffect(9, 5, 255);

  /*CPR
      5 heartbeats followed by 3 long breaths, repeated.
      These values can be adjusted here */

  int numberBreaths = 3;
  int breathDuration = 333;         //Three breaths per second.
  int numberHeatBeats = 5;
  int heartRate = 85;

void setup()
{
}

void loop()
{
  /*The heartbeat method takes three optional values:
    1. The number of beats to flash (defaults to 1).
       - If using the second value then for the best visual effect this one should be
         divisible by that.
    2. The number of beats to group together (defaults to 1).
       - Setting this to 2, for example, will group the beats in pairs.
       - Setting to 3 will group them in threes, etc.
    3. The heartrate in beats per minute (defaults to 60).
       - NB: This is a blocking call, it will return only after (60000/heartrate) milliseconds. */

  ledeffect.heartbeat(numberHeatBeats, 1, heartRate);

  /*The breathe method takes one optional value:
    1. The value in milliseconds of the total duration of the breath.
       - If not supplied this will be 5454ms which equates to a standard breathing
         rate of 11 breaths per minute.
       - To specify this value from a given breaths per minute call see the slow breaths example.
       - NB: This is a blocking call and takes the number of milliseconds specified to return. */

  for (int i = 0; i < numberBreaths; i++) {
    ledeffect.breathe(breathDuration);
  }
}
