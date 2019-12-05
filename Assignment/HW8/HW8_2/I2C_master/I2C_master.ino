#include <Wire.h> // I2C Master

#define sv1 8
#define sv2 9

byte i = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(sv1, 1);

  while (Wire.available()) {
    Serial.print("Sensed data: ");
    
    i = Wire.read();

    Serial.println(i);
    
  }

  Wire.beginTransmission(sv2);

  Wire.write(i);
  Wire.endTransmission();
  
  delay(1000);
} 
