#define LIGHT_SENSOR_PIN 36 // ESP32 pin GPIO36 (ADC0)

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 bits per second
}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN); // Read ADC value
  float voltage = analogValue * (3.3 / 4095.0); // Correctly convert ADC to voltage assuming 3.3V max
  float lux = analogValue * (286 / 1150.0); // Calibrated conversion factor based on your data

  Serial.print("Analog Value = ");
  Serial.print(analogValue);   // Print the raw ADC reading
  Serial.print(" Voltage = ");
  Serial.print(voltage, 3);    // Print the calculated voltage
  Serial.print(" Lux = ");
  Serial.println(lux, 2);      // Print the calculated lux value

  delay(500);                  // Delay between reads
}
