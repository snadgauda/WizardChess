/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

#define STEP_X_1 4
#define STEP_X_2 5
#define STEP_X_3 6
#define STEP_X_4 7

#define STEP_Y_1 8
#define STEP_Y_2 9
#define STEP_Y_3 10
#define STEP_Y_4 11

// change this to fit the number of steps per revolution for your motor
const int stepsPerRevolution = 200;
// set the speed at 60 rpm: 
const int stepperSpeed = 200;

// initialize the stepper library on pins 8 through 11:
Stepper stepperX(stepsPerRevolution, STEP_X_1, STEP_X_2, STEP_X_3, STEP_X_4);
Stepper stepperY(stepsPerRevolution, STEP_Y_1, STEP_Y_2, STEP_Y_3, STEP_Y_4);

void setup() {
  //*
  pinMode(STEP_X_1, OUTPUT);
  pinMode(STEP_X_2, OUTPUT);
  pinMode(STEP_X_3, OUTPUT);
  pinMode(STEP_X_4, OUTPUT);
  
  pinMode(STEP_Y_1, OUTPUT);
  pinMode(STEP_Y_2, OUTPUT);
  pinMode(STEP_Y_3, OUTPUT);
  pinMode(STEP_Y_4, OUTPUT);
  //*/
  stepperX.setSpeed(stepperSpeed);
  stepperY.setSpeed(stepperSpeed);
  // initialize the serial port:
  Serial.begin(9600);
  /*
  stepperX.step(stepsPerRevolution);
  stepperY.step(stepsPerRevolution);
  delay(1000);
  stepperX.step(-stepsPerRevolution);
  stepperY.step(-stepsPerRevolution);
  */

  for (int i = 0; i <200; i++)
  {
    stepperX.step(1);
    delay(1);
    stepperY.step(2);
    delay(1);
  }
}

void loop() {

}
