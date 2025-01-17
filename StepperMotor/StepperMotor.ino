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
#include <Servo.h>

#define STEP_X_1 4
#define STEP_X_2 5
#define STEP_X_3 6
#define STEP_X_4 7

#define STEP_Y_1 8
#define STEP_Y_2 9
#define STEP_Y_3 10
#define STEP_Y_4 11

#define STEP_CONST 100

#define SERVO_PIN 3

#define SERVO_UP 0
#define SERVO_DOWN 90

Servo myServo;

// change this to fit the number of steps per revolution for your motor
const int stepsPerRevolution = 200;
// set the speed at 60 rpm:
const int stepperSpeed = 60;

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

  myServo.attach(SERVO_PIN);
  /*
    stepperX.step(stepsPerRevolution);
    stepperY.step(stepsPerRevolution);
    delay(1000);
    stepperX.step(-stepsPerRevolution);
    stepperY.step(-stepsPerRevolution);
  */
moveStepperFunc(20);
delay(500);
myServo.write(SERVO_UP);
delay(500);
moveStepperFunc(280);
delay(500);
myServo.write(SERVO_DOWN);
delay(500);
moveStepperFuncOpp(300);
}

void loop() {
  if (Serial.available()) {
    String inp = Serial.readString();
    int oldX = inp[0] - '0';
    int oldY = inp[1] - '0';
    int newX = inp[2] - '0';
    int newY = inp[3] - '0';
    doStep(oldX, oldY, newX, newY);
  }
}

void doStep(int oldX, int oldY, int newX, int newY) {
  stepperX.step(STEP_CONST * oldX);
  delay(1);
  stepperY.step(STEP_CONST * oldY);
  delay(1);
  myServo.write(SERVO_UP);
  int diffX = STEP_CONST * (newX - oldX);
  int diffY = STEP_CONST * (newY - oldY);
  if (diffX == 0) {
    stepperY.step(diffY);
  } else if (diffY == 0) {
    stepperX.step(diffX);
  }  else {
    for (int i = 0; i < diffX; i++)
    {
      stepperX.step(1);
      delay(30);
      stepperY.step(-1);
      delay(30);
    }
    delay(1);
    myServo.write(SERVO_DOWN);
    delay(1);
    delay(1);
  }

}

void moveStepperFunc(int steps){
  for (int i = 0; i < steps; i++)
 {
   stepperX.step(1);
    delay(1);
   stepperY.step(-1);
    delay(1);
  }
}

void moveStepperFuncOpp(int steps){
  for (int i = 0; i < steps; i++)
 {
   stepperX.step(-1);
    delay(1);
   stepperY.step(1);
    delay(1);
  }
}
