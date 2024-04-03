// HW for Lesson 10 - McWhorter Uno R4 Class
// Using analog voltages to control LED brightness
// Lori Pfahler
// April 2024

// pin number of LED
int greenLED = 9;

// array for brightness values - value between 0 to 255; 0 = off, 255 = full brightness
// change by power of 2 to deal with nonlinear perception of brightness
int brightValues[] = {
  1, 2, 4, 8, 16, 32, 64, 128, 255, 128, 64, 32, 16, 8, 4, 2, 1, 0
};
// current index value for brightValue array 
int currentIndex = 0;
// number of values in the brightValues array
int numValues;

// delay time in ms
int delayTime = 50;

void setup() 
{
  // setup LED as OUTPUT
  pinMode(greenLED, OUTPUT);
  // This is a way to determine the size of our brightValues array
  numValues = sizeof(brightValues)/sizeof(brightValues[0]);
}

void loop() 
{
  // reset currentIndex to zero if we have gone through all the brightValues
  if (currentIndex >= numValues) 
  {
    currentIndex = 0;
  }
  // analogWrite to redLED current brightness value
  analogWrite(greenLED, brightValues[currentIndex]);
  delay(delayTime);
  // advance the value of currentIndex by 1
  currentIndex++;
}

