#include <RH_ASK.h>
#include <SPI.h>

#define TRANSMIT_PIN 5
#define RECEIVE_PIN 2
#define PIR_PIN 6

RH_ASK driver(2000, RECEIVE_PIN, TRANSMIT_PIN);

const char *msg = "swimmer";
int previousState;
int currentState;

void setup() {
  // put your setup code here, to run once: 
  pinMode(PIR_PIN, INPUT);
   
  Serial.begin(9600);
  
  if (!driver.init())
    Serial.println("rf driver init failed");
}

void loop() {
  // put your main code here, to run repeatedly:
  previousState = currentState;
  currentState = digitalRead(PIR_PIN);
  if(currentState && !previousState) {
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(5000); //Wait for the swimmer to pass
  }
}
