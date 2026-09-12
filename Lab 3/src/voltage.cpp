#include <Arduino.h>

// function prototype
float voltage(float analogvalue);

// Put your potentiometer pin assignment here
const int sensorPin = A0;

void setup() {
    Serial.begin(115200);
}

void loop() {
    // ajm451 - reads the raw value from the analog input pin and stores it in sensorValue
    int sensorValue = analogRead(sensorPin);
    // ajm451 - uses the voltage function to convert the raw value to the voltage it represents
    float sensorVoltage = voltage(sensorValue);
    Serial.println(sensorVoltage);
    // wait 25ms before reading the new sensor value and repeating the process
    delay(25);
}

// function to calculate output voltage
float voltage(float analogvalue){
    float voltage = analogvalue * 3.3 / 4095;
    //analogRead(sensorPin); gives us 0-4095 values
    //use the formula (Analog value*Reference voltage) / (Sensor Resolution) to calculate the output voltage
    return voltage;
}