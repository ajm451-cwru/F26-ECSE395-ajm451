#include <Arduino.h>
// This is required in PlatformIO but hidden in the standard Arduino IDE.

#define LED_PIN 13

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // AJM451 - define baud rate as suggested in the lab instructions
  Serial.begin(115200); // Start the Serial connection
}

void loop() {
  // AJM451 - print a custom message to the serial monitor
  Serial.println("Hello Feather -Andrew"); // Print the words to the Serial Monitor.
  
  // AJM451 - set the blink pattern to do a flashy blink, see the video in Lab 2 folder for the output
  digitalWrite(LED_PIN, HIGH); // LED On
  delay(250); // Speed in milliseconds
  digitalWrite(LED_PIN, LOW); // LED Off
  delay(250); // Speed in milliseconds
  digitalWrite(LED_PIN, HIGH); // LED On
  delay(50); // Speed in milliseconds
  digitalWrite(LED_PIN, LOW); // LED Off
  delay(50); // Speed in milliseconds
  digitalWrite(LED_PIN, HIGH); // LED On
  delay(50); // Speed in milliseconds
  digitalWrite(LED_PIN, LOW); // LED Off
  delay(50); // Speed in milliseconds
}