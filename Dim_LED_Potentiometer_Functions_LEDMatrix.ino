// HW for Lesson 40 Using Functions
// Create a dimmer for an LED using a Potentiometer
// With LED Matrix animation
// Lori Pfahler
// September 2026

// libraries for LED Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
// create matrix object
ArduinoLEDMatrix matrix;

int redLED = 3;
int potPin = A0;
int potReading;
int delayTime = 100;
float brightness;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  // read potentiometer
  potReading = analogRead(potPin);

  // function to set brightness value with nonlinear equation
  brightness = bright(potReading);

  // analogWrite to redLED the current brightness value
  analogWrite(redLED, brightness);

  // show on led matrix
  drawLED(potReading, matrix);

  // print results to serial monitor
  printResults(potReading, brightness);

  delay(delayTime);
}

// function to determine brightness level for LED
float bright(int reading) {
  float reading100;
  float brightness;
  if (reading < 2) {
    brightness = 0;  // fully off
  } else if (reading > 1000) {
    brightness = 100;  // fully on
  } else {
    // place reading on 0 - 100 scale
    reading100 = (reading / 1023.0) * 100.0;
    // use nonlinear dimming equation
    brightness = pow(100, reading100 / 100);
  }
  return brightness;
}

// function for printing output to serial monitor
void printResults(int reading, float brightness) {
  Serial.print("potReading: ");
  Serial.print(reading);
  Serial.print(", brightness: ");
  Serial.println(brightness);
}

// function for writing to the LED matrix
void drawLED(int reading, ArduinoLEDMatrix& myMatrix) {
  // blank frame
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
  // make level indicator on matrix
  int level = map(reading, 0, 1023, 0, 11);
  Serial.println(level);
  for (int c = 0; c <= level; c++) {
    frame[2][c] = 1;
    frame[3][c] = 1;
    frame[4][c] = 1;
    frame[5][c] = 1;
  }
  myMatrix.renderBitmap(frame, 8, 12);
}
