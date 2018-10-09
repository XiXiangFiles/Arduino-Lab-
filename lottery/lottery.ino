#include<Servo.h>
#include<stdio.h>
#include<string.h>
Servo myservo;
const int pinMoter=6;
const int pinMoter2=7;
const int pinServo=9;
const int pinRelay=8;
int looptimes=0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(pinServo);
  pinMode(pinRelay,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String flag = Serial.readString();
  flag.trim();  
  if(flag=="start"){
   looptimes=4; 
    }else if(flag=="close"){
      looptimes=0;
   }
  
  if(looptimes-- >0){
      Serial.println("it started");
      digitalWrite(pinRelay,LOW);
      myservo.write(10);
      delay(150);
      digitalWrite(pinRelay,HIGH);
      delay(1200);
      digitalWrite(pinRelay,LOW);
  }
  if(looptimes == 0){
    Serial.println("close");
    digitalWrite(pinRelay,LOW);
    myservo.write(150);
  } 
}
