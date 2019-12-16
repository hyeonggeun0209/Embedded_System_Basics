const byte pinLED = 13; // SPI slave LED
volatile byte data = 0;
volatile byte state = LOW;
int val = 0;
float set = 28.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MISO, OUTPUT);
  SPCR |= _BC(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);
}

ISR(SPI_STC_vect) {
  byte cur = SPDR;
  if(set < cur) {
    state = HIGH;
  } else {
    state = LOW;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(pinLED, state);
  if (digitalRead(SS) == HIGH) {
    command = 0;
  }
}
