// Homework for Lesson 14: 
// Get brightness level from user and apply to an LED
// Show level on LED Matrix as well
// McWhorter Uno R4 Course
// May 2024
// Lori Pfahler

// Needed libraries for LED Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"


// setup variables and LED matrix
ArduinoLEDMatrix matrix;
int greenLED = 9;
int baudRate = 115200;
int brightness;
float calcBright;

void setup() {
  pinMode(greenLED, OUTPUT);
  Serial.begin(baudRate);
  matrix.begin();
}

void loop() {
  Serial.println("Enter your brightness level for the LED (0 (off), 1, 2, ..., 10 (max):");

  while (Serial.available() == 0) {
      // hold until user enters something in serial port/serial receive buffer
  }

  brightness = Serial.parseInt();
  Serial.print("Brightness level is ");
  Serial.println(brightness);

  // only adjust LED if an acceptable level is entered 
  if(brightness >= 0 && brightness <= 10) {
    // calculate nonlinear brightness value - shooting for a range of 0 to 150
    // brightness can go to 255 but not much change in brightness is seen after 150
    // Level 1 = 1.5, Level 2 = 6, Level 3 = 13.5, ...,Level 9 = 121.5, Level 10 = 150
    calcBright = 1.5 * pow(brightness, 2);
    // write LED to user's entered brightness level
    analogWrite(greenLED, int(calcBright));
    // print brightness level to the led matrix
    matrix.beginDraw();
    matrix.clear();
    matrix.textFont(Font_5x7);
    matrix.beginText(1, 1, 255, 0, 0);
    matrix.println(brightness);
    matrix.endText();
    matrix.endDraw();
  }
  else {
    // inform the user that they have not entered a valid brightness level
    Serial.println("Invalid Brightness Level - Please try again.");
    // turn LED off
    analogWrite(greenLED, 0);
    // clear LED matrix
    matrix.beginDraw();
    matrix.clear();
    matrix.endDraw();
  }

}
