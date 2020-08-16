#include <HandleLed.h>

HandleLed handleLed(A0, 13);

void setup()
{
	// put your setup code here, to run once:
}

void loop()
{
	handleLed.handleLed();
}
