// Extra Credit Part 1 Code for Lesson 42 Transistors and Active Buzzer
// Play different tones on an Active Buzzer
// to create a police siren type sound
// Lori Pfahler
// October 2026

int buzzerPin = 8;
int delayOne = 1;
int delayTwo = 3;


void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // first tone
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(delayOne);
    digitalWrite(buzzerPin, LOW);
    delay(delayOne);
  }

  // second tone
  for (int i = 0; i < 33;  i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(delayTwo);
    digitalWrite(buzzerPin, LOW);
    delay(delayTwo);
  }
}
