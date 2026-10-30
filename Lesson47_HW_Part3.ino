// HW Code PART 3 for McWhorter's UNO R4 Course - Lesson 47
// Control a DC Motor a with TA6586 Motor Controller
// button switch: to switch direction 
// potentiometer: to set the speed
// Use hardware interrupt to detect button press
// Use LED Matrix to show direction
// 
// Lori Pfahler
// October 2027

// LED matrix libraries
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// create matrix object
ArduinoLEDMatrix matrix;

// motor driver variables
int BI = 6;
int FI = 5;
int motorSpeed;

// potentiometer variables
int potPin = A0;
int potReading;

// button variables - use hardware interrupt available on pin 2
int buttonPin = 2;
volatile unsigned long prev_interrupt_time = 0;
volatile bool changeDirection = false;
char direction = 'F';

// Interrupt Serice Routine (ISR) - if button is pressed, set changeDirection to true
void buttonInterrupt() {
    unsigned long interrupt_time = millis();
  // debounce button switch - change LEDState only if 200ms 
  // has passed since the last trigger
  if (interrupt_time - prev_interrupt_time > 200) {
    changeDirection = true;
    prev_interrupt_time = interrupt_time;
  }
}

// assume FI and BI are defined pins for TA6586
// direction should be 'F' for forward; 'R' for reverse
// speed should be 0 - 255
void motor(char direction, int speed) {
  // if speed is < 50 - turn motor off
  if (speed < 50) {
    analogWrite(FI, 0);
    analogWrite(BI, 0);
  }
  // go forward at speed
  if (direction =='F' && speed >= 50) {
    analogWrite(FI, 0);
    analogWrite(BI, speed);
  }
  // go backward at speed
  if (direction =='R' && speed >= 50) {
    analogWrite(FI, speed);
    analogWrite(BI, 0);
  }
}



void setup() {
  // start matrix
  matrix.begin();
  // pinModes
  pinMode(BI, OUTPUT);
  pinMode(FI, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  // enable interrupt using buttonInterrupt fuction (ISR) and attach to buttonPin
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, FALLING);
  // print initial direction to matrix
  matrix.beginDraw(); 
  matrix.clear();
  matrix.textFont(Font_5x7);
  matrix.beginText(1, 1, 255, 0, 0);
  matrix.println(direction);
  matrix.endText();
  matrix.endDraw();
}

void loop() {
  // read potentiometer and determine the motorSpeed
  potReading = analogRead(potPin);
  motorSpeed = map(potReading, 0, 1023, 0, 255);

  // change direction if button has been pressed; turn motor off briefly
  // changeDirection will be set to true by interrupt function
  if (changeDirection == true) {
    // switch it back to false to allow button to be pressed again
    changeDirection = false; 
    // turn motor off and pause 2 seconds
    motor(direction, 0);
    delay(2000);
    // switch direction
    if (direction == 'F') {
      direction = 'R';
    }
    else {
      direction = 'F';
    }
    // print direction change to LED matrix
    matrix.beginDraw(); 
    matrix.clear();
    matrix.textFont(Font_5x7);
    matrix.beginText(1, 1, 255, 0, 0);
    matrix.println(direction);
    matrix.endText();
    matrix.endDraw();
  }

  // set motor direction and speed
  motor(direction, motorSpeed);

}