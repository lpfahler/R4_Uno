// Code from Lesson 18 - McWhorter R4 Uno Class
// Hooking up an RGB LED
// Lori Pfahler
// June 2024

int redPin = 11;
int greenPin = 10;
int bluePin = 9;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(redPin, HIGH);
  delay(500);
  digitalWrite(redPin, LOW);
  delay(500);

  digitalWrite(greenPin, HIGH);
  delay(500);
  digitalWrite(greenPin, LOW);
  delay(500);

  digitalWrite(bluePin, HIGH);
  delay(500);
  digitalWrite(bluePin, LOW);
  delay(500);

}
