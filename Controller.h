#ifndef MY_MOTOR_H
#define MY_MOTOR_H

#include <Arduino.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
//#include <Adafruit_MotorShield.cpp>


class Controller {

  private:
  byte Forwardpin;
  byte Backwardpin;
  byte Raisepin;
  byte Lowerpin;
  byte state;
  byte LastForVal;
  byte LastBackVal;
  byte LastRaiseVal;
  byte LastLowerVal;
  byte CurForVal;
  byte CurBackVal;
  byte CurRaiseVal;
  byte CurLowerVal;                          
  Adafruit_StepperMotor* Motor;
  Adafruit_DCMotor* myMotor;

  public:
  Controller(Adafruit_StepperMotor* Motor, Adafruit_DCMotor* myMotor, byte Forwardpin, byte Backwardpin, byte Raisepin, byte Lowerpin);

  Movement();                  //Method to set up Pin outs
  void init_Move();                    //Method to assign the Pin outs
  void move_F();                  //Method for forward step
  void move_B();                  //Method for backward step
  void step_U();
  void step_D();
  void off();                     //Method for release/output signalling release
  int ReadInputs();
};

#endif
