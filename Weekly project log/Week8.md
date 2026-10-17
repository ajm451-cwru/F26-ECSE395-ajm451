# Lab Notebook - Week 8

**Andrew Manteau**

## Complete Verification/Validation Plans - Oct. 12

We completed our plans for verification and validation. The minutes for this meeting are in the Minutes folder.

The plans developed here will be used when we are finished with our MVP. We'll then be able to test our MVP against our functional and technical specifications and revise as appropriate.

## Begin Connecting to Microphones - Oct. 14

We received our sound sensor and microphone modules and began testing them with the ESP32. Minutes are provided in the Minutes folder.

During this meeting I soldered pins to the microphone module and researched the technical docs and guides so that we could figure out how to connect the ESP32 to the microphone, since it uses digital communication (I2S) rather than just an analog signal.

We also connected the sound sensor to the ESP32 and tested that. The sound sensor is more straightforward to test with compared to the microphone because the sound sensor uses an analog signal.

## Continue Microphone/Sound Sensor Testing for Prototype 2

Martin successfully developed a program that can take input from two sound sensors and display arrows/lines on the screen corresponding to those two directions, drawn based on the signals receiveed from the sound sensors.

The other three of us looked through the documentation on the microphone to figure out how to connect to and read from the microphone. We were successfully able to receive values from the microphone and print them to the serial register, but we will need further testing to make proper sense of these values and use them for sensing.