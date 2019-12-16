char buf[100];
volatile byte pos = 0;
volatile boolean done = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
  SPCR &= ~_BV(MSTR);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
