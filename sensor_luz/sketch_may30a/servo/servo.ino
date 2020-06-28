#include <Servo.h>
Servo myservo1; // Create a servo object to control the servo
int pos = 0;
void setup()
{
    myservo1.attach(9); //attaches the servo object to PWM pin 9
    Serial.begin(9600);
}
void loop()
{

    int lightValue = analogRead(A0);

    lightValue = map(lightValue, 0, 1023, 0, 180);


    myservo1.write(lightValue);
    Serial.println(lightValue);
    delay(500);
}
