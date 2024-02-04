// Lesson 2 HW Code for Uno R4 Course
// Blink External LED - SOS
// Lori Pfahler
// January 2024

// Define variables for delay times
int dotDelay = 200;
int dashDelay = 600;
int wordDelay = 1400;


void setup() {
  // setup pin for LED; this one is also the internal LED
  // both will blink
  pinMode(13, OUTPUT);
}

void loop() {
  // Send "SOS"
  // S = ...
  digitalWrite(13, HIGH);
  delay(dotDelay);
  digitalWrite(13, LOW);
  delay(dotDelay);
  digitalWrite(13, HIGH);
  delay(dotDelay);
  digitalWrite(13, LOW);
  delay(dotDelay);
  digitalWrite(13, HIGH);
  delay(dotDelay);
  digitalWrite(13, LOW);
  delay(dashDelay);
  // O = ---
  digitalWrite(13, HIGH);
  delay(dashDelay);
  digitalWrite(13, LOW);
  delay(dotDelay);
  digitalWrite(13, HIGH);
  delay(dashDelay);
  digitalWrite(13, LOW);
  delay(dotDelay);
  digitalWrite(13, HIGH);
  delay(dashDelay);
  digitalWrite(13, LOW);
  delay(dashDelay);
  // S = ...
  digitalWrite(13, HIGH);
  delay(dotDelay);
  digitalWrite(13, LOW);
  delay(dotDelay);
  digitalWrite(13, HIGH);
  delay(dotDelay);
  digitalWrite(13, LOW);
  delay(dotDelay);
  digitalWrite(13, HIGH);
  delay(dotDelay);
  digitalWrite(13, LOW);
  // word delay
  delay(wordDelay);
}

