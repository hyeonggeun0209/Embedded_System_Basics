#include <SPI.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);
}

byte transferAndWait(const byte what) {
  byte a = SPI.transfer(what);
  delayMicroseconds(20);
  return a;
  
}
void loop() {
  // put your main code here, to run repeatedly:
  byte s;
  digitalWrite(SS, LOW);

  transferAndWait('s');
  transferAndWait(0);
  s = transferAndWait(0);

  digitalWrite(SS, HIGH);

  Serial.println("Sensed data: ");
  Serial.println(s, DEC);
  delay(1000);
}
