#define RECEIVE_PIN 5
#define MOTOR_PIN 6

int intensity = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(RECEIVE_PIN, INPUT);
  pinMode(RECEIVE_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(RECEIVE_PIN)) {
    analogWrite(MOTOR_PIN, intensity);
  } else {
    analogWrite(MOTOR_PIN, 0);
  }
}
