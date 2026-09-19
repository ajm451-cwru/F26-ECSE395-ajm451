
#include <ESP32Servo.h>
// Don't forget to include the library!!
// From PlatfromIO library, search for ESP32 servo and add it to the project

// Define the servo and the pin it is connected to, what is your servo pin?
Servo myServo;
const int servoPin = A0;

// Define the minimum and maximum pulse widths for the servo

// ajm451 - changed the min and max pulse widths to 1000 and 1500 respectively, reducing the total range of angles
const int minPulseWidth = 1000; // 0.5 ms
const int maxPulseWidth = 1500; // 2.5 ms

void setup() {
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo

  // ajm451 - changed the PWM frequency, which makes the motion more granular
  myServo.setPeriodHertz(100); // Standard 50Hz servo
}

void loop() {
  // Rotate the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    int pulseWidth;
    // the map function is a puction that maps 0 degrees to 500 pulse width, and 180 degrees to 2500 pulse width
    // map(angle, min angle, max angle, min pulse width, max pulse width)
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);

    // ajm451 - changed the delay to 5 ms, which makes the motor rotate faster
    delay(5);
  }

  // Rotate the servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    int pulseWidth;
    // the map function is a puction that maps 0 degrees to 500 pulse width, and 180 degrees to 2500 pulse width
    // map(angle, min angle, max angle, min pulse width, max pulse width)
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(5);
  }
}