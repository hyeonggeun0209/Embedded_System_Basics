const int S1 = 10;
volatile byte command = 0; // SPI slave LM35
volatile byte data = 0;
const int pinLM35 = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);
}

ISR(SPI_STC_vect) {
  byte c = SPDR;
  switch(command) {
    case 0:
      command = c;
      SPDR = 0;
      break;

    case 's':
      SPDR = data;
      break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  data = (byte)analogRead(pinLM35) * 5 * 100 / 1024.0;
  if (digitalRead(S1) == HIGH) {
    command = 0;
  }
}
