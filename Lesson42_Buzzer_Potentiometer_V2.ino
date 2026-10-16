// Extra Credit Code Part 2 for Lesson 42 Transistors and Active Buzzer
// Potentiometer to adjust the tone active buzzer
// Lori Pfahler
// October 2026

int buzzerPin = 8;
int potPin = A0;
int potReading;
int delayTime = 1;
String message;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // read potentiometer and set the delayTime to a value between 1 and 10 ms
  potReading = analogRead(potPin);
  delayTime = map(potReading, 0, 1023, 1, 10);
  message = "Pot Reading = " + String(potReading) + ", delayTime = " + String(delayTime);
  Serial.println(message);
  // play tone
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(delayTime);
    digitalWrite(buzzerPin, LOW);
    delay(delayTime);
  }
}

