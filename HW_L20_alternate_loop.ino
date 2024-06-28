// HW for Lesson 20 - McWhorter's Uno R4 Class
// Loop without using "for" or "while" loop
// Lori Pfahler
// June 2024

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int numCycles;
int delayTime = 250;
bool goToStart = true;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(115200);
}

void rgbLED(int redPinNum, int greenPinNum, int bluePinNum, int red, int green, int blue) {
  // function to light an rgb led - assuming pinMode has been called
  // and connected to pins that allow PWM
  analogWrite(redPinNum, red);
  analogWrite(greenPinNum, green);
  analogWrite(bluePinNum, blue);
}

void loop() {
  if (goToStart == true) {
    goToStart = false;
    Serial.println("Please enter the number of R, G, B cycles you wish (i.e. 1, 2, 3, ..., max 25)");
    while(Serial.available()==0) {
      // wait for user input
    }
    numCycles = Serial.parseInt();

    // only allow 1-25 for the number of cycles
    if (numCycles > 25) {
      numCycles = 25;
      Serial.print("Too many cycles requested; ");

    }
    if (numCycles <= 0){
      numCycles = 1;
      Serial.print("Too few cycles requested; ");
    }

    Serial.print("The number of cycles is set to ");
    Serial.println(numCycles);
  }
  if (numCycles==0){
    goToStart = true;
  }
  
  if (numCycles > 0){
    // do an R, G, B cycle of the LED
    rgbLED(redPin, greenPin, bluePin, 255, 0, 0);
    delay(delayTime);
    rgbLED(redPin, greenPin, bluePin, 0, 255, 0);
    delay(delayTime);
    rgbLED(redPin, greenPin, bluePin, 0, 0, 255);
    delay(delayTime);  
    // turn LED off and delay a bit longer for visual separation of cycles
    rgbLED(redPin, greenPin, bluePin, 0, 0, 0);
    delay(delayTime + 500); 
  }
  numCycles = numCycles - 1;

}
