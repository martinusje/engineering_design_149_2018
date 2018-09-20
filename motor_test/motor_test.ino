#define MOTOR_PIN 6

int period = 2000;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MOTOR_PIN, HIGH);
  delay(period/2);
  digitalWrite(MOTOR_PIN, LOW);
  delay(period/2);
}
