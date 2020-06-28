#include <HandleLDR.h>
#include <Servo.h>

Servo name_servo;

int servo_position = 0;

HandleLDR ledPin(8);

void setup()
{
    name_servo.attach(9);
}

void loop()
{
    ledPin.processLed();

    int lightValue = analogRead(A0);
    lightValue = map(lightValue, 0, 1023, 0, 180);

    name_servo.write(lightValue);
}