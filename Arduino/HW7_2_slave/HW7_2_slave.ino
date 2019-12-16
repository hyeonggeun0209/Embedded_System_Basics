#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);
unsigned char c;

void setup() {
  
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop() {
  if(Serial.available()) {
    c = Serial.read();
    mySerial.write(c);
    Serial.write(c);
  } else if(mySerial.available()) {
    c = mySerial.read();
    Serial.write(c);
  }
}
