// HW for Lessons 22 and 23 - McWhorter Uno R4
// Use potentiometer to control a servo
// Lori Pfahler
// September 2024

// Needed libraries for LED Matrix and servo
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include <Servo.h>

int servoPin = 3;
int potPin = A0;
int servoAngle;
int potReading;
Servo myServo;
int delayTime = 100;
ArduinoLEDMatrix matrix;

void setup() {
  // start serial monitor and LED matrix
  Serial.begin(115200);
  matrix.begin();
  // connect myServo to the servoPin
  myServo.attach(servoPin);
  // setup potentiometer pin
  pinMode(potPin, INPUT);
} 

void loop() {
  potReading = analogRead(potPin);
  // used map function cause I have done the math so
  // many, many, many times!
  servoAngle = map(potReading, 0, 1023, 0, 180);
  // write the appropriate angle to the servo
  myServo.write(servoAngle);
  // print to monitor to check on values
  Serial.print("Pot = ");
  Serial.print(potReading);
  Serial.print("| Angle = ");
  Serial.println(servoAngle);
  // display angle on LED matrix
  matrix.beginDraw();
  matrix.clear();
  matrix.textFont(Font_4x6);
  matrix.beginText(1, 1, 255, 0, 0);
  matrix.println(servoAngle);
  matrix.endText();
  matrix.endDraw();

  delay(delayTime);
}
