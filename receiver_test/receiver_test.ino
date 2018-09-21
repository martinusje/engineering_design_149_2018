#include <RH_ASK.h>
#include <SPI.h>

#define TRANSMIT_PIN 8 //Incorrect! but needed because the motor is also on pin 5
#define RECEIVE_PIN 2
#define SHUT_PIN 4

RH_ASK driver(2000, RECEIVE_PIN, TRANSMIT_PIN);

void setup() {
  // put your setup code here, to run once:
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
  }
}
