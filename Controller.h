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
    //Super long but it encompasses both available kind of motors and each pin for each direction
  Controller();                  
  void init_Move();                    
  void move_F();                  
  void move_B();                  
  void step_U();
  void step_D();                    
  int ReadInputs();
};

#endif
