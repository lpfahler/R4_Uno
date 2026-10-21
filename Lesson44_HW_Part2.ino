// HW Lesson 44 for McWhorter's UNO R4 Course - Part 2
// Play some songs on a Passive Buzzer
// User song choice, playSong function and pitches in a header file
// Improvement would be to including songs in a header file too
// Lori Pfahler
// October 2027

#include "pitches.h"

int buzzerPin = 8;

// Ode to Joy
int odeToJoy[] = {
  A4, A4, AS4, C5, C5, AS4, A4, G4, F4, F4,
  G4, A4, A4, G4, G4
};
// Ode to Joy durations: 8 = eight note, 4 = quarter note, 
// 2 = half note, 4/1.5 = quarter note with dot
int odeToJoyDurations[] {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4/1.5, 8, 2 
};
int odeLength = sizeof(odeToJoy)/sizeof(odeToJoy[0]);

// Margaritaville
int margaritaville[] = {
  B4, B4, A4, A4, G4, G4, FS4, G4, FS4, G4,
  FS4, D4, REST, B4, B4, B4, B4, A4, A4, A4,
  B4, A4, A4, FS4, REST, B4, B4, B4, CS5, 
  A4, B4, CS5, D5, A4, FS4, FS4, G4, REST, G4, 
  G4, A3, REST, G4, G4, FS4, D4, D4
};
int margaritavilleDurations[] {
  8, 4, 8, 4, 8, 4, 8, 8,
  8, 8, 8, 4, 4, 8, 8, 4, 8, 4/1.5, 4, 8,
  8, 8, 8, 4, 4, 4, 8, 8, 4/1.5,
  8, 4, 4/1.5, 4, 4, 4, 8, 2/1.5, 8, 8,
  8, 2, 4, 8, 4, 8, 8, 4
};
int marLength = sizeof(margaritaville)/sizeof(margaritaville[0]);


// Star Trek Intro
int starTrek[] = {D4, G4, C5, B4, G4, E4, A4, D5};
int starTrekDurations[] = {8/1.5, 16/1.5, 4/1.5, 8, 16/1.5, 16/1.5, 16/1.5, 2};
int stLength = sizeof(starTrek)/sizeof(starTrek[0]);

// function to play sounds - assumes buzzPin has been setup with appropriate pinMode
void playSong(int buzzPin, int tempo, int notes[], int lenNotes, int durations[], int lenDurations) {
  for (int note = 0; note < lenNotes; note++) {
    tone(buzzPin, notes[note], tempo/durations[note]);
    delay(tempo/durations[note]);
    // break between notes
    delay(10);
  }
}


void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // ask user for song selection
  Serial.println("Select Song.  1 = Ode to Joy, 2 = Star Trek Intro, 3 = Margaritaville,");
  while(Serial.available() == 0) {
    // wait for user input
  }
  int song = Serial.parseInt();
  // play user selected song
  switch(song) {
    case 1:
      // Ode to Joy
      playSong(buzzerPin, 1200, odeToJoy, odeLength, odeToJoyDurations, odeLength);
      break;
    case 2:
      // Star Trek Intro
      playSong(buzzerPin, 1500, starTrek, stLength, starTrekDurations, stLength);
      break;
    case 3:
      // Margaritaville
      playSong(buzzerPin, 1500, margaritaville, marLength, margaritavilleDurations, marLength);
      break;
    default:
      Serial.println("Enter a 1, 2, 3");
      break;
  }

}


