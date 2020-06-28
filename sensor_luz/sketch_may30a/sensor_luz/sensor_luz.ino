#define LIGHT 2 // define pint 2 for sensor
const int ledPin = 13;




void setup() {  
  
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(LIGHT, INPUT_PULLUP);// define pin as Input  sensor

}

void loop() {  
  
  int L =digitalRead(LIGHT);// read the sensor 
  
  if(L == 1){
    Serial.println(" light is ON");
    digitalWrite(ledPin, HIGH);
  }else{

     Serial.println("  === light is OFF");
    digitalWrite(ledPin, LOW);
  }
  delay(500);
 // Light LDR Sensor Code by Robojax.com 20180210

}
