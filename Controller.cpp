#include "Controller.h"


Controller::Controller(Adafruit_StepperMotor* Motor, Adafruit_DCMotor* myMotor, byte Forwardpin, byte Backwardpin, byte Raisepin, byte Lowerpin) {      
  this->Motor = Motor;
  this->myMotor = myMotor;      //These two commands allow us to name the motors whatever we want and have it be interchangable 
  this->Raisepin = Raisepin;            
  this->Lowerpin = Lowerpin;
  this->Forwardpin = Forwardpin;         
  this->Backwardpin = Backwardpin;    //These commands allow us to set up the associated pins in whatever order we want them to be                            
}

Controller::Controller() {  //Sets up the input pin numbers *Easily changable*
  this->Raisepin = 8;                 
  this->Lowerpin = 7;
  this->Forwardpin = 2;               
  this->Backwardpin = 4;    //These values are placeholders and can be easily changed to which ever pins we hook them up 
}

void Controller::init_Move() {  //This operation sets up the pins before as input pins             
  pinMode(Raisepin, INPUT);               
  pinMode(Lowerpin, INPUT);               
  pinMode(Forwardpin, INPUT);                        
  pinMode(Backwardpin, INPUT);                        
  LastForVal = LOW;
  LastBackVal= LOW;
  LastRaiseVal = LOW;
  LastLowerVal = LOW;     //The four commands are used in the ReadInputs operation
}

void Controller::move_F() {   //Operation to move the servo motor forward
  Serial.println("Forward");
  myMotor->run(FORWARD);          
  }

void Controller::move_B() {   //Operation to move the servo motor backward
  Serial.println("Backward");
  myMotor->run(BACKWARD);         
  }

void Controller::step_U() {   //Operation to move the stepper motor upwards
  Serial.println("Raise");
  Motor->step(10, FORWARD, MICROSTEP);
}

void Controller::step_D() {   //Operation to moce the stepper motor downwards
  Serial.println("Lower");
  Motor->step(10, BACKWARD, MICROSTEP);
}

int Controller::ReadInputs() {          //Operation to read the inputs
  CurForVal=digitalRead(Forwardpin);
  CurBackVal=digitalRead(Backwardpin);
  CurRaiseVal=digitalRead(Raisepin);
  CurLowerVal=digitalRead(Lowerpin);    //These digitalRead commands are used to check the current value of the input pins *i.e. high or low*
  
  if (!LastForVal && CurForVal) {     //Checks to see if there is a difference in the last known value and the current known value 
    LastForVal = CurForVal;           //Resets the last known value to the current known value to not have a loop created
    Serial.println("Recieved 1");     //This is for trouble shooting we can always remove it or comment it out
    move_F();                         //Runs the move forward command for the servo motors
    //delay(100);
    return 1;                         //ends the operation early
  }

  if (!LastBackVal && CurBackVal) {   //Checks to see if there is a difference in the last known value and the current known value
    LastBackVal = CurBackVal;         //Resets the last known value to the current known value to not have a loop created
    Serial.println("Recieved 2");     //This is for trouble shooting we can always remove it or comment it out
    move_B();                         //Runs the move Backward command for the servo motors
    //delay(100);
    return 1;                         //ends the operation early
  }

  if (!LastRaiseVal && CurRaiseVal) { //Checks to see if there is a difference in the last known value and the current known value
    LastRaiseVal=CurRaiseVal;         //Resets the last known value to the current known value to not have a loop created
    Serial.println("Recieved 3");     //This is for trouble shooting we can always remove it or comment it out
    step_U();                         //Runs the move Raise command for the stepper motors
    //delay(100);
    return 1;                         //ends the operation early
  }

  if (!LastLowerVal && CurLowerVal) { //Checks to see if there is a difference in the last known value and the current known value
    LastLowerVal=CurLowerVal;         //Resets the last known value to the current known value to not have a loop created
    Serial.println("Recieved 4");     //This is for trouble shooting we can always remove it or comment it out
    step_U();                         //Runs the move Raise command for the stepper motors
    //delay(100);
    return 1;                         //ends the operation early
  }

else {
    LastForVal = LOW;
    LastBackVal= LOW;
    LastRaiseVal = LOW;
    LastLowerVal = LOW;     //These 4 commands are used to reset the Last known Values of the input pins if they have been changed from an input
      return 0;             //Ends the operation loop
  }
}