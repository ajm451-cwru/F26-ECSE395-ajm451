#include <Arduino.h>

// ajm451 - define easily memorizable shortcuts to refer to the LED and data input pins
#define INPUT_PIN A0
#define LED_PIN 13

void setup() {
    // ajm451 - set the data and LED pins as an input and output, respectively
    pinMode(INPUT_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    // ajm451 - debug line to test behavior of touch sensor
    // ajm451 - found that the output is grounded when not touched, brought to supply voltage if touched
    // Serial.println(analogRead(INPUT_PIN));

    int touchReading = analogRead(INPUT_PIN);

    if (touchReading > 2000) {
        Serial.println("Touch detected!");
        // ajm451 - turn on the LED
        digitalWrite(LED_PIN, HIGH);
    } else {
        Serial.println("No touch detected...");
        // ajm451 - turn off the LED
        digitalWrite(LED_PIN, LOW);
    }
  
    // ajm451 - wait 20ms before repeating
    delay(20); 
}