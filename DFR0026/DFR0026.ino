const int pinLight = 2;

int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(pinLight);

  Serial.println(val);

  delay(500);
}
