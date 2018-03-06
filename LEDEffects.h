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
    LEDEffect(int pin);
    void heartbeat();
    void breathe();
  private:
    int _pin;
    int _pwmMin;
    int _pwmMax;
    int _pwmMid;
};

#endif
