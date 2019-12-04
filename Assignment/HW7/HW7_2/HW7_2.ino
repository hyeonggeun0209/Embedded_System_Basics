#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);
unsigned char c;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    c = Serial.read();
    mySerial.write(c);
    Serial.write(c);
    
  } else if(mySerial.available()) {
    c = mySerial.read();
    Serial.write(c);
  }
}
