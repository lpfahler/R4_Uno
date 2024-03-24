// Lesson 9 HW Code for Uno R4 Course
// Blink Red and Green LED with Serial Print
// Red (fast) blinks faster than the Green (slow) blinks.
// This is a small change to HW instructions
// Lori Pfahler
// March 2024

// Pin number of LEDs
int redLED = 8;
int greenLED = 7;

// variables to track LED states
int redState = LOW;  
int greenState = LOW;

// timing variables when were LEDs last updated
unsigned long redPreviousMillis = 0;
unsigned long greenPreviousMillis = 0;
unsigned long redCurrentMillis;
unsigned long greenCurrentMillis;

// intervals for blinking
int redInterval = 500;
int greenInterval = 2000;

void setup() 
{
  // setup LEDs as OUTPUTs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  // start serial monitor
  Serial.begin(9600);
}

void loop() 
{
  // get current time
  redCurrentMillis = millis();
  greenCurrentMillis = millis();

  // check red LED situation
  if (redCurrentMillis - redPreviousMillis >= redInterval) {
    // save the time the red LED blinked
    redPreviousMillis = redCurrentMillis;
    // switch LED state
    redState = !redState;
    // write redState to redLED
    digitalWrite(redLED, redState);
    // print LED states to serial monitor
    Serial.print("Red State = ");
    Serial.print(redState);
    Serial.print(", Green State = ");
    Serial.println(greenState);
  }

  // check green LED situation
  if (greenCurrentMillis - greenPreviousMillis >= greenInterval) {
    // save the time the green LED blinked
    greenPreviousMillis = greenCurrentMillis;
    // switch LED state
    greenState = !greenState;
    // write greenState to greenLED
    digitalWrite(greenLED, greenState);
  }
}
