// Code to demostrate interrupts on Arduino
// Using interrupts in this program
// Yellow LED (blinkLED) will blink every 200 ms
// Green LED (buttonLED) will change state when we press the button and release
// Lori Pfahler
// October 2026

// Pins 2 and 3 are enabled for this type of interrupt
int buttonPin = 2;
int buttonLED = 11; // green LED on my breadboard
int blinkLED = 12; // yellow LED
volatile bool LEDState = false; // start with buttonLED off
volatile unsigned long prev_interrupt_time = 0;

// Interrupt Service Routine (ISR) - make it a toggle switch
void buttonInterrupt() {
  unsigned long interrupt_time = millis();
  // debounce button switch - change LEDState only if 200ms 
  // has passed since the last trigger
  if (interrupt_time - prev_interrupt_time > 200) {
    LEDState = !LEDState;
    digitalWrite(buttonLED, LEDState);
    prev_interrupt_time = interrupt_time;
  }
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonLED, OUTPUT);
  pinMode(blinkLED, OUTPUT);
  // to enable the ISR using buttonInterrupt function and attach it to buttonPin 
  // CHANGE:the interrupt triggered when signal goes from HIGH to LOW or LOW to HIGH
  // Other choices are LOW, RISING (LOW TO HIGH), FALLING (HIGH TO LOW)
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, RISING);
  digitalWrite(buttonLED, LEDState);
}

void loop() {
  // blink the blinkLED (yellow)
  digitalWrite(blinkLED, HIGH);
  delay(200);
  digitalWrite(blinkLED, LOW);
  delay(200);
}
