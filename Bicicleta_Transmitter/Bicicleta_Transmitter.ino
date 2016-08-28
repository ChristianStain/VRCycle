#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int posicion;
int exceptionVel;
int exceptionVelAnterior = 0;
int pulso=1;
int potPin = 0;
int sensorPin = 1;
int varSensor;
int limitPin = 4;
int transmitterPin = 2;

void setup(){
  Serial.begin(9600);
  pinMode(limitPin,INPUT);
  pinMode(potPin,INPUT);
  mySwitch.enableTransmit(transmitterPin);  // Using Pin #2
}

void loop(){

  posicion = analogRead(potPin);  
  varSensor = analogRead(sensorPin);
  if(varSensor<1015)
    exceptionVel=1;
  Serial.println(varSensor);
  
  if(exceptionVel && exceptionVelAnterior==0){
      posicion=posicion+1000;
  }
  exceptionVelAnterior=exceptionVel;
  mySwitch.send(posicion, 12);
}
