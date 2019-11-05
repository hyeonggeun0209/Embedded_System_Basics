const int led = 13;
const int pinButton = 2;
boolean stateLED = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(pinButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pinButton) == HIGH) {
    stateLED = !stateLED;
    
    digitalWrite(led, stateLED);
  }
  delay(100);
}
