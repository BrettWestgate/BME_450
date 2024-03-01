#include "Motor.h"


Light_Motor::Light_Motor(Adafruit_StepperMotor* StepMotor, Adafruit_DCMotor *DCMotor, byte Downpin, byte Uppin, byte Forwardpin, byte Backwardpin, byte Homepin) {      
  this->PlethMotor = PlethMotor;
  this->Downpin = Downpin;            //Assigns the variable to it's own changing value
  this->Uppin = Uppin;
  this->Forwardpin = Forwardpin;               //Assigns the variable to it's own changing value
  this->Backwardpin = Backwardpin;
  init_Pleth();                                     //Starts the initiation/Pin out set up method
}

Light_Motor::Light_Motor() {
  this->Downpin = 8;            //Assigns the variable to it's own changing value
  this->Uppin = 7;
  this->Forwardpin = 2;               //Assigns the variable to it's own changing value
  this->Backwardpin = 4;
  init_Pleth();
}

void Pleth_Motor::init_Pleth() {              
  pinMode(Uppin, INPUT);               //Assigns the pin out to the output signals
  pinMode(Downpin, INPUT);               //Assigns the pin out to the output signals
  pinMode(Forwardpin, INPUT);                        //Assigns pins as input pins
  pinMode(Backwardpin, INPUT);                        //Assigns pins as input pins
  pinMode(Homepin, INPUT); 
  LastForVal = LOW;
  LastBackVal= LOW;
  LastUpVal = LOW;
  LastDownVal = LOW;
                                        
}
void Pleth_Motor::move_F() {
  
}

void Pleth_Motor::move_B() {
  
}

void Pleth_Motor::step_U() {
  Serial.println("Step Up");
  PlethMotor->step(50, FORWARD, MICROSTEP);          //Object takes one turn forward
}

void Pleth_Motor::step_D() {
  Serial.println("Step Down");
  PlethMotor->step(50, BACKWARD, MICROSTEP);         //Object takes one turn backward
}

//void Pleth_Motor::off() {
  //digitalWrite(pinFLabView, LOW);             //Relays that motor is now off and not moving
  //digitalWrite(pinBLabView, LOW);             //Relays that motor is now off and not moving
//}

}

int Pleth_Motor::ReadInputs() {
  CurForVal=digitalRead(Forwardpin);
  CurBackVal=digitalRead(Backwardpin);
  CurUpVal=digitalRead(Uppin);
  CurDownVal=digitalRead(Downpin);
  
  if (!LastForVal && CurForVal) {
    LastForVal = CurForVal;
    move_F();
    //delay(100);
    Serial.println("Forward");
    return 1;
  }
    
  else if (!LastBackVal && CurBackVal) {
    LastBackVal = CurBackVal;
    move_B(); 
    //delay(100);
    Serial.println("Backward");
    return 1;
  }
    
  else if (!LastUpVal && CurUpVal) {
    LastUpVal = CurUpVal;
    step_U();
    Serial.println("Up");
    return 1;    
  }
    
  else if (!LastDownVal && CurDownVal) {
    LastDownVal = CurDownVal;
    step_D();
    Serial.println("Down");
    return 1;
  }
    
  else {
    LastForVal = LOW;
    LastBackVal= LOW;
    LastUpVal = LOW;
    LastDownVal = LOW;
      return 0;
  }
}
