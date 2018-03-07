/* -------------------------------------------------------------------------
   LEDEffects Library Examples
   LEDEffects is a library for showing fade effects on a single LED.
   Created by Gavin Smalley, March 6th 2018.
   Released into the public domain.

   Example 1 - Breathing LED
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

/*The breath() method takes one optional value:
  1. The value in milliseconds of the total duration of the breath.
     - If not supplied this will be 5454ms which equates to a standard breathing
       rate of 11 breaths per minute.
     - To specify this value from a given breaths per minute call see the slow breaths example.
     - NB: This is a blocking call and takes the number of milliseconds specified to return. */

  //Single Breath
  Serial.println("Standard Breath");
  ledeffect.breath();
  delay (250);

  //Fast Breath
  Serial.print("Fast Breath");
  ledeffect.breath(2000);
  delay (250);

  //Slow Breath
  Serial.println("Slow Breath (5bpm)");
  int duration = 60000 / 5;         //Number of milliseconds in a minute divided by number of breaths per minute.
  ledeffect.breath(duration);
  delay (250);

  //Continuous Breathing will now run in the loop
  Serial.println("Continuous Breathing - reset Arduino to repeat.");
}

void loop()
{
  ledeffect.breath();
}
