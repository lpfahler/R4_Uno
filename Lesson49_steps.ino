// Class Code for McWhorter's UNO R4 Course - Lesson 49
// Control a Stepper Motor 28BYJ-48 with ULN2003 Controller Module
// Determine if number of steps is 2038 or 2048
// Lori Pfahler
// November 2027

#include <Stepper.h>
// 2048 steps to go around a full 360 degrees
int STEPS = 2048; 
int rpm = 15; // this setup can do ~1 to ~15 rpm
// create Stepper object
Stepper stepper(STEPS, 2, 3, 4, 5); // expects this order for pins: IN1, IN3, IN2, IN4

void setup() {
  Serial.begin(115200);
  // delay to mark starting point
  delay(10000);
}

void loop() {
  // go forward one revolution at 15rpm
  for (int i = 0; i < 100; i++) {
    stepper.setSpeed(rpm);
    stepper.step(STEPS);
    Serial.println(i);
    delay(1000);
  }
}
