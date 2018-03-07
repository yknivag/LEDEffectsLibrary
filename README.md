# LED Effects Library

An Arduino/ESP8266 Library which contains a number of LED fade effects.  Please note that this will **not** work on the ESP32 as it doesn't support the *analogWrite()* command.

## Compatability

The library should work with all boards that support analogWrite

NB: At this time the ESP32 is not supported.

## Warning

The effect calls **are blocking**. The board will pause for the entire duration of the effect.

## Wiring

The library expects an LED (and appropriate resistor) at the PWM capable PIN specified at instantiation. For driving many LEDs this could be a transistor/MOSFET at the pin with LEDs downstream from that.

## Features

At this time there are five effects in the library - it is anticipated that this may grow in time although it is deliberately limited to effects possible with a single LED.

##Usage

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

*void heartbeat(int flashBeats = 1, int groupedAs = 1, int bpm = 60);*

The heartbeat() method takes three optional values:
1. The number of beats to flash (defaults to 1).
   - If using the second value then for the best visual effect this one should be divisible by that.
2. The number of beats to group together (defaults to 1).
   - Setting this to 2, for example, will group the beats in pairs.
   - Setting to 3 will group them in threes, etc.
3. The heartrate in beats per minute (defaults to 60).
   - NB: This is a blocking call, it will return only after ((60000 / bpm) * beats) milliseconds.

### breath()

*void breath(int duration = 5454);*

The breath() method takes one optional value:
1. The value in milliseconds of the total duration of the breath.
   - If not supplied this will be 5454ms which equates to a standard breathing rate of 11 breaths per minute.
   - To specify this value from a given breaths per minute call see the slow breaths example.
   - NB: This is a blocking call and takes the number of milliseconds specified to return.

### breathe()

*void breathe(int breaths = 1, int bpm = 11);*

Distinct from *breath()* in that it takes a number of breaths and breath rate as opposed to just outputting a single breath. **Note this is still a blocking function and will block for as long as it is active.** If you wish to do something between breaths then use *breath()*. The "Slow Breath" code in the "Breath" example shows how to do this for a given respiratory rate.

The breathe() method takes two optional values:
1. The value in milliseconds of the total duration of the breath.
   - If not supplied this will be 1.
   - NB: This is a blocking call and takes the entire duration to return.
2. The breathing rate in breaths per minute.
   - If not specified this defaults to 11 as an average human respiratory rate.

### groupedBreathe()

*void groupedBreathe(int breaths = 1, int groupedAs = 1, int bpm = 11);*

The groupedBreathe() method takes three optional values:
1. The number of breaths (defaults to 1).
   - If using the second value then for the best visual effect this one should be divisible by that.
2. The number of breaths to group together (defaults to 1).
   - Setting this to 2, for example, will group the breaths in pairs.
   - Setting to 3 will group them in threes, etc.
3. The respiritory rate in breaths per minute (defaults to 11).
   - NB: This is a blocking call, it will return only after ((60000 / bpm) * breaths) milliseconds.

### breatheDelay()

*void breatheDelay(int duration, int bpm = 11);*

Designed to provide visual feedback to the user during long *delay()* statements this method takes 1 mandatory and 1 optional parameter. The code is designed such that it will always wait for the time specified and will adjust (if necessary) the bpm slightly to ensure that only full breaths are shown. The delays and breaths shown may be subject to slight rounding errors.

The breatheDelay() method takes one mandatory and one optional values:
1. The value in milliseconds of the total duration of the delay required.
   - NB: This is a blocking call and takes the entire duration to return.
2. The breathing rate in breaths per minute.
   - If not specified this defaults to 11 as an average human respiratory rate.

## Examples

There are 6 fully commented examples.

### Heartbeat

Demonstrates the *heartbeat()* method by cycling through a number of possible patterns. Outputs to the serial monitor which example is currently being shown.

### Breath

Demonstrates the *breath()* method with a variety of different breathing options one after another and then breathes indefinitely. Outputs to the serial monitor which example is currently being shown.

### Breathe

Demonstrates both *breathe()* and *groupedBreathe()* alternatively in a variety of patterns.

### BreatheDelay

A very simple example, this is a slow version of the blink sketch using *breatheDelay()* instead of *delay()*. It requires 2 LEDs, one to blink and one to breathe. This is not an ideal demostration, but it covers the syntax. A real-life example may be for instance breathing an LED for a given time whilst a motor is running or whilst a door catch is being held open etc.

### CPR

Demonstrates how to use the breathe and heartbeat methods together on a single LED.

### TwoLEDs

Demonstrates how to connect two (or more) independently controlled LEDs.  Note that only one will ever be lit at any given time as each call is blocking.
