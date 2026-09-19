
#include <Arduino.h>

// AJM451 - define analog pins for motor control
const int MOTOR_B_1A = A0;
const int MOTOR_B_1B = A1; 

void setup() {
  // ajm451 - set baud rate
  Serial.begin(115200);

  // ajm451 - set motor pins as outputs
  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT); 

  // ajm451 - print to register that setup is done
  Serial.println("Setup done :)");
}

void loop() {
  // --- SECTION 1: Clockwise (5s) ---
  Serial.println("Rotate clockwise for 5 seconds");
  
  // ajm451 - set one pin high so that the motor rotates clockwise
  digitalWrite(MOTOR_B_1A, HIGH);
  digitalWrite(MOTOR_B_1B, LOW);
  
  // ajm451 - wait for 5 seconds
  delay(5000);

  // --- SECTION 2: Stop (2s) ---
  Serial.println("Pause for 2 seconds");
  
  // ajm451 - set pins low so motor stops
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_1B, LOW);

  // ajm451 - wait for 2 seconds
  delay(2000);

  // --- SECTION 3: Counterclockwise (5s) ---
  Serial.println("Rotate counterclockwise for 5 seconds");
  
  // ajm451 - set the other pin high now, so the motor rotates counterclockwise
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_1B, HIGH);

  // ajm451 - wait for 5 seconds
  delay(5000);

  // --- SECTION 4: Stop (2s) ---
  Serial.println("Pause for 2 seconds");
  
  // ajm451 - turn off the motor
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_1B, LOW);

  // ajm451 - wait for 2 seconds
  delay(2000);
}


// Note:
// - Please uncomment the necessary lines and fill in the blank to complete the assignment.
