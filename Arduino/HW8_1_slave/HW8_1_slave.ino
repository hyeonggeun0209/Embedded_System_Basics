volatile byte command = 0; // SPI slave LM35
volatile byte data = 0;
const byte pinLM35 = 2;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MISO, OUTPUT);
  SPCR |= _BC(SPE);
  SPCR &= ~_BV(MSTR);
  SPCR |= _BV(SPIE);
}

ISR(SPI_STC_vect) {
  byte c = SPDR;
  swithch(command) {
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
  val = analogRead(pinLM35) * 5 * 100 / 1024.0;
  data = (byte)val;
  if (digitalRead(SS) == HIGH) {
    command = 0;
  }
}
