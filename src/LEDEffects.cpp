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
    for(int fadeValue = _pwmMid; fadeValue >=_pwmMin; fadeValue--) {
      analogWrite(_pin, fadeValue);
      delay(downDelayTime);
    }
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

void LEDEffect::breath(int duration) {
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
  analogWrite(_pin, 0);
}

void LEDEffect::breathe(int breaths, int bpm) {
  int breathTime = (60000 / bpm);
  for(i = 0; i < breaths; i++) {
    breath(breathTime);
  }
}

void LEDEffect::breatheDelay(int duration, int bpm) {
  int idealBreathTime = 60000 / bpm;
  int breaths = 1;
  if (idealBreathTime < duration) {
    breaths = duration % idealBreathTime;
  }
  int realBreathTime = duration / breaths;
  for(int i = 0; i < breaths; i++) {
    breath(realBreathTime);
  }
}

void LEDEffect::groupedBreathe(int breaths, int groupedAs, int bpm) {
  int breathTime = (60000 / bpm);
  int periodTime = breathTime / 7;
  int upDelayTime = (periodTime * 2)/ (_pwmMax - _pwmMin);
  int downDelayTime = (periodTime * 3)/ (_pwmMax - _pwmMin);
  for (int n = 0; n < breaths; n++) {
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
      int wait = (periodTime * 2) + (groupedAs * periodTime);
      delay(wait);
    }
  }
  analogWrite(_pin, 0);
}
