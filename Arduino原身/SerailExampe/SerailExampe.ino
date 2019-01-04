void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String flag = Serial.readString();
    flag.trim();
    if ( flag == "open") {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (flag == "close") {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
