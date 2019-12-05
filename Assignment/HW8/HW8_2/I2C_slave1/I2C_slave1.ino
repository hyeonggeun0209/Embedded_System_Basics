#include <Wire.h> // I2C Slave LM35

#define sv1 8

const int pinLM35 = 2;
byte data = 0;
int val;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(sv1);
  Wire.onRequest(requestEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pinLM35) * 5 * 100 / 1024.0;
  data = (byte)val;
}
void requestEvent(){
  Wire.write(data);
}
