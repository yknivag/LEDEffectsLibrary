# LED Effects Library
An Arduino/ESP8266 Library which contains a number of LED fade effects.

## Compatability

The library should work with all boards that support analogWrite

NB: At this time the ESP32 is not supported.

## Warning

The effect calls **are blocking**. The board will pause for the entire duration of the effect.

## Wiring

The library expects an LED (and appropriate resistor) at the PWM capable PIN specified at instantiation. For driving many LEDs this could be a transistor/MOSFET at the pin with LEDs downstream from that.

## Features

At this time there are two effects in the library - it is anticipated that this may grow in time although it is deliberately limited to effects possible with a single LED.

### Include

*#include <LEDEffects.h>*

### Constructor

The constructor takes three values:
1. The pin number of the LED (must be a PWM pin)
   - So long as they are on different pins there can be as many LEDs involved as possible
2. The minimum desired brightness (default is 0)
3. The maximum desired brightness (on an Arduino this can't be higher than 255, on an ESP8266 the maximum is 1023). It defaults to 255.

eg *LEDEffect ledeffect(9, 5, 255);*

### heartbeat()

The heartbeat method takes three optional values:
1. The number of beats to flash (defaults to 1).
   - If using the second value then for the best visual effect this one should be divisible by that.
2. The number of beats to group together (defaults to 1).
   - Setting this to 2, for example, will group the beats in pairs.
   - Setting to 3 will group them in threes, etc.
3. The heartrate in beats per minute (defaults to 60).
   - NB: This is a blocking call, it will return only after (60000/heartrate) milliseconds.

### breathe()

The breathe method takes one optional value:
  1. The value in milliseconds of the total duration of the breath.
     - If not supplied this will be 5454ms which equates to a standard breathing
       rate of 11 breaths per minute.
     - To specify this value from a given breaths per minute call see the slow breaths example.
     - NB: This is a blocking call and takes the number of milliseconds specified to return.

## Examples

There are 4 fully commented examples.

### Breathe

Demonstrates the *breathe()* method with a variety of different breathing options one after another and then breathes indefinitely. Outputs to the serial monitor which example is currently being shown.

### Heartbeat

Demonstrates the *heartbeat()* method by cycling through a number of possible patterns. Outputs to the serial monitor which example is currently being shown.

### CPR

Demonstrates how to use both methods together on a single LED.

### TwoLEDs

Demonstrates how to connect two (or more) independently controlled LEDs.  Note that only one will ever be lit at any given time as each call is blocking.
