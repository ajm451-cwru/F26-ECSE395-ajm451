#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// pin definitions for the ultrasonic sensor
#define ECHO 12
#define TRIG 13

// line definitions for the bitmap, highline = row all white pixels, lowline = row all black pixels
#define HIGHLINE 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
#define LOWLINE 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

// Declaration for SSD1306 display connected using I2C
// Following lines obtained from Sunfounder website
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Function to read the distance from the ultrasonic sensor
// Obtained from Sunfounder website
float readDistance() {
 digitalWrite(TRIG, LOW);   // Set trig pin to low to ensure a clean pulse
 delayMicroseconds(2);         // Delay for 2 microseconds
 digitalWrite(TRIG, HIGH);  // Send a 10 microsecond pulse by setting trig pin to high
 delayMicroseconds(10);
 digitalWrite(TRIG, LOW);  // Set trig pin back to low

 // Measure the pulse width of the echo pin and calculate the distance value
 float distance = pulseIn(ECHO, HIGH) / 58.00;  // Formula: (340m/s * 1us) / 2
 return distance;
}

// Converts a measured distance from the ultrasonic sensor to a height value for the OLED display
int dist2height(float distance) {
    float maxDistance = 100.0;  // Maximum distance to map to the display height, in centimeters
    return min((int)(64 * distance / maxDistance), 64); // All distances above maxDistance will be mapped to the maximum height
}

// A bitmap to fill the entire OLED display
static unsigned char PROGMEM epd_bitmap_desktop[] = {
	HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE,
    HIGHLINE
};


void setup() {

    // begin the serial communication, used for debugging
    Serial.begin(115200);

    // set pin types for ultrasonic sensor
    pinMode(ECHO, INPUT);
    pinMode(TRIG, OUTPUT);

    // initialize the OLED object
    // obtained from Sunfounder website
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.println(F("SSD1306 allocation failed"));
      for (;;)
        ;
    }

    // Clear the screen buffer
    display.clearDisplay();

    // Fill the screen with white pixels
    display.drawBitmap(0, 0, epd_bitmap_desktop, 128, 64, WHITE);

    // display the image
    display.display();

    // print a debug message to show that setup is complete
    Serial.println("Picture printed");
}

void loop() {

    // Read the distance from the ultrasonic sensor and print to serial register
    float distance = readDistance();  // Call the function to read the sensor data and get the distance
    Serial.print(distance);           // Print the distance value
    Serial.println(" cm");            // Print " cm" to indicate the unit of measurement
  
    // calculate the height of the meter based on the distance measured
    int height = dist2height(distance);

    // Clear the screen buffer
    display.clearDisplay();

    // Draw the bitmap with the updated height
    // When distance measured is larger, height is larger, and the bitmap will be drawn higher up
    display.drawBitmap(0, 64-height, epd_bitmap_desktop, 128, 64, WHITE);

    // Display the updated image
    display.display();

    // Delay for 100 milliseconds before repeating the loop
    delay(100);
}

