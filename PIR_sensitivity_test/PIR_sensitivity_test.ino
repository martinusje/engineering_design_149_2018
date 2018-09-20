#define PIR_PIN 13

void setup() {
  // put your setup code here, to run once:
  pinMode(PIR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(PIR_PIN));
}
