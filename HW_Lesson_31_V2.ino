// HW for Lesson 31 - Using DHT-11 Temp and Humidity Sensor
// Scroll Data on LED Matrix Version 2
// Three Button Switches: temp, humidity, heat index
//
// Added 10k resistor to data pin on DHT-11
// Use "blink without delay" to update sensor data at a slower rate
// than the buttons are checked
// Button switches can react separately from sensor update
//
// Lori Pfahler
// October 2024

// LED matrix libraries
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// load library for DHT-11 sensor 
#include <DHT.h>
#define DHTPin 3
#define DHTTYPE DHT11
DHT dht(DHTPin, DHTTYPE);

// create matrix object
ArduinoLEDMatrix matrix;

// variables for sensor reading and display
float tempC;
float tempF;
float humid;
float heatIndexC;
float heatIndexF;
String message0;
String message1;
String message2;
int selectMessage = 0;

// variables to update sensor data every "interval" second(s)
// can modify as desired
unsigned long previousMillis = 0;
unsigned long currentMillis;
// interval for sensor data update 
int interval = 5000;

// buttons and LED indicator light
int tempButton = 8; //red
int tempState = HIGH;
int prevtempState = HIGH;
int humidButton = 7; //blue
int humidState = HIGH;
int prevhumidState = HIGH;
int HIButton = 5; //yellow
int HIState = HIGH;
int prevHIState = HIGH;
int greenLED = 2;

void setup() {
  // start matrix
  matrix.begin();

  // start the DHT object
  dht.begin();

  // delay for intialization of sensor
  delay(2000);
    
  // setup button switches and LED
  pinMode(tempButton, INPUT_PULLUP);
  pinMode(humidButton, INPUT_PULLUP);
  pinMode(HIButton, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);


  // get initial sensor data
  tempC = dht.readTemperature(false);
  tempF = dht.readTemperature(true);
  humid = dht.readHumidity();
  heatIndexF = dht.computeHeatIndex(true);
  heatIndexC = dht.computeHeatIndex(false);
  // prepare messages
  message0 =  "Temp(F): " + String(tempF) + ", Temp(C): " + String(tempC);
  message1 =  "Humidity: " + String(humid) + "%";
  message2 = "Heat Index(F): " + String(heatIndexF) + ", Heat Index(C) " + String(heatIndexC);


  // blink LED to indicate sensor ready to go
  for (int i = 0; i <= 5; i++) {
    digitalWrite(greenLED, HIGH);
    delay(100);
    digitalWrite(greenLED, LOW);
    delay(100);
  }
}

void loop() {
  // get current time since start in milliseconds
  currentMillis = millis();

  // determine if it is time to update sensor data
  if (currentMillis - previousMillis >= interval) {
    // get sensor data
    tempC = dht.readTemperature(false);
    tempF = dht.readTemperature(true);
    humid = dht.readHumidity();
    heatIndexF = dht.computeHeatIndex(true);
    heatIndexC = dht.computeHeatIndex(false);
    // check for bad data
    if (isnan(tempC) || isnan(tempF) || isnan(humid)) {
      matrix.beginDraw(); 
      matrix.textScrollSpeed(50);
      matrix.textFont(Font_4x6);
      matrix.beginText(0, 1, 255, 0, 0);
      matrix.println("Data Invalid");
      matrix.endText(SCROLL_LEFT);
      matrix.endDraw();
      return;
    }
    // update timing
    previousMillis = currentMillis;
    // prepare messages
    message0 =  "Temp(F): " + String(tempF) + ", Temp(C): " + String(tempC);
    message1 =  "Humidity: " + String(humid) + "%";
    message2 = "Heat Index(F): " + String(heatIndexF) + ", Heat Index(C) " + String(heatIndexC);

  }

  // read the state of the button
  tempState = digitalRead(tempButton);
  humidState = digitalRead(humidButton);
  HIState = digitalRead(HIButton);

  // if button pressed - send message to LED matrix
  if (tempState == LOW && prevtempState == HIGH) {
    matrix.beginDraw(); 
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_4x6);
    matrix.beginText(0, 1, 255, 0, 0);
    matrix.println(message0);
    digitalWrite(greenLED, HIGH);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
    // turn off LED
    digitalWrite(greenLED, LOW);
  }

  if (humidState == LOW && prevhumidState == HIGH) {
    matrix.beginDraw(); 
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_4x6);
    matrix.beginText(0, 1, 255, 0, 0);
    matrix.println(message1);
    digitalWrite(greenLED, HIGH);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
    // turn off LED
    digitalWrite(greenLED, LOW);
  }

  if (HIState == LOW && prevHIState == HIGH) {
    matrix.beginDraw(); 
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_4x6);
    matrix.beginText(0, 1, 255, 0, 0);
    matrix.println(message2);
    digitalWrite(greenLED, HIGH);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
    // turn off LED
    digitalWrite(greenLED, LOW);
  }

  // reset previous button states
  prevtempState = tempState;
  prevhumidState = humidState;
  prevHIState = HIState;

  // debounce
  delay(50); 

}

