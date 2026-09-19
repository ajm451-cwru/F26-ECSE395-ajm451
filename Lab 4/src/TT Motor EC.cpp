
#include <Arduino.h>

// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = A0; // Replace 0 with your pin number
const int MOTOR_B_1B = A1; // Replace 0 with your pin number

// ajm451 - the minimum value to be written to the motor pin, because the motor stops completely at most values smaller than 100
const int speed_min = 100;

// ajm451 - initialize the speed to the minimum value
int speed = speed_min;

// ajm451 - boolean variable to determine whether we are speeding up or slowing down
int speeding_up = 1;


void setup() {

    // ajm451 - set motor pins as outputs
    pinMode(MOTOR_B_1A, OUTPUT);
    pinMode(MOTOR_B_1B, OUTPUT); 

    // ajm451 - set baud rate for serial communication
    Serial.begin(115200); 

}

void loop() {
    // ajm451 - print current speed to serial monitor
    Serial.println(speed);

    // ajm451 - write the new speed to the motor pin
    analogWrite(MOTOR_B_1A, speed);

    // ajm451 - wait 50 ms
    delay(50);

    // ajm451 - determine the new speed based on whether we are speeding up or slowing down
    if (speeding_up == 1) {
        if (speed >= 255) {
            // ajm451 - start slowing down if we reach the maximum speed
            speeding_up = 0;
        } else {
            speed += 5;
        }
    } else {
        if (speed <= speed_min) {
            // ajm451 - start speeding up if we reach the minimum speed
            speeding_up = 1;
        } else {
            speed -= 5;
        }
    }
}

// Note:
// - Please modify the `analogWrite()`, swap the `analogWrite()`, and modify the `delay()`.
// - You don't have to put anything in the loop.
//      - If you would like to run the code again, please press the `RESET BUTTON` on your ESP32.
