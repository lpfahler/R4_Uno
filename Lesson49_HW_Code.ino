// Homework Code for McWhorter's UNO R4 Course - Lesson 49
// Control a Stepper Motor 28BYJ-48 with ULN2003 Controller Module
// Use 4 button switches: two forward 180 degrees and 90 degrees, two reverse 180 and 90 degrees
// I found my motor has 2048 steps per revolution
// Lori Pfahler
// November 2027

#include <Stepper.h>
// 2048 steps to go around a full 360 degrees
int STEPS = 2048; 
int rpm = 15; // this motor can do ~1 to ~15 rpm
// create Stepper object
Stepper stepper(STEPS, 2, 3, 4, 5); // expects this order for pins: IN1, IN3, IN2, IN4

// button switches
int redButton = 11;   
int greenButton = 8; 
int blueButton = A1;   
int yellowButton = A2; 

// interrupt flags
volatile bool redFlag = false;
volatile bool greenFlag = false;
volatile bool blueFlag = false;
volatile bool yellowFlag = false;
int debounceTime = 50;

// Interrupt Serice Routine (ISR) - if button is pressed, set redFlag = true
void redInterrupt() {
      // static allows intital value of zero but will not continue to reset
    unsigned static long prevInterruptTime = 0; 
    unsigned long interruptTime = millis();
  // debounce button switch
  if (interruptTime - prevInterruptTime > debounceTime) {
    redFlag = true;
    prevInterruptTime = interruptTime;
  }
}

// Interrupt Serice Routine (ISR) - if button is pressed, set redFlag = true
void greenInterrupt() {
    unsigned static long prevInterruptTime = 0;
    unsigned long interruptTime = millis();
  // debounce button switch
  if (interruptTime - prevInterruptTime > debounceTime) {
    greenFlag = true;
    prevInterruptTime = interruptTime;
  }
}

// Interrupt Serice Routine (ISR) - if button is pressed, set redFlag = true
void blueInterrupt() {
    unsigned static long prevInterruptTime = 0;
    unsigned long interruptTime = millis();
  // debounce button switchs 
  if (interruptTime - prevInterruptTime > debounceTime) {
    blueFlag = true;
    prevInterruptTime = interruptTime;
  }
}

// Interrupt Serice Routine (ISR) - if button is pressed, set redFlag = true
void yellowInterrupt() {
    unsigned static long prevInterruptTime = 0;
    unsigned long interruptTime = millis();
  // debounce button switch
  if (interruptTime - prevInterruptTime > debounceTime) {
    yellowFlag = true;
    prevInterruptTime = interruptTime;
  }
}
void setup() {
  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);
  // enable interrupts using interrupt service request fuction (ISR) 
  // appropriate button pin
  attachInterrupt(digitalPinToInterrupt(redButton), redInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(greenButton), greenInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(blueButton), blueInterrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(yellowButton), yellowInterrupt, FALLING);

  // set speed of stepper motor
  stepper.setSpeed(rpm);
}


void loop() {
  // go forward 1025 steps (~180 degrees) if red button pressed
  if (redFlag == true) {
    redFlag = false;
    stepper.step(1024);
  }
  // go forward 512 steps (~90 degrees) if green button pressed
  if (greenFlag == true) {
    greenFlag = false;
    stepper.step(512);
  }
    // go backward 1025 steps (~180 degrees) if blue button pressed
  if (blueFlag == true) {
    blueFlag = false;
    stepper.step(-1024);
  }
  // go backward 512 steps (~90 degrees) if yellow button pressed
  if (yellowFlag == true) {
    yellowFlag = false;
    stepper.step(-512);
  }
}
