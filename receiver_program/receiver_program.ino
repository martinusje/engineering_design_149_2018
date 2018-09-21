#include <RH_ASK.h>
#include <SPI.h>

#define TRANSMIT_PIN 8 //Incorrect! but needed because the motor is also on pin 5
#define RECEIVE_PIN 2
#define SHUT_PIN 4
#define MOTOR_PIN 5

RH_ASK driver(2000, RECEIVE_PIN, TRANSMIT_PIN);

int intensity = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(RECEIVE_PIN, INPUT);
  pinMode(SHUT_PIN, OUTPUT);
  digitalWrite(SHUT_PIN, LOW);
  
  Serial.begin(9600);
  
  if (!driver.init())
    Serial.println("rf driver init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN] = {0};
  uint8_t buflen = sizeof(buf);
 
  if (driver.recv(buf, &buflen)) // if message received, save it
  {
    Serial.println((char*)buf); // print received message
    if(buf == "swimmer") {
      vibrateMotor();
    }
  }
}

void vibrateMotor() {
  analogWrite(MOTOR_PIN, intensity);
  delay(1000);
  analogWrite(MOTOR_PIN, 0);
}

