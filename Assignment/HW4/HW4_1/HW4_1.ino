const int pinLM35 = 0;
const int LEDR = 13;
const int LEDG = 12;
const int LEDB = 11;
int val = 0;

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(pinLM35);
  float temp = val * 5 * 100 / 1024.0;
  Serial.println(temp);
  if(temp > 29) {
    digitalWrite(LEDR,1);
    digitalWrite(LEDG,0);
    digitalWrite(LEDB,0);
  } else {
    digitalWrite(LEDR,0);
    digitalWrite(LEDG,0);
    digitalWrite(LEDB,1);
  }
  delay(500);
}
