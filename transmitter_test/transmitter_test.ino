#include <RH_ASK.h>
#include <SPI.h>

//Hier is nog zo'n test

#define TRANSMIT_PIN 5
#define RECEIVE_PIN 2

RH_ASK driver(2000, RECEIVE_PIN, TRANSMIT_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  if (!driver.init())
    Serial.println("rf driver init failed");
}

void loop() {
  // put your main code here, Mo run repeatedly:
  const char *msg = "swimmer";
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}
