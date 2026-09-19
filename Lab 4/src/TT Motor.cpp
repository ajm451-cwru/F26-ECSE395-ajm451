/*
#include <Arduino.h>

// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = A0; // Replace 0 with your pin number
const int MOTOR_B_1B = A1; // Replace 0 with your pin number
const int speed_min = 100;
int speed = speed_min;
int speeding_up = 1;


void setup() {

  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT); 
  Serial.begin(115200); 

  analogWrite(MOTOR_B_1A, 50);
  analogWrite(MOTOR_B_1B, 255);

  delay(2000);

  analogWrite(MOTOR_B_1A, 0);  
  analogWrite(MOTOR_B_1B, 0);

}

void loop() {
  
}

// Note:
// - Please modify the `analogWrite()`, swap the `analogWrite()`, and modify the `delay()`.
// - You don't have to put anything in the loop.
//      - If you would like to run the code again, please press the `RESET BUTTON` on your ESP32.
*/