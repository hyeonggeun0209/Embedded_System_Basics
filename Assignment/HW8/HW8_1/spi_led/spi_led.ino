const byte pinLED = 8; // SPI slave LED
volatile byte data = 0;
volatile byte state = LOW;
int val = 0;
float set = 28.0;
volatile byte cur;

void setup() {
  // put your setup code here, to run once:
  pinMode(MISO, OUTPUT);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);
}

ISR(SPI_STC_vect) {
  cur = SPDR;
  if(set < cur) {
    state = HIGH;
  } else {
    state = LOW;
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(cur);
  digitalWrite(pinLED, state);
  
}
