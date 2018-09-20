#define RECEIVE_PIN 5

void setup() {
  // put your setup code here, to run once:
  pinMode(RECEIVE_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(RECEIVE_PIN));
}
