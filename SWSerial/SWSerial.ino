#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);
byte b;
byte c;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    c = Serial.read();
    mySerial.write(c);
    Serial.write(c);
    //Serial.write("\n");
  }
  if (mySerial.available()) {
    b = mySerial.read();
    Serial.write(b);
    
  }
}
