/*
  LEDEffects.cpp - Library for showing fade effects on a single LED.
  Created by Gavin Smalley, March 6th 2018.
  Released into the public domain.
*/
#include "Arduino.h"
#include "LEDEffects.h"

LEDEffect::LEDEffect(int pin, int pwmMin = 5, int pwmMax = 255) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _pwmMax = pwmMax;
  _pwmMin = pwmMin;
  _pwmMid = _pwmMin + ((_pwmMax - _pwmMin) / 2);
}

void LEDEffect::heartbeat(int flashBeats, int groupedAs, int bpm) {
  int periodTime = ((60000 / bpm) / 6);
  int shortPeriodTime = periodTime / 3;
  int downDelayTime = (periodTime * 2) / (_pwmMid - _pwmMin);
  for (int i = 0; i < flashBeats; i += 1) {
    analogWrite(_pin, _pwmMax);
    delay(shortPeriodTime);
    analogWrite(_pin, _pwmMin);
    delay(shortPeriodTime * 2);
    analogWrite(_pin, _pwmMid);

    //fade out from half to min in increments of 5 points:
    for(int fadeValue = _pwmMid; fadeValue >=_pwmMin; fadeValue--) {
      analogWrite(_pin, fadeValue);
      //wait for 20 milliseconds to see the dimming effect
      delay(downDelayTime);
    }
    //short delay to make up 1000 milli-seconds (60 bpm)
    if (i % groupedAs != 0) {
      delay(periodTime);
    }
    else {
      int wait = (periodTime * 2) + (groupedAs * periodTime);
      delay(wait);
    }
  }
  analogWrite(_pin, 0);
}

//5454ms gives a breath rate of 11 breaths per minute if called continuously
void LEDEffect::breathe(int duration) {
  int periodTime = duration / 7;
  int upDelayTime = (periodTime * 2)/ (_pwmMax - _pwmMin);
  int downDelayTime = (periodTime * 3)/ (_pwmMax - _pwmMin);
  for (int i=(_pwmMin - 1); i<_pwmMax; i++) {
    analogWrite(_pin, i);
    delay(upDelayTime);
  }
  for (int j=(_pwmMax - 1); j>_pwmMin; j--) {
    analogWrite(_pin, j);
    delay(downDelayTime);
  }
  delay(periodTime * 2);
}

