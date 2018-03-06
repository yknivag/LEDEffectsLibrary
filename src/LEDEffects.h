/*
  LEDEffects.h - Library for showing fade effects on a single LED.
  Created by Gavin Smalley, March 6th 2018.
  Released into the public domain.
*/
#ifndef LEDEffects_h
#define LEDEffects_h

#include "Arduino.h"

class LEDEffect
{
  public:
    LEDEffect(int pin, int pwmMin, int pwmMax);
    void heartbeat(int flashBeats = 1, int groupedAs = 1, int bpm = 60);
    void breathe(int duration = 5454);
  private:
    int _pin;
    int _pwmMin;
    int _pwmMax;
    int _pwmMid;
};

#endif