void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(97);
  Serial.println(3.1415);
  Serial.println('a');
  Serial.println("hello");
  Serial.println(97, BIN);
  Serial.println(97, OCT);
  Serial.println(97, DEC);
  Serial.println(97, HEX);
  Serial.println(3.1415, 0);
  Serial.println(3.1415, 2);
  Serial.println(3.1415, 4);

  delay(1000);
}
