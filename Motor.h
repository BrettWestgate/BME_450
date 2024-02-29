#ifndef MY_MOTOR_H
#define MY_MOTOR_H

#include <Arduino.h>
#include <Adafruit_MotorShield.h>

class Pleth_Motor {

  private:
  byte Downpin;                                   //Output Pin Variable
  byte Uppin;
  byte Forwardpin;
  byte Backwardpin;
  byte state;
  byte LastForVal;
  byte LastBackVal;
  byte LastUpVal;
  byte LastDownVal;;
  byte CurForVal;
  byte CurBackVal;
  byte CurUpVal;
  byte CurDownVal;
    int p;                                         //Steps/Position Variable
  Adafruit_StepperMotor* PlethMotor;                       
  

  public:
  Pleth_Motor(Adafruit_StepperMotor* PlethMotor, byte Downpin, byte Uppin, byte Forwardpin, byte Backwardpin);

  Pleth_Motor();                  //Method to set up Pinouts
  void init_Pleth();                    //Method to assign the Pinouts
  void move_F();                  //Method for forward step
  void move_B();                  //Method for backward step
  void step_U();
  void step_D();
  void off();                     //Method for release/output signaling release
  void Position(int p) {          //Method for steps tracking
    this->p = p;
  }
  int ReadInputs();              //Main code function
};

#endif
