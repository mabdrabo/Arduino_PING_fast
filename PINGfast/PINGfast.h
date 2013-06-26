/*
    PINGfast.cpp - Library for controling a PING/ultrasonic sensor in a faster way
    Created by Mahmoud Abdrabo, June 26, 2013.
*/
#ifndef PINGfast_h
#define PINGfast_h

#include "Arduino.h"

class PINGfast
{
  public:
    PINGfast(int pin, int max_distance);
    PINGfast(int pin);
    int getCM();
    int getCM(int max_distance);
  private:
    int _pin;
    int _max_distance;
    int _timeout;
};

#endif