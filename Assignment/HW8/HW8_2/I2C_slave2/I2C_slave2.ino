#include <Wire.h> // I2C Slave LED

#define sv2 9

const int pinR = 3;
float set = 26.0;
float d = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(sv2);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(pinR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(d > set){
    digitalWrite(pinR, HIGH);
    }
  else {
    digitalWrite(pinR, LOW);
    }
    
}

void receiveEvent(int howMany) {
  while(Wire.available()>0){
   d = Wire.read();
   Serial.println(d);
  }
}
