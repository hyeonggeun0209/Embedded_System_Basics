const int pinLED = 13;
const int pinButton = 2;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean stateLED = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(pinButton);
  if (current != last) {
    delay(5);
    current = digitalRead(pinButton);
  }
  return current;
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);
  if (currentButton==HIGH && lastButton==LOW) {
    stateLED = !stateLED; 
  }
  lastButton = currentButton;
  digitalWrite(pinLED, stateLED);
}
