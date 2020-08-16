/*
  HandleLDR.h - Library to turn on / off a led using an LDR sensor
*/

#ifndef HandleLDR_h
#define HandleLDR_h

#include "Arduino.h"

class HandleLDR
{
public:
	HandleLDR(int ledPin);
	void processLed();

private:
	int _ledPin;
};

#endif