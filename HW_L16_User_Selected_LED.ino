// Homework for Lesson 16 - McWhorter Uno R4 Class
// User enters the color of the LED that should be turned on
// Show selection on LED Matrix
// Improvement would be to use a function for scrolling text
// Ran into "bus errors" when I tried it
// Lori Pfahler
  // June 2024

// Needed libraries for LED Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"


// setup variables, LEDs and LED Matrix
String myColor;
String myColorLC;
ArduinoLEDMatrix matrix;
String message;
int baudRate = 115200;
int redLED = 12;
int yellowLED = 9;
int greenLED = 6;
int catLED = 4;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(catLED, OUTPUT);
  Serial.begin(baudRate);
  matrix.begin();

}

void loop() {
  Serial.println("Please Enter the Color of the LED to turn on (red, yellow, green, or cat):");
  while(Serial.available()==0) {
    // wait for user input
  }
  // keep original user string as they typed it
  myColor = Serial.readString();
  myColorLC = myColor;
  myColorLC.toLowerCase();

  if(myColorLC == "red") {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(catLED, LOW); 
    Serial.print("You chose the ");
    Serial.print(myColor);
    Serial.println(" LED.  RED ALERT!!!");
    // scroll message
    message = "RED ALERT!";
    matrix.beginDraw();
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 1);
    matrix.println(message);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
  else if(myColorLC == "yellow") {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(catLED, LOW);
    Serial.print("You chose the ");
    Serial.print(myColor);
    Serial.println(" LED.");
    // scroll message
    message = "Yellow";
    matrix.beginDraw();
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 1);
    matrix.println(message);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
  else if(myColorLC == "green") {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(catLED, LOW);
    Serial.print("You chose the ");
    Serial.print(myColor);
    Serial.println(" LED."); 
    // scroll message
    message = "Green";
    matrix.beginDraw();
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 1);
    matrix.println(message);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
  else if(myColorLC == "cat") {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(catLED, HIGH);  
    Serial.print("Excellent!  You chose the ");
    Serial.print(myColor);
    Serial.println(" LED. Enjoy!"); 
    // scroll message
    message = "Cats Rule!";
    matrix.beginDraw();
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 1);
    matrix.println(message);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(catLED, LOW); 
    Serial.println("Invalid entry; please try again.  ");
    // scroll message
    message = "Try Again";
    matrix.beginDraw();
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 1);
    matrix.println(message);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw(); 
  }
}
