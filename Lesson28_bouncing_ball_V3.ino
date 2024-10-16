// Homework for Lesson 28 McWhorter Uno R4 Course
// Bouncing Ball Version 3
// random starting point and random directions
// potentiometer to control speed
// October 2024
// Lori Pfahler

// LED matrix library
#include "Arduino_LED_Matrix.h"

// create matrix object
ArduinoLEDMatrix matrix;

// variables to control position of LED that is on
// r = row, c = column
int rPosition;
int cPosition;
// direction of LED in row and column 
int rDirection;
int cDirection;
// array containing the two directions that the LED can
// be going
int myDirections[2] = {-1, 1};

// starting frame for LED matrix
uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// potentiometer pin and related variables
int potPin = A0;
int speed;
int potReading;

void setup() {
  // setup potentiometer pin
  pinMode(potPin, INPUT);
  // start LED matrix
  matrix.begin();
  // set random starting position of LED for r and c
  // but do not start on a boundary
  rPosition = random(1, 7);
  cPosition = random(1, 11);
  // get a random starting direction for r and c directions
  rDirection = myDirections[random(0, 2)];
  cDirection = myDirections[random(0, 2)];
  Serial.begin(115200);
}

void loop() {
  // read potentiometer to set speed (10 to 500ms)
  potReading = analogRead(potPin);
  speed = map(potReading, 0, 1023, 500, 10);
  Serial.print("Speed = ");
  Serial.print(speed);
  Serial.println("ms");
  // turn on LED
  frame[rPosition][cPosition] = 1;
  matrix.renderBitmap(frame, 8, 12);
  // set speed
  delay(speed);
  // move LED to next position
  // determine if LED has "hit a wall" - if yes
  // change direction for both r and c
  if (rPosition == 0 || rPosition == 7) {
    rDirection = -rDirection;
  }
  if (cPosition == 0 || cPosition == 11) {
    cDirection = -cDirection;
  }
  // turn off previous LED position
  frame[rPosition][cPosition] = 0;
  // get new LED position
  rPosition = rPosition + rDirection;
  cPosition = cPosition + cDirection;

}
