// HW for Lesson 25 - McWhorter Uno R4 Class
// Pushbutton Switch Control of RGB LED - Toggle
// using internal pull-up resistors
// Also have status of RGB LED on LED Matrix
//
// Lori Pfahler
// September 2024

// Needed libraries for LED Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// frame for displaying status of RGB led
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

// RGB LED pins
int redLED = 6;
int greenLED = 5;
int blueLED = 3;
// button pins
int redButton = 13;
int greenButton = 12;
int blueButton = 11;
// variables to track button presses and LED states (on/off)
int redButtonState = HIGH;
int redLastButtonState = HIGH;
int redState = LOW;
int greenButtonState = HIGH;
int greenLastButtonState = HIGH;
int greenState = LOW;
int blueButtonState = HIGH;
int blueLastButtonState = HIGH;
int blueState = LOW;



void setup() {
  // setup LEDs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // setup button switches with internal pull-up resistor
  // NOT PRESSED = HIGH, PRESSED = LOW
  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);

  // start serial monitor and LED Matrix
  Serial.begin(115200);
  matrix.begin();

  // put Letters R, G, B on LED Matrix
  letterR();
  letterG();
  letterB();
  matrix.renderBitmap(frame, 8, 12);

}

void loop() {
  // read current button states
  redButtonState = digitalRead(redButton);
  greenButtonState = digitalRead(greenButton);
  blueButtonState = digitalRead(blueButton);
  
  // change the state of the led if the button was 
  // pressed = lastButtonState==LOW and the current value of 
  // the button is now not pressed = buttonState==HIGH

  // red
  if (redButtonState == HIGH && redLastButtonState == LOW) {
    redState = !redState;
    digitalWrite(redLED, redState); 
    // change status indicator for R
    if (redState == HIGH) {
      onR();
    }
    else {
      offR();
    }
    matrix.renderBitmap(frame, 8, 12);
  }
  // green
  if (greenButtonState == HIGH && greenLastButtonState == LOW) {
    greenState = !greenState;
    digitalWrite(greenLED, greenState);
    // change status indicator for G
    if (greenState == HIGH) {
      onG();
    }
    else {
      offG();
    }
    matrix.renderBitmap(frame, 8, 12);

  }
  // blue
  if (blueButtonState == HIGH && blueLastButtonState == LOW) {
    blueState = !blueState;
    digitalWrite(blueLED, blueState); 
    // change status indicator for B
    if (blueState == HIGH) {
      onB();
    }
    else {
      offB();
    }
    matrix.renderBitmap(frame, 8, 12);
  }

  // reset the last button state variables
  redLastButtonState = redButtonState;
  greenLastButtonState = greenButtonState;
  blueLastButtonState = blueButtonState;

  delay(50);
}

// functions for LED Matrix - Letters R, G, B and 
// on/off indicators for each letter
void letterR(){
  //Letter R
  frame[0][0] = 1;
  frame[0][1] = 1;
  frame[1][0] = 1;
  frame[1][2] = 1;
  frame[2][0] = 1;
  frame[2][1] = 1;
  frame[3][0] = 1;
  frame[3][2] = 1;
  frame[4][0] = 1;
  frame[4][2] = 1;
}

void letterG(){
  // letter G
  frame[0][5] = 1;
  frame[0][6] = 1;
  frame[1][4] = 1;
  frame[2][4] = 1;
  frame[2][6] = 1;
  frame[3][4] = 1;
  frame[3][6] = 1;
  frame[4][5] = 1;
  frame[4][6] = 1;
}

void letterB(){
  // letter B
  frame[0][8] = 1;
  frame[0][9] = 1;
  frame[1][8] = 1;
  frame[1][10] = 1;
  frame[2][8] = 1;
  frame[2][9] = 1;
  frame[3][8] = 1;
  frame[3][10] = 1;
  frame[4][8] = 1;
  frame[4][9] = 1;
}

void onR(){
  //Indicate that R is on
  frame[6][0] = 1;
  frame[6][1] = 1;
  frame[6][2] = 1;
  frame[7][0] = 1;
  frame[7][1] = 1;
  frame[7][2] = 1;
}
void offR(){
  //Indicate that R is off
  frame[6][0] = 0;
  frame[6][1] = 0;
  frame[6][2] = 0;
  frame[7][0] = 0;
  frame[7][1] = 0;
  frame[7][2] = 0;
}

void onG(){
  //Indicate that G is on
  frame[6][4] = 1;
  frame[6][5] = 1;
  frame[6][6] = 1;
  frame[7][4] = 1;
  frame[7][5] = 1;
  frame[7][6] = 1;
}
void offG(){
  //Indicate that G is off
  frame[6][4] = 0;
  frame[6][5] = 0;
  frame[6][6] = 0;
  frame[7][4] = 0;
  frame[7][5] = 0;
  frame[7][6] = 0;
}

void onB(){
  //Indicate that B is on
  frame[6][8] = 1;
  frame[6][9] = 1;
  frame[6][10] = 1;
  frame[7][8] = 1;
  frame[7][9] = 1;
  frame[7][10] = 1;
}
void offB(){
  //Indicate that B is off
  frame[6][8] = 0;
  frame[6][9] = 0;
  frame[6][10] = 0;
  frame[7][8] = 0;
  frame[7][9] = 0;
  frame[7][10] = 0;
}
