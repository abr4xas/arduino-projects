int sensor_pin = A0;
int output_value ;
int thresholdValue = 867;

void setup() {
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop() {

  output_value = analogRead(sensor_pin);
  // we will map the output values to 0-100 because the moisture is measured in percentage.
  // When we took the readings from the dry soil, the sensor value was 867, and in the wet soil,
  // the sensor value was 532. We mapped these values to get the moisture.
  // After that, we printed these values on the serial monitor.
  //output_value = map(output_value, thresholdValue, 532, 0, 100);
  Serial.print("Mositure : ");
  Serial.print(output_value);
  //Serial.println("%");

  if (output_value < thresholdValue) {
    Serial.println(" - Doesn't need watering");
  }
  else {
    Serial.println(" - Time to water your plant");
  }
  delay(1000);
}
