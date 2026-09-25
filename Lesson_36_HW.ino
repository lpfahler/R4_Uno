// Lesson 36 HW User Input of Grades
// Print grades in sorted order - Max first
// Calculate average, min and max
// Lori Pfahler
// September 2026

// create an int for the number of grades, total of the grades, min and max grade
int numGrades;
float total;
float minGrade;
float maxGrade;
// variables for bubble sort
int swap;
int nPairs;
float pair1;
float pair2;


void setup() {
  Serial.begin(115200);
}

void loop() {
  // reset total
  total = 0;

  // get number of grades from user and create array to store grades
  Serial.println("How many grades?");
  while (Serial.available() == 0) {
    // wait for user input
  }
  numGrades = Serial.parseInt();
  float grades[numGrades];

  // get grades from user
  for (int i = 0; i < numGrades; i++) {
    Serial.println("Enter Grade " + String(i + 1));
    while (Serial.available() == 0) {
      // wait for user input
    }
    grades[i] = Serial.parseFloat();
    // create running total for average calculation
    total = total + grades[i];
  }

  // Use bubble sort algoritm 
  nPairs = numGrades - 1;
  swap = -1;
  while (swap != 0) {
    swap = 0;
    for (int i = 0; i < nPairs; i++) {
      // store adjacent pair data to allow swapping if needed
      pair1 = grades[i]; 
      pair2 = grades[i+1];
      // swap if pair out of order
      if (pair1 > pair2) {
        grades[i] = pair2;
        grades[i+1] = pair1;
        swap++;
      }
    }
    nPairs = nPairs - 1;
  }

  // print grades - highest to lowest
  Serial.println();
  Serial.println("Your Grades are:");
  for (int i = numGrades - 1; i >= 0; i--) {
    Serial.println(String(grades[i]));
  }
  // print results
  Serial.println();
  Serial.println("Average: " + String(total/numGrades));
  // get min and max from sorted grades array
  Serial.println("Min Grade: " + String(grades[0]));
  Serial.println("Max Grade: " + String(grades[numGrades - 1]));
  Serial.println();
}

