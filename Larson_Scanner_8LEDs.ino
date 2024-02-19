// Lesson 4 HW Code for Uno R4 Course
// Neat breadboard - Larson Scanner
// Lori Pfahler
// February 2024

// Define variable for delay time
int delayTime = 75;

void setup() {
  // setup pins for LEDs on Pins 5-12
  for (int i = 5; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Go up the line of LEDs 5 to 12
  for (int i = 5; i < 13; i++) {
    digitalWrite(i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
  }

  // Go down the line of LEDs 11 to 6 - starts at 11 and 
  // ends at 6 to avoid repeating LEDs on pins 12 and 5
  for (int i = 11; i > 5; i--) {
    digitalWrite(i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
  }
}
