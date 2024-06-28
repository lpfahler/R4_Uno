// HW for Lesson 19 - McWhorter's Uno R4 Class
// Flash RGB LED a user entered number times
// Lori Pfahler
// June 2024

// Needed libraries for LED Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int numCycles;
int delayTime = 250;
ArduinoLEDMatrix matrix;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(115200);
  matrix.begin();
}

void rgbLED(int redPinNum, int greenPinNum, int bluePinNum, int red, int green, int blue) {
  // function to light an rgb led - assuming pinMode has been called
  // and connected to pins that allow PWM
  analogWrite(redPinNum, red);
  analogWrite(greenPinNum, green);
  analogWrite(bluePinNum, blue);
}

void loop() {
  Serial.println("Please enter the number of R, G, B cycles you wish (i.e. 1, 2, 3, ..., max 25)");
  while(Serial.available()==0) {
    // wait for user input
  }
  numCycles = Serial.parseInt();

  // only allow 1-25 for the number of cycles
  if (numCycles > 25) {
    numCycles = 25;
    Serial.print("Too many cycles requested; ");

  }
  if (numCycles <= 0){
    numCycles = 1;
    Serial.print("Too few cycles requested; ");
  }

  Serial.print("The number of cycles is set to ");
  Serial.println(numCycles);

  // loop through numCycles
  for (int i = 1; i <= numCycles; i++){
    // display count on LED matrix
    matrix.beginDraw();
    matrix.clear();
    matrix.textFont(Font_5x7);
    matrix.beginText(1, 1, 255, 0, 0);
    matrix.println(i);
    matrix.endText();
    matrix.endDraw();
    // do an R, G, B cycle of the LED
    rgbLED(redPin, greenPin, bluePin, 255, 0, 0);
    delay(delayTime);
    rgbLED(redPin, greenPin, bluePin, 0, 255, 0);
    delay(delayTime);
    rgbLED(redPin, greenPin, bluePin, 0, 0, 255);
    delay(delayTime);  
    // turn LED off and delay a bit longer for visual separation of cycles
    rgbLED(redPin, greenPin, bluePin, 0, 0, 0);
    delay(delayTime + 500);  
  }
  // clear matrix - just using clear() doesn't seem to work anymore
    matrix.beginDraw();
    matrix.clear();
    matrix.textFont(Font_5x7);
    matrix.beginText(1, 1, 255, 0, 0);
    matrix.println("  ");
    matrix.endText();
    matrix.endDraw();
}
