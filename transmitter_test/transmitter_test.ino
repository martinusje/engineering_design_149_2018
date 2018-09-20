#define TRANSMIT_PIN 5

int period = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRANSMIT_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRANSMIT_PIN, HIGH);
  delay(period/2);
  digitalWrite(TRANSMIT_PIN, LOW);
  delay(period/2);
}
