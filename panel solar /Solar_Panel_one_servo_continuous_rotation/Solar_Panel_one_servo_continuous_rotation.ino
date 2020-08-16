/*
    Solar Tracker software.
    Analog read of 4 light dependant resistors (LDR)
    and control of two servo motors based on the LDRs values.
*/

#include <Servo.h> //include the software library required to control the servo motors

/*
   Minimum and maximum change in value for which we don't move the
   solar panel in order to avoid vibrations and unnecessary movements
*/
#define THRESHOLD 15

#define DTIME 300 // Number of MILISECONDS between loop executions

// Definition of arduino analog pins that the LDRs are connected to
#define SENSOR_TL 3 //Top Left sensor pin
#define SENSOR_TR 1 //Top Right sensor pin
#define SENSOR_BL 0 //Bottom Left sensor pin
#define SENSOR_BR 2 //Bottom Right sensor pin

#define HORIZ_PIN 9				//Specify connection pin for the horizontal servo
#define HORIZ_LIMIT 180			//Horizontal limit should be the full rotation of a servo
Servo horiz;					//Servo for horizontal movement
int horizpos = HORIZ_LIMIT / 2; //Position value of horizontal servo (half of the limit initial position)

void turnCW();
void turnCCW();
void servoStop();

void setup()
{
	// put your setup code here, to run once:

	Serial.begin(9600); //Enable serial communication with your PC at 9600 baudrate

	//Attach the servo connections. Specifiy what pins to send commands to the servo on.
	horiz.attach(HORIZ_PIN);
}

void loop()
{
	// put your main code here, to run repeatedly:

	int tl = analogRead(SENSOR_TL); //Read the value of the TL sensor
	int tr = analogRead(SENSOR_TR); //Read the value of the TR sensor
	int bl = analogRead(SENSOR_BL); //Read the value of the BL sensor
	int br = analogRead(SENSOR_BR); //Read the value of the BR sensor

	//Average the readings for each side: TOP, BOTTOM, LEFT, RIGHT
	int average_top = (tl + tr) / 2;
	int average_bottom = (bl + br) / 2;
	int average_left = (tl + bl) / 2;
	int average_right = (tr + br) / 2;

	// Uncomment the following code section if you want to send / plot the values of the averages on serial.
	//  Serial.print(average_top);
	//  Serial.print(",");
	//  Serial.print(average_bottom);
	//  Serial.print(",");
	//  Serial.print(average_left);
	//  Serial.print(",");
	//  Serial.print(average_right);
	//  Serial.println();

	//Compute the difference of light between top and bottom / left and right
	int dif_vert = average_top - average_bottom;
	int dif_horz = average_left - average_right;

	if (((-1 * THRESHOLD) <= dif_horz) && (dif_horz <= THRESHOLD))
	{
		//deactivate servo motor because change in value not considerable enough
		servoStop();
	}
	else
	{
		if (average_left > average_right)
		{
			turnCW();
		}
		else if (average_left < average_right)
		{
			turnCCW();
		}
		else if (average_left == average_right)
		{
			servoStop();
		}
	}

	delayMicroseconds(DTIME);
	servoStop();
}

void turnCW()
{
	horiz.write(70);
}

void turnCCW()
{
	horiz.write(110);
}

void servoStop()
{
	horiz.write(90);
}
