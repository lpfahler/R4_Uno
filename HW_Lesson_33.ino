// HW for Lesson 33 - Using a Photoresistor
// Use photoresistor to change icon on display
// sun = high light, cloud = medium light, moon = low light
// Lori Pfahler
// October 2024

// LED matrix libraries
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// create matrix object
ArduinoLEDMatrix matrix;

// sun frame for LED matrix
byte sunFrame[8][12] = {
  { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// cloud frame
byte cloudFrame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// moon frame
byte moonFrame[8][12] = {
  { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 }
};

// variables
int photoPin = A0;
// value from photoresistor 
int photoValue;
// variable to check if display needs to be updated
int oldValue = 0;
// calibrate to light in the area
int initialValue;
// set interval to create three differing light levels for action - see below
// adjust as needed
int interval = 100;

void setup() {
  // start matrix
  matrix.begin();
  // setup photoresistor
  pinMode(photoPin, INPUT);
  // read initial value from photoresistor
  initialValue = analogRead(photoPin);
}

void loop() {
  // read photoresistor
  photoValue = analogRead(photoPin);
  // provide bitmap based on photoValue 
  // do not update unless there has been a significant change (+- 10)
  if (photoValue <= (oldValue - 10) || photoValue >= (oldValue + 10)) {
    if (photoValue  <= (initialValue - (2*interval))) {
      matrix.renderBitmap(moonFrame, 8, 12);
    }
    else if (photoValue <=  (initialValue - interval)) {
      matrix.renderBitmap(cloudFrame, 8, 12);   
    }
    else {
      matrix.renderBitmap(sunFrame, 8, 12);
    }
  }
  oldValue = photoValue;
  delay(100);

}


