// HW Lesson 44 for McWhorter's UNO R4 Course
// Play some songs on a Passive Buzzer
// Lori Pfahler
// October 2027

#include "pitches.h"

int buzzerPin = 8;
int tempo;

// Lori's Transcription of Ode to Joy
int odeToJoy[] = {
  A4, A4, AS4, C5, C5, AS4, A4, G4, F4, F4,
  G4, A4, A4, G4, G4}
;
// Ode to Joy durations
int odeToJoyDurations[] {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4/1.5, 8, 2 
};

// Lori's Transcription of Margaritaville
int margaritaville[] = {
  B4, B4, A4, A4, G4, G4, FS4, G4, FS4, G4,
  FS4, D4, REST, B4, B4, B4, B4, A4, A4, A4,
  B4, A4, A4, FS4, REST, B4, B4, B4, CS5, 
  A4, B4, CS5, D5, A4, FS4, FS4, G4, REST, G4, 
  G4, A3, REST, G4, G4, FS4, D4, D4
};

// 8 = eight note, 4 = quarter note, 2 = half note
// 4/1.5 = quarter note with dot
int margaritavilleDurations[] {
  8, 4, 8, 4, 8, 4, 8, 8,
  8, 8, 8, 4, 4, 8, 8, 4, 8, 4/1.5, 4, 8,
  8, 8, 8, 4, 4, 4, 8, 8, 4/1.5,
  8, 4, 4/1.5, 4, 4, 4, 8, 2/1.5, 8, 8,
  8, 2, 4, 8, 4, 8, 8, 4
};


void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
  // play Ode to Joy
  int odeLength = sizeof(odeToJoy)/sizeof(odeToJoy[0]);
  // set the tempo of the music; typically time for whole note 
  tempo = 1200;
  for (int note = 0; note < odeLength; note++) {
    // use tempo divided by song durations array
    // to set the duration for tone/delay functions
    tone(buzzerPin, odeToJoy[note], tempo/odeToJoyDurations[note]);
    delay(tempo/odeToJoyDurations[note]);
    // break between notes
    delay(10);
  }

  delay(5000);

  // play Margaritaville
  int marLength = sizeof(margaritaville)/sizeof(margaritaville[0]);
  tempo = 1500;
  for (int note = 0; note < marLength; note++) {
    tone(buzzerPin, margaritaville[note], tempo/margaritavilleDurations[note]);
    delay(tempo/margaritavilleDurations[note]);
    delay(10);
  }
}

void loop() {

}


