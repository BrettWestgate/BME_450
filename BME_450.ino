#include "Controller.h"


#define Forward_Con 2 
#define Backward_Con 4
#define Raise_Con 7
#define Lower_Con 8 
#define Extra 1                                    //Defines which pins will be used

#include <Adafruit_MotorShield.h>


Adafruit_MotorShield AFMSStep = Adafruit_MotorShield(0x60);
Adafruit_MotorShield AFMSServ = Adafruit_MotorShield(0x61);
Adafruit_StepperMotor *Step1 = AFMSStep.getStepper(200, 1);
Adafruit_StepperMotor *Step2 = AFMSStep.getStepper(200, 2);    //Connects to Motorshield/Stepper motor
Adafruit_DCMotor *Servo1 = AFMSServ.getMotor(1); 
Adafruit_DCMotor *Servo2 = AFMSServ.getMotor(2); 
Adafruit_DCMotor *Servo3 = AFMSServ.getMotor(3); 
Adafruit_DCMotor *Servo4 = AFMSServ.getMotor(4); 

Controller ServoTR (0, Servo1, 4, 2, 1, 1);                       //Creates Instance in the motor class
Controller ServoBL (0, Servo3, 4, 2, 1, 1);
Controller ServoTL (0, Servo2, 2, 4, 1, 1);
Controller ServoBR (0, Servo4, 2, 4, 1, 1);
Controller StepL (Step1, 0, 1, 1, 7, 8);
Controller StepR (Step2, 0, 1, 1, 8, 7);

int M;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  if (!AFMSStep.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield 1. Check wiring.");
    while (1);
    }
  if (!AFMSStep.begin()) {         // create with the default frequency 1.6KHz
    // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield 2. Check wiring.");
    while (1);
    }
  Serial.println("Motor Shield found.");

  myMotor->setspeed(150)
  motor->setspeed(10)
  
  StepL.init_Move();
  StepR.init_Move();
  ServoTR.init_Move();
  ServoBR.init_Move();
  ServoTL.init_Move();
  ServoBL.init_Move();
  
}

void loop() {
  // put your main code here, to run repeatedly:
 //Motor.step(50, BACKWARD, DOUBLE);
  M=Controller.ReadInputs();                             //Checks if a front step input has been recieved
    //Motor.off();
    delay(250);
    PlotPins();
  }

void PlotPins() {
  Serial.print("V1:");
  Serial.print(digitalRead(Raise_Con));
  Serial.print(",");
  Serial.print("V2:");
  Serial.print(digitalRead(Lower_Con));
  Serial.print(",");
  Serial.print("V3:");
  Serial.print(digitalRead(Backward_Con));
  Serial.print(",");
  Serial.print("V4:");
  Serial.println(digitalRead(Forward_Con));
}