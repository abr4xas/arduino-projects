// These constants won't change:
const int sensorPin = A0; // pin that the sensor is attached to
const int ledPin = 13;	  // pin that the LED is attached to
// variables:
int sensorValue = 0; // the sensor value

void setup()
{
	pinMode(ledPin, OUTPUT);
	pinMode(sensorPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	handleLed();
}

void handleLed()
{

	sensorValue = analogRead(sensorPin);
	Serial.print("Analog read: ");
	Serial.println(sensorValue);

	if (sensorValue >= 300)
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		//else, it is bright, turn pin 9 LOW
		digitalWrite(ledPin, LOW);
	}
	delay(200);
}
