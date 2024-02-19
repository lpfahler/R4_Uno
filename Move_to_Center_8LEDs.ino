// Lesson 4 HW Code for Uno R4 Course
// Neat breadboard - Move to Center and Back Out
// Lori Pfahler
// February 2024

// Define variable for delay time
int delayTime = 100;

void setup() {
  // setup pins for LEDs on Pins 5-12
  for (int i = 5; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Go in
  for (int i = 5; i < 9; i++) {
    digitalWrite(i, HIGH);
    digitalWrite(17 - i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
    digitalWrite(17 - i, LOW);
  }

  // Go out
  for (int i = 7; i > 5; i--) {
    digitalWrite(i, HIGH);
    digitalWrite(17 - i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
    digitalWrite(17 - i, LOW);
  }
}
