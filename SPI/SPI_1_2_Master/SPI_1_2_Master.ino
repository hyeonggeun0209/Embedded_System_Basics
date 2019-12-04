#include <SPI.h>
const int S1 = 10;
const int S2 = 9;

void setup() {
  // put your setup code here, to run once:

  SPI.begin();
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(S1, LOW);
  const byte *p1 = "Hello, S1!\n";
  for (int i = 0; i < strlen(p1); i++) {
    SPI.transfer(p1[i]);
  }
  digitalWrite(S1, HIGH);
  
  digitalWrite(S2, LOW);
  const byte *p2 = "Hello, S2!\n";
  for (int i = 0; i < strlen(p2); i++) {
    SPI.transfer(p2[i]);
  }
  digitalWrite(S2, HIGH);
  
  delay(1000);
}
