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
  for (int n = 1; n <= flashBeats; n++) {
    analogWrite(_pin, _pwmMax);
    delay(shortPeriodTime);
    analogWrite(_pin, _pwmMin);
    delay(shortPeriodTime * 2);
    analogWrite(_pin, _pwmMid);
    for(int fadeValue = _pwmMid; fadeValue >=_pwmMin; fadeValue--) {
      analogWrite(_pin, fadeValue);
      delay(downDelayTime);
    }
    if (n % groupedAs != 0) {
      delay(periodTime);
    }
    else {
      int wait = 0;
      if (groupedAs == 1) {
        wait = (periodTime * 2);
      }
      else {
        wait = (periodTime * 2) + (groupedAs * periodTime);
      }
      delay(wait);
    }
  }
  analogWrite(_pin, 0);
}

void LEDEffect::breath(int duration) {
  int periodTime = duration / 6;
  int upDelayTime = (periodTime * 2) / (_pwmMax - _pwmMin);
  int downDelayTime = (periodTime * 2) / (_pwmMax - _pwmMin);
  for (int i = (_pwmMin - 1); i < _pwmMax; i++) {
    analogWrite(_pin, i);
    delay(upDelayTime);
  }
  for (int j = (_pwmMax - 1); j > _pwmMin; j--) {
    analogWrite(_pin, j);
    delay(downDelayTime);
  }
  delay(periodTime * 2);
  analogWrite(_pin, 0);
}

void LEDEffect::breathe(int breaths, int bpm) {
  groupedBreathe(breaths, 1, bpm);
}

void LEDEffect::breatheDelay(int duration, int bpm) {
  int idealBreathTime = 60000 / bpm;
  int breaths = 1;
  if (idealBreathTime < duration) {
    breaths = duration / idealBreathTime;
  }
  int realBreathTime = duration / breaths;
  for(int i = 0; i < breaths; i++) {
    breath(realBreathTime);
  }
  /* Sometimes the total breathing time will be less than the requested
     duration due to rounding. The following code causes a delay for any under
     run to ensure the method returns in the correct time. */
  int underRun = duration - (realBreathTime * breaths);
  if (underRun > 0) {
    delay(underRun);
  }
}

void LEDEffect::groupedBreathe(int breaths, int groupedAs, int bpm) {
  int breathTime = (60000 / bpm);
  int periodTime = breathTime / 6;
  int upDelayTime = (periodTime * 2)/ (_pwmMax - _pwmMin);
  int downDelayTime = (periodTime * 2)/ (_pwmMax - _pwmMin);
  for (int n = 1; n <= breaths; n++) {
    for (int i = (_pwmMin - 1); i < _pwmMax; i++) {
      analogWrite(_pin, i);
      delay(upDelayTime);
    }
    for (int j = (_pwmMax - 1); j > _pwmMin; j--) {
      analogWrite(_pin, j);
      delay(downDelayTime);
    }
    if (n % groupedAs != 0) {
      delay(periodTime);
    }
    else {
      int wait = 0;
      if (groupedAs == 1) {
        wait = (periodTime * 2);
      }
      else {
        wait = (periodTime * 2) + (groupedAs * periodTime);
      }
      delay(wait);
    }
  }
  analogWrite(_pin, 0);
}

void LEDEffect::flicker(int duration) {
  //If duration isn't speccified it defaults to 0 and we run indefinitely.
  if(duration == 0) {
    while (true) {
      analogWrite(_pin, random(_pwmMin,_pwmMax));
      delay(random(100,200));
    }
  }
  else {
    int endTime = millis() + duration;
    while (millis() <= endTime) {
      int remainingTime = endTime - millis();
      int brigtness = random(_pwmMin,_pwmMax);
      analogWrite(_pin, brigtness);
      if (remainingTime > 200) {
        delay(random(100,200));
      }
      else {
        delay(random(remainingTime));
      }
    }
  }
  analogWrite(_pin, 0);
}
