// HW for Lesson 24 - McWhorter Uno R4 Class
// Pushbutton Switch Control of LED - Toggle
// Turn the LED on with one press then off with the next press
// This approach will not turn the LED on/off until the 
// button is let go of
//
// Lori Pfahler
// September 2024

int greenLED = 7;
int buttonPin = 12;

// variables to track button presses and LED state (on/off)
int buttonState = HIGH;
int lastButtonState = HIGH;
int ledState = LOW;

void setup() {
  // setup LED
  pinMode(greenLED, OUTPUT);
  // setup button switch with external pull-up resistor
  // NOT PRESSED = HIGH, PRESSED = LOW
  pinMode(buttonPin, INPUT);
  // start serial monitor
  Serial.begin(115200);
  // Print to the serial monitor to check status of LED
  Serial.print("LED is: ");
  Serial.println(ledState);
}

void loop() {
  // read button state
  buttonState = digitalRead(buttonPin);
  // change ledState if the button was pressed = lastButtonState==LOW
  // and the current value of the button is now not pressed = buttonState==HIGH
  // the button was pushed and let go of
  if (buttonState == HIGH && lastButtonState == LOW){
  // use the code below if you want it to change as immediately
  // upon pressing the button
  // if (buttonState == LOW && lastButtonState == HIGH){
    ledState = !ledState;
    // change LED to appropriate state
    digitalWrite(greenLED, ledState); 
    // Print ledState to the serial monitor
    Serial.print("LED is: ");
    Serial.println(ledState);
  }
  // reset the last button state variable
  lastButtonState = buttonState;
  delay(50);
}
