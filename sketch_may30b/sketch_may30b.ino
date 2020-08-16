#include <HandleLed.h>

HandleLed ledPin(13);

void setup()
{
	// put your setup code here, to run once:
}

void loop()
{
	ledPin.processLed();
}
