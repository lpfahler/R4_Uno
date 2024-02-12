// Lesson 3 HW Code for Uno R4 Course
// Blink 4 LEDs
// Lori Pfahler
// February 2024

// Define variables for delay time and LED pins
int delayTime = 200;
int LED1 = 12;
int LED2 = 8;
int LED3 = 4;
int LED4 = 2;

void setup() {
  // setup pins for LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  // Blink LEDs
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  delay(delayTime);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(delayTime);
}

