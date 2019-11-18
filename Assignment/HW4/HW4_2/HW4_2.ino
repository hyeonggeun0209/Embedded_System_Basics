const int LEDR = 13;
const int LEDG = 12;
const int LEDB = 11;
const int pinTilt = 3;
int val = 0;
void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(pinTilt, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pinTilt);
  Serial.println(val);
  if(val == 1) {
    digitalWrite(LEDR,1);
    digitalWrite(LEDG,1);
    digitalWrite(LEDB,1);
  } else {
    digitalWrite(LEDR,0);
    digitalWrite(LEDG,0);
    digitalWrite(LEDB,0);
  }
  delay(500);
}
