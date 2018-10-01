void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  String flag = Serial.readString();
  flag.trim();
  if ( flag == "open") {
    Serial.println("open relay");
    digitalWrite(8, HIGH);
    delay(5000);
  } else {
    Serial.println("close relay");
    digitalWrite(8, LOW);
  }
}
