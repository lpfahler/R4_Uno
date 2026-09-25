// Lesson 35 HW User Input of Grades
// Calculate average, min and max
// Lori Pfahler
// September 2026

// create an int for the number of grades
int numGrades;
float total;
float minGrade;
float maxGrade;


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
    // get initial value for min and max
    if (i == 0) {
      minGrade = grades[i];
      maxGrade = grades[i];
    }
    // check for new min or max
    if (grades[i] < minGrade) {
      minGrade = grades[i];
    }  
    if (grades[i] > maxGrade) {
      maxGrade = grades[i];
    }
  }
  // print grades
  Serial.println();
  Serial.println("Your Grades are:");
  for (int i = 0; i < numGrades; i++) {
    Serial.println(String(i + 1) + ": " + String(grades[i]));
  }
  // print results
  Serial.println();
  Serial.println("Average: " + String(total/numGrades));
  Serial.println("Min Grade: " + String(minGrade));
  Serial.println("Max Grade: " + String(maxGrade));
  Serial.println();
}
