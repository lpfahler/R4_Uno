// Homework Code for McWhorter's UNO R4 Course - Lesson 49
// Control a Stepper Motor 28BYJ-48 with ULN2003 Controller Module
// Use bounce2 library to detect and debounce pushbuttons
// Use 4 button switches: two forward 180 degrees and 90 degrees, two reverse 180 and 90 degrees
// I found my motor has 2048 steps per revolution
// Lori Pfahler
// November 2027

#include <Stepper.h>
#include <Bounce2.h>

// button setup
Bounce2::Button redButton = Bounce2::Button();
int redPin = 11; 
Bounce2::Button greenButton = Bounce2::Button();
int greenPin = 8; 
Bounce2::Button blueButton = Bounce2::Button();
int bluePin = A1;  
Bounce2::Button yellowButton = Bounce2::Button();
int yellowPin = A2; 

// stepper setup
int STEPS = 2048; 
int rpm = 15; // this motor can do ~1 to ~15 rpm
// create Stepper object
Stepper stepper(STEPS, 2, 3, 4, 5); // expects this order for pins: IN1, IN3, IN2, IN4

void setup() {
  // pushbuttons - attach it to the pin, set debounce interval
  // set LOW state to indicate button press
  redButton.attach(redPin, INPUT_PULLUP);
  redButton.interval(5);
  redButton.setPressedState(LOW);
  greenButton.attach(greenPin, INPUT_PULLUP);
  greenButton.interval(5);
  greenButton.setPressedState(LOW);
  blueButton.attach(bluePin, INPUT_PULLUP);
  blueButton.interval(5);
  blueButton.setPressedState(LOW);
  yellowButton.attach(yellowPin, INPUT_PULLUP);
  yellowButton.interval(5);
  yellowButton.setPressedState(LOW);
  // set speed of stepper motor
  stepper.setSpeed(rpm);
}


void loop() {
  redButton.update();
  greenButton.update();
  blueButton.update();
  yellowButton.update();
  // go forward 1025 steps (~180 degrees) if red button pressed
  if (redButton.pressed()) {
    stepper.step(1024);
  }
  // go forward 512 steps (~90 degrees) if green button pressed
  if (greenButton.pressed()) {
    stepper.step(512);
  }
  // go backward 1025 steps (~180 degrees) if blue button pressed
  if (blueButton.pressed()) {
    stepper.step(-1024);
  }
  // go backward 512 steps (~90 degrees) if yellow button pressed
  if (yellowButton.pressed()) {
    stepper.step(-512);
  }
}
