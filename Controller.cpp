#include "Controller.h"



Controller::Controller(Adafruit_StepperMotor* Motor, Adafruit_DCMotor* myMotor, byte Forwardpin, byte Backwardpin, byte Raisepin, byte Lowerpin) {      
  this->Controller = Controller;
  this->Raisepin = Raisepin;            //Assigns the variable to it's own changing value
  this->Lowerpin = Lowerpin;
  this->Forwardpin = Forwardpin;               //Assigns the variable to it's own changing value
  this->Backwardpin = Backwardpin;
  init_Move();                                     //Starts the initiation/Pin out set up method
}

Controller::Controller() {
  this->Raisepin = 8;            //Assigns the variable to it's own changing value
  this->Lowerpin = 7;
  this->Forwardpin = 2;               //Assigns the variable to it's own changing value
  this->Backwardpin = 4;
  init_Move();
}

void Controller::init_Move() {              
  pinMode(Raisepin, INPUT);               //Assigns the pin out to the output signals
  pinMode(Lowerpin, INPUT);               //Assigns the pin out to the output signals
  pinMode(Forwardpin, INPUT);                        //Assigns pins as input pins
  pinMode(Backwardpin, INPUT);                        //Assigns pins as input pins
  pinMode(Homepin, INPUT); 
  LastForVal = LOW;
  LastBackVal= LOW;
  LastRaiseVal = LOW;
  LastLowerVal = LOW;
                                        //Starts the release Method to set up motor
}

void Controller::move_F() {
  Serial.println("Forward");
  Controller->run(FORWARD);          //Object takes one turn forward
  }

void Controller::move_B() {
  Serial.println("Backward");
  Controller->run(BACKWARD);         //Object takes one turn backward
  }


void Controller::step_U() {    
  Serial.println("Raise");
  Controller->step(10, FORWARD, MICROSTEP);
}

void Controller::step_D() {    
  Serial.println("Lower");
  Controller->step(10, BACKWARD, MICROSTEP);
}

int Controller::ReadInputs() {
  CurForVal=digitalRead(Forwardpin);
  CurBackVal=digitalRead(Backwardpin);
  CurRaiseVal=digitalRead(Raisepin);
  CurLowerVal=digitalRead(Lowerpin);
  if (!LastForVal && CurForVal) {
    LastForVal = CurForVal;
    Serial.println("Recieved 1");
    move_F();
    //delay(100);
    return 1;
  }
  if (!LastBackVal && CurBackVal) {
    LastBackVal = CurBackVal;
    Serial.println("Recieved 2");
    move_B(); 
    //delay(100);
    return 1;
  }
  if (!LastRaiseVal && CurRaiseVal) {
    LastRaiseVal=CurRaiseVal;
    Serial.println("Recieved 3");
    step_U();
    //delay(100);
    return 1;
  }
  if (!LastLowerVal && CurLowerVal) {
    LastLowerVal=CurLowerVal;
    Serial.println("Recieved 3");
    step_U();
    //delay(100);
    return 1;
else {
    LastForVal = LOW;
    LastBackVal= LOW;
    LastRaiseVal = LOW;
    LastLowerVal = LOW;
      return 0;
  }
}