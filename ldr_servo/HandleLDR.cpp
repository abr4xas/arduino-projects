/*
  HandleLDR.cpp - Library to turn on / off a led using an LDR sensor
*/

#include "Arduino.h"
#include "HandleLDR.h"

HandleLDR::HandleLDR(int ledPin)
{
	pinMode(ledPin, OUTPUT);

	_ledPin = ledPin;
}

void HandleLDR::processLed()
{

	int sensorValue = analogRead(A0);

	switch (sensorValue >= 300)
	{
	case true:
		digitalWrite(_ledPin, HIGH);
		break;

	default:
		digitalWrite(_ledPin, LOW);
		break;
	}
}