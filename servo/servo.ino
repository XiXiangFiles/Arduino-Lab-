#include<Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int angle;
  for(int i =500 ; i< 750 ; i++ ){
      int angle=map(i, 0, 1023, 0, 180);
      Serial.println(angle);
      delay(1000);
      myservo.write(angle);
    }
}
