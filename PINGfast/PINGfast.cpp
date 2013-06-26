/*
  	PINGfast.cpp - Library for controling a PING/ultrasonic sensor in a faster way
  	Created by Mahmoud Abdrabo, June 26, 2013.
	

	Constructor Parameters

	pin 			Arduino digital pin for the sensor
	max_distance 	max desired distanced to be sensed (in centimeters)


	getCM function

	returns distance in centimeters and -1 if nothing sensed within max_distance	
	
*/

#include "Arduino.h"
#include "PINGfast.h"

PINGfast::PINGfast(int pin, int max_distance)
{
  _pin = pin;
  _max_distance = max_distance;
  _timeout = _max_distance * 29 * 2;
}

PINGfast::PINGfast(int pin)
{
  _pin = pin;
  _max_distance = 400;
  _timeout = 23200;		//  400 cm
}

int PINGfast::getCM()
{
	getCM(_max_distance);
}

int PINGfast::getCM(int max_distance)
{
	int timeout = max_distance * 29 * 2;
	pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(_pin, LOW);
    pinMode(_pin, INPUT);
    int duration = pulseIn(_pin, HIGH, timeout);
    if (duration <= 50)
	{
		return -1;
	}
	else
	{
		return int(duration / 29 / 2);
	}
}