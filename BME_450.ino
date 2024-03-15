#include "Controller.h"


#define Forward_Con 2 
#define Backward_Con 4
#define Raise_Con 7
#define Lower_Con 8                       //Defines which pins will be used
#define Extra 1                           //This doesn't matter it's only there as an extra unused pin        

#include <Adafruit_MotorShield.h>

const int LED_Power = 12;
const int LED_Control = 11;

Adafruit_MotorShield AFMSStep = Adafruit_MotorShield(0x60);     //Sets up the Stepper motor shield
Adafruit_MotorShield AFMSServ = Adafruit_MotorShield(0x61);     //Sets up the Servo motor shield
Adafruit_StepperMotor *Step1 = AFMSStep.getStepper(200, 1);
Adafruit_StepperMotor *Step2 = AFMSStep.getStepper(200, 2);     //These 2 commands assign the 2 stepper motors to individual ports
Adafruit_DCMotor *Servo1 = AFMSServ.getMotor(1); 
Adafruit_DCMotor *Servo2 = AFMSServ.getMotor(2); 
//Adafruit_DCMotor *Servo3 = AFMSServ.getMotor(3);    
//Adafruit_DCMotor *Servo4 = AFMSServ.getMotor(4);                //These 4 commands assign the 4 servo motors to individual ports 

Controller ServoTR (0, Servo1, 4, 2, 1, 1);                       
//Controller ServoBL (0, Servo3, 4, 2, 1, 1);       //These create instances of the two motors that will be spinning in the same direction
Controller ServoTL (0, Servo2, 2, 4, 1, 1);
//Controller ServoBR (0, Servo4, 2, 4, 1, 1);       //These create instances of the two motors that will be spinning in the same direction
Controller StepL (Step1, 0, 1, 1, 7, 8);
Controller StepR (Step2, 0, 1, 1, 8, 7);          //These create instances of the two stepper motors in the Controller class

int A;
int B;
int C;
int D;
//int E;
//int F;  //These 6 commands don't matter too much and are used to speed up the process of reading inputs *explained later*

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  pinMode(LED_Power, INPUT);
  pinMode(LED_Control, OUTPUT);

  if (!AFMSStep.begin()) {                                            // create with the default frequency 1.6KHz
    Serial.println("Could not find Motor Shield 1. Check wiring.");
    while (1);
    }                                                                 //These commands run the check for the motorshield controlling the servo motors

  if (!AFMSStep.begin()) {                                            // create with the default frequency 1.6KHz
    Serial.println("Could not find Motor Shield 2. Check wiring.");
    while (1);
    }                                                                 //These commands run the check for the motorshield controlling the stepper motors
  Serial.println("Motor Shield found."); //We see this it means that both motorshields are operating correctly

  Servo1->setSpeed(150);
  Servo2->setSpeed(150);
  //Servo3->setSpeed(150);
  //Servo4->setSpeed(150);      //Default speed for the servo motors
  Step1->setSpeed(10);        //Stepper motors run at a different speed
  Step2->setSpeed(10);        //These just set the speeds of the individual motors *These are the default speeds we can change if we want*
  
  StepL.init_Move();
  StepR.init_Move();
  ServoTR.init_Move();
  //ServoBR.init_Move();
  ServoTL.init_Move();
  //ServoBL.init_Move();      //These commands start the initiation operation for the motors to assign all their pins as inputs
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(LED_Power == HIGH)) {
    digitalWrite(LED_Control, HIGH);
  }                             //This is what is going to control our LEDs both on and off 
  A=StepL.ReadInputs();         //Begins the ReadInputs operation to check if a command has come and the state has changed in the input pins
  B=StepR.ReadInputs();
  C=ServoTR.ReadInputs();
  D=ServoTL.ReadInputs();
  //E=ServoBR.ReadInputs();
  //F=ServoBL.ReadInputs();       //The integers ("A","B",etc) are returned as 1 or 0 depending on if a state change has occured in the .ccp code 
    //Motor.off();
    delay(250);
    //PlotPins();   //This operation is shown below and just allows us to see how the states in the pins are changing in response to the user input
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
