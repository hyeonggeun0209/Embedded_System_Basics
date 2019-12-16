#include <SPI.h> // SPI master
const int S1 = 10;
const int S2 = 9;
const int S3 = 8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
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
  digitalWrite(S1, LOW);
  
  transferAndWait('s');
  transferAndWait(0);
  s = transferAndWait(0);

  digitalWrite(S1, HIGH);

  Serial.println("Sensed temperature : ");
  Serial.println(s, DEC);

  
  digitalWrite(S2, LOW);
  
  transferAndWait(s);

  digitalWrite(S2, HIGH);


  /*digitalWrite(S3, LOW);
  
  transferAndWait(s);

  digitalWrite(S3, HIGH);*/


  delay(1000);
}
