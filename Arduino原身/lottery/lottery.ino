#include<Servo.h>
#include<stdio.h>
#include<string.h>
Servo myservo;
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
   looptimes=3; 
    }else if(flag=="close"){
      looptimes=0;
   }else if(flag == "ready"){
      myservo.write(10);
    }
  
  if(looptimes-- >0){
      Serial.println("it started");
      digitalWrite(pinRelay,LOW);
      myservo.write(95);
      delay(100);
      digitalWrite(pinRelay,HIGH);
      delay(1000);
      digitalWrite(pinRelay,LOW);
  }
  if(looptimes == 0){
    Serial.println("close");
    myservo.write(150);
    delay(1000);
    digitalWrite(pinRelay,LOW);
  } 
}
