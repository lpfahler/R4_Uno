// HW for McWhorter's Uno R4 Course Lesson 29
// Pong Version 4 Using Potentiometer to Move Paddle
// Use "blink without delay" to read potentiometer faster
// than updating the ball position
// random start and directions
// Lori Pfahler
// October 2024

// LED matrix library
#include "Arduino_LED_Matrix.h"
// create matrix object
ArduinoLEDMatrix matrix;

// rows for the paddle, paddleOne can move from row 0 - row 6 in 
// column 0, paddle will be two leds long
int paddleOne = 0;
// paddleOneNew is needed to check if potentiometer has move
// paddleOne location
int paddleOneNew = 0;
int paddleTwo = 1;

// starting frame for LED matrix
byte frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// variables to control position of LED (ball) that is on
// r = row, c = column

int rPosition;
int cPosition;
// random direction of LED in row and column 
int myDirections[2] = {-1, 1};
int rDirection;
int cDirection;

// potentiometer pin and reading variable
int potPin = A0;
int potReading;

// variables to allow potentiometer to move
// faster than the ball, gameplay speed
unsigned long previousMillis = 0;
unsigned long currentMillis;
// interval in ms for game play speed
int interval = 200;

// end game variables
bool gameOver = false;
byte endFrame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
  { 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};


void setup() {
  // setup potentiometer pin
  pinMode(potPin, INPUT);
  // start LED matrix
  matrix.begin();
  // set random seed based on random voltage of analog pin
  randomSeed(analogRead(A1));
  // start ball at a random start but not too close in terms of columns
  // Causes memory errors if you start on an edge and the intial direction
  // is inward - loop will immediately reverse direction and then take the 
  // ball out of the frame - then you get a memory error
  rPosition = random(1, 7);
  cPosition = random(8, 11);
  // random direction of LED in row and column 
  rDirection = myDirections[random(0, 2)];
  cDirection = myDirections[random(0, 2)];
  // Serial.begin(115200);
  // render first paddle position
  frame[paddleOne][0] = 1;
  frame[paddleTwo][0] = 1;
  matrix.renderBitmap(frame, 8, 12);
  delay(1000);
}

void loop() {
  while (gameOver == false) {
    // read potentiometer
    potReading = analogRead(potPin);
    // use only the middle portion of the potentiometer range 
    // (256-768) instead of (0-1023)
    if (potReading <= 256) {
      potReading = 256;
    }
    if (potReading >= 768) {
      potReading = 768;
    }
    paddleOneNew = map(potReading, 256, 768, 0, 6);
    // update paddle position if needed
    if (paddleOne != paddleOneNew) {
        // turn off "old" paddle values
        frame[paddleOne][0] = 0;
        frame[paddleTwo][0] = 0;
        // turn on "new" paddle values
        paddleTwo = paddleOneNew + 1;
        frame[paddleOneNew][0] = 1;
        frame[paddleTwo][0] = 1;
        // reset paddleOne
        paddleOne = paddleOneNew;
    }

    // display frame on led matrix with ball and paddle update
    frame[rPosition][cPosition] = 1;
    matrix.renderBitmap(frame, 8, 12);

    // read current time
    currentMillis = millis(); 

    // only move the ball if timing exceeds game play interval
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      // check for walls and paddle hits - change direction if needed
      if (rPosition <= 0 || rPosition >= 7) {
        rDirection = -rDirection;
      }
      if (cPosition >= 11) {
        cDirection = -cDirection;
      }
      if (cPosition <= 1) {
        if (rPosition == paddleOne || rPosition == paddleTwo) {
          cDirection = -cDirection;
        }
        else {
          gameOver = true;
        }
      }
      // turn off previous LED position
      frame[rPosition][cPosition] = 0;
      // only get a new LED position of the game is NOT over
      if (gameOver == false) {
        // get new LED position
        rPosition = rPosition + rDirection;
        cPosition = cPosition + cDirection;
      }
    }
    // delay for button debouncing
    delay(50);
  }

  // ball is out of play - end game
  // reset and start over
  matrix.renderBitmap(endFrame, 8, 12);
  delay(2000);
  gameOver = false;
  // reset frame to blank
  for (int i = 0; i <= 7; i++) {
    for (int j = 0; j <= 11; j++) {
      frame[i][j] = 0;
    }
  }
  // display paddle
  frame[paddleOne][0] = 1;
  frame[paddleTwo][0] = 1;
  matrix.renderBitmap(frame, 8, 12);

  //reset r and c positions and directions
  // do not start on a boundary
  rPosition = random(1, 7);
  cPosition = random(8, 11);
  rDirection = myDirections[random(0, 2)];
  cDirection = myDirections[random(0, 2)];

  delay(500);
}