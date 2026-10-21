// Class Code for McWhorter's UNO R4 Course - Part 3
// Play a song
// Lesson 44 - Music on a Passive Buzzer
// Lori Pfahler
// October 2027

#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_DB3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_EB3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define REST     0


// song
int melody[] = {
  NOTE_C4,
  NOTE_G3,
  NOTE_G3,
  NOTE_A3,
  NOTE_G3,
  REST,
  NOTE_B3,
  NOTE_C4
};
// durations
int noteDurations[] {
  4, 8, 8, 4, 4, 4, 4, 4
};

int buzzerPin = 8;
int melodyLength;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
  // Typo in Paul's Lesson
  Serial.println(sizeof(melody));
  // Correct array length formula
  melodyLength = sizeof(melody)/sizeof(melody[0]);
  Serial.println(melodyLength);
  // play song - print note duration and delay duration times
  for (int note = 0; note < melodyLength; note++) {
    tone(buzzerPin, melody[note], 1000/noteDurations[note]);
    delay(1000/noteDurations[note] * 1.2);
    // I would normally use "delay(10)"" for note separation
    Serial.println(String(1000/noteDurations[note]) + ", " + String(1000/noteDurations[note] * 1.2));
  }
}

void loop() {

}

