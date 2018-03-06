/* -------------------------------------------------------------------------
   LEDEffects Library Examples
   LEDEffects is a library for showing fade effects on a single LED.
   Created by Gavin Smalley, March 6th 2018.
   Released into the public domain.

   Example 2 - Heartbeat LED
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

void setup()
{
  Serial.begin(115200);
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

  //Single Beat
  Serial.println("Single Beat");
  ledeffect.heartbeat();
  delay (250);

  //Double Beat
  Serial.println("Double Beat");
  ledeffect.heartbeat(2,2);
  delay (250);

  //Fast Beats
  Serial.println("6 Fast Beats (85bpm)");
  ledeffect.heartbeat(6, 1, 85);
  delay (250);

  //Fast Double Beats
  Serial.println("6 Fast Beats (85bpm) Grouped as doubles");
  ledeffect.heartbeat(6, 2, 85);
  delay (250);
}
