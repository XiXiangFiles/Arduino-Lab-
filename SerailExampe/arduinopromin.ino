void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("open");
  delay(3000);
  Serial.println("close");
  delay(3000);
}
