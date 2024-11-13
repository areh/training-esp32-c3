void setup() {
  // Enable serial output
  Serial.begin(115200);
  // Wait a second
  delay(1000);
  // Set builtin LED to output
  pinMode(LED_BUILTIN, OUTPUT);
  // Output "Hello world!" with a leading linebreak
  Serial.println("\nHello world!");
}

void loop() {
  // Read state of onboard LED and write the opposite
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  // Wait a second
  delay(1000);
}
