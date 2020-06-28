int ledPin = 6;
const int limit = 500;       //set threshold value for dark vs light


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}


void loop() {
  int light = analogRead(A2);
  Serial.println(light);
  delay(5);

  if (light < limit)
  {
    digitalWrite(ledPin, HIGH);
  } else
  {
    digitalWrite(ledPin, LOW);
  }

}
