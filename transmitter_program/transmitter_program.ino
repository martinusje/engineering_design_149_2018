#define TRANSMIT_PIN 5
#define PIR_PIN 13

void setup() {
  // put your setup code here, to run once:
  pinMode(TRANSMIT_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PIR_PIN)) {
    digitalWrite(TRANSMIT_PIN, HIGH);
  } else {
    digitalWrite(TRANSMIT_PIN, LOW);
  }
}
