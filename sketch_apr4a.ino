char angle = "";

long previousMillis = 0;
long interval = 10000;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void loop() {
  unsigned long currentMillis = millis();

  if (Serial.available()) {
    angle = (char)Serial.read();

    // if(strlen(angle) < 1)
    //   return false;

    Serial.println(angle);

    if (angle == 'a') {
      Serial.println("a geldi");
      previousMillis = currentMillis;
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
    } else if (angle == 'b') {
      Serial.println("b geldi");
      previousMillis = currentMillis;
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    } else if (angle == 'c') {
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
    }
  }

  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  }

}  //loop
