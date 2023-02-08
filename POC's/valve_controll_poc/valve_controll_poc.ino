/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-water-liquid-valve
 */

// constants won't change
const int RELAY_COLD_PIN = A5;  // the Arduino pin, which connects to the IN pin of relay
const int RELAY_WARM_PIN = A4;  // the Arduino pin, which connects to the IN pin of relay

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin A5 as an output.
  pinMode(RELAY_COLD_PIN, OUTPUT);
  pinMode(RELAY_WARM_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_COLD_PIN, HIGH); // open valve 5 seconds
  delay(500);
  digitalWrite(RELAY_WARM_PIN, LOW); // open valve 5 seconds
  delay(4500);
  digitalWrite(RELAY_COLD_PIN, LOW);  // close valve 5 seconds
  delay(500);
  digitalWrite(RELAY_WARM_PIN, HIGH);  // close valve 5 seconds
  delay(4500);
}
