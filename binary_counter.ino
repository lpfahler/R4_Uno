// Lesson 5 HW Code for Uno R4 Course
// Binary Counter
// Lori Pfahler
// February 2024

// Define variable for delay time 
// Define array for LED Pins
int delayTime = 1000;
int ledPin[] = {5, 6, 7, 8};

void setup() {
  // setup pins for LEDs on Pins 5-8
  for(int i = 0; i < 4; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop()
{
  // loop through the numbers 0 - 15
  for(int curNum = 0; curNum < 16; curNum++)
  {
    // make a byte version of curNum
    byte myByte = curNum;
    // loop through the places in myByte if the place
    // is a 1 turn the LED on - if the place is a zero turn it off
    for(int i = 0; i < 4; i++)
    {
      // use bitRead to select the "place" to look at
      if(bitRead(myByte, i) == 1) // turn on
      { 
        digitalWrite(ledPin[i], HIGH); 
      }
      else // turn off
      {
        digitalWrite(ledPin[i], LOW); 
      }
    }
    delay(delayTime);
  }
}

