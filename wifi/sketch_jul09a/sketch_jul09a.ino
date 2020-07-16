#include <WiFiEsp.h>
#define RX 10
#define TX 11


#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"

// set up software serial to allow serial communication to our TX and RX pins
SoftwareSerial Serial1(RX, TX);
#endif

// Set  baud rate of so we can monitor output from esp.
#define ESP8266_BAUD 9600
// CHANGE THIS TO MATCH YOUR SETTINGS
char ssid[] = "winterfell";
char pass[] = "dracarys";
int status = WL_IDLE_STATUS;


void setup()
{
  // Open up communications for arduino serial and esp serial at same rate
  Serial.begin(ESP8266_BAUD);
  Serial1.begin(ESP8266_BAUD);

  // Initialize the esp module
  WiFi.init(&Serial1);

  // Start connecting to wifi network and wait for connection to complete
  while (status != WL_CONNECTED)
  {
    Serial.print("Conecting to wifi network: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
  }

  // Once we are connected log the IP address of the ESP module
  Serial.print("IP Address of ESP8266 Module is: ");
  Serial.println(WiFi.localIP());
  Serial.println("You're connected to the network");

}

void loop() {
  // put your main code here, to run repeatedly:

}
