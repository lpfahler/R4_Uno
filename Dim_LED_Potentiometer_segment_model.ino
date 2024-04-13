// HW for Lesson 12 Read Analog Voltages Using Potentiometers
// Create a dimmer for an LED using a Potentiometer
// Lori Pfahler
// April 2024

int greenLED = 9;
int potPin = A4;
int potReading;
int baudRate = 9600;
int delayTime = 100;
float brightness;


void setup() {
  pinMode(potPin, INPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(baudRate);
}

void loop() {
  // read potentiometer
  potReading = analogRead(potPin);
  // hueristic equation 
  if(potReading < 2){
    brightness = 0;
  }
  else if(potReading < 256) {
    brightness = (0.15 * potReading) + 2;
  }  
  else if(potReading < 512) {
    brightness = (0.06 * potReading) + 25;
  }
  else if(potReading < 768) {
    brightness = (0.06 * potReading) + 25;
  }
  else {
    brightness = (0.314 * potReading) - 170.941;
  }
  
  // analogWrite to greenLED current brightness value
  analogWrite(greenLED, int(brightness));
  Serial.print("potReading: ");
  Serial.print(potReading);
  Serial.print(", brightness: ");
  Serial.println(brightness);
  delay(delayTime);
}

