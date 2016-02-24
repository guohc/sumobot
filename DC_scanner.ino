int ENA = 5; //connected to Arduino's port 5(output pwm)
int IN1 = 2; //connected to Arduino's port 2
int IN2 = 3; //connected to Arduino's port 3
unsigned long previousMillis = 0;
unsigned long currentMillis;
void setup() {
  pinMode(ENA, OUTPUT); //output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  unsigned long previousMillis = 0;
  analogWrite(ENA, 255); //start driving motorA
}

void loop() {
  currentMillis = millis();

  if (currentMillis - previousMillis >= 250 && currentMillis - previousMillis < 300) {
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, HIGH);
    previousMillis = currentMillis;
  }

  if (currentMillis - previousMillis >= 300 && currentMillis - previousMillis < 550) {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    previousMillis = currentMillis;
  }

  if (currentMillis - previousMillis >= 550 && currentMillis - previousMillis < 600) {
    previousMillis = currentMillis;
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, HIGH);
    previousMillis = currentMillis;
  }

  if (currentMillis - previousMillis >= 600) {
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    previousMillis = currentMillis;
  }
}
