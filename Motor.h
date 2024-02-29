#ifndef MY_MOTOR_H
#define MY_MOTOR_H

#include <Arduino.h>
#include <Adafruit_MotorShield.h>
//#include <Adafruit_MotorShield.cpp>


class Pleth_Motor {

  private:
  byte Downpin;               //Output Pin Variable
  byte Uppin;
  byte Forwardpin;
  byte Backwardpin;
  //byte Homepin;
  byte state;
  byte LastForVal;
  byte LastBackVal;
  byte LastUpVal;
  byte LastDownVal;
  //byte LastHomeVal;
  byte CurForVal;
  byte CurBackVal;
  byte CurUpVal;
  byte CurDownVal;
  //byte CurHomeVal;
  int p;   
  Adafruit_StepperMotor* PlethMotor;                       //Steps/Position Variable
  

  public:
  Pleth_Motor(Adafruit_StepperMotor* PlethMotor, byte Downpin, byte Uppin, byte Forwardpin, byte Backwardpin);

  Pleth_Motor();                  //Method to set up Pinouts
  void init_Pleth();                    //Method to assign the Pinouts
  void step_F();                  //Method for forward step
  void step_B();                  //Method for backward step
  void step_U();
  void step_D();
  void off();                     //Method for release/output signaling release
  void Position(int p) {          //Method for steps tracking
    this->p = p;
  }
  void GoHome();                  //Method for returning to beginnning position
  int ReadInputs();
};

#endif
