# Lab 4 - Actuator Adventures
**Andrew Manteau**

This is the third assignment working with the ESP32. I will be connecting actuators to the ESP32. To upload code to the ESP32, I will be using PlatformIO in VS Code. I am using a Windows laptop.

## Steps

1. Set up the circuit for the TT motor following the schematic.

![TT Motor circuit photo](photos/TT%20Motor%201.jpg)
![TT Motor detail photo](photos/TT%20Motor%202.jpg)

2. Set up the benchtop power supply, set the current limit to 0.15A.

3. Photograph the circuit.

4. Upload the code in "TT Motor.cpp" to the ESP32, observe its movement.

5. Update the values as described in the manual and record findings in this document.

6. Modify "TT Motor Rotate.cpp" to follow the pattern described in the comments and the lab manual. Upload to the ESP32 and observe to check that it worked. Take a video of it working.

7. Create a new file named "TT Motor EC.cpp". Write code here to gradually speed up and slow down the motor continuously. Upload this code and make modifications until the motor spins as expected.

8. Wire the Servo Motor circuit.

![Servo circuit](photos/Servo%201.jpg)
![Servo detail view](photos/Servo%202.jpg)

9. Set the power supply as instructed.

10. Upload "Servo Motor.cpp" to the ESP32 and observe movement.

11. Update and reupload the code as instructed, noting the differences when each parameter is changed.

12. Edit "Servo Motor Random.cpp" to rotate the motor to a random position with a random delay between each movement.

13. Record this movement.

14. Make comments where appropriate.

15. Finish documentation.

16. Push to repo.

## Directory

All motors use A0 as the main output pin.

### TT Motor.cpp

Makes the motor spin for 2 seconds.

### TT Motor EC.cpp

Makes the motor gradually speed up and slow down continuously. The analog value being sent to the motor driver is printed to the serial register.

### TT Motor Rotate.cpp

Makes the motor do the following actions in order:

1. Spin clockwise for 5 sec

2. Stop for 2 sec

3. Spin counterclockwise for 5 sec

4. Stop for 2 sec

5. Repeat from Step 1

Configuration: 

* A0 pin - clockwise motor output
* A1 pin - counterclockwise motor output

### Servo Motor.cpp

Rotate the servo motor back and forth continuously. Variations have been made to several parameters: rotation range, speed, and PWM frequency.

### Servo Motor Rotate.cpp

Rotates the servo motor to a random position between 0-180 degrees. Waits a random period between 150-400 ms between rotations.

## Observations

### TT Motor

* Modifying digitalWrite modulates the speed of rotation; bigger values rotate the motor faster.

* Swapping the values makes the motor rotate in the opposite direction.

* Increasing the delay makes the motor rotate for more time before it stops.

### Servo Motor

* minPulseWidth - When lowered below 500, the motor pauses for a moment when it reaches the 0 degree position. When raised, the starting angle is increased while the max angle stay the same, so the motor rotates slower and in a more limited range of angles.

* maxPulseWidth - Similar to minPulseWidth, but adjusts the max angle instead of the min angle.

* setPeriodHertz - Increasing this value makes the servo change it's position more frequently. Setting it very low makes the servo jump forward, then wait a while before jumping again. In other words, a higher value makes the movement of the servo more granular.

* Rotation range - THe rotation range is edited by changing the min and max pulse widths.

* delay - Decreasing the delay makes the servo rotate back and forth at a faster rate.

## Time Reporting & Reflection

1. This assignment took approximately 2-3 hours to complete.

2. Medium

3. The assignment itself wasn't too difficult to understand. Rather, I had a lot of troubles with getting my computer to connect with the ESP32. I may have a subpar USB-C cable. I was able to fix the issue by changing the communication protocol by adding the following line to "platformio.ini": `upload_flags = --no-stub`. This slowed down the upload process but also made it work every time, which was a very worthwhile tradeoff.

4. I feel quite comfortable with the course content. The labs are still very straightforward and my team is making good progress on our project.

5. N/A