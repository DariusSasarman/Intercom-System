// 28BYJ-48 Stepper Motor - 10 degree oscillation
// Connect ULN2003 driver board IN1-IN4 to pins 8-11

#include <Stepper.h>

// Motor specs
const int stepsPerRevolution = 2048;  // 28BYJ-48 with gear reduction
const int stepsFor50Degrees = 57;     // (2048/360) * 10 ≈ 57

// Initialize stepper library on pins 8-11
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set motor speed (RPM)
  myStepper.setSpeed(5);  // Adjust speed as needed (5-15 RPM recommended)
  
  Serial.begin(9600);
  Serial.println("28BYJ-48 Oscillation Start");
}

void loop() {

  // Rotate 10 degrees to the left (counterclockwise)
  Serial.println("Rotating 50° left");
  myStepper.step(-stepsFor50Degrees*8);
  delay(500);  // Pause at end position
  
  // Rotate 10 degrees to the right (clockwise)
  Serial.println("Rotating 50° right");
  myStepper.step(stepsFor50Degrees*8);
  delay(500);  // Pause at end position
  

}
