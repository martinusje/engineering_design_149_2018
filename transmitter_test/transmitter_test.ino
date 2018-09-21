#include <RH_ASK.h>
#include <SPI.h>

#define TRANSMIT_PIN 5

RH_ASK driver(2000, 2, TRANSMIT_PIN); // 200bps, TX on D3 (pin 2), RX on D4 (pin 3)
int period = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  if (!driver.init())
    Serial.println("rf driver init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
  const char *msg = "hello world";
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}
