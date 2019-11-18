const int pinLED[3] = {8, 9, 10};
const int pinButton[3] = {2, 3, 4};
boolean lastButton[3] = {LOW, LOW, LOW};
boolean currentButton[3] = {LOW, LOW, LOW};
boolean ledMode[3] = {LOW, LOW, LOW};

void setup() {
  pinMode(pinLED[0], OUTPUT);
  pinMode(pinLED[1], OUTPUT);
  pinMode(pinLED[2], OUTPUT);
  pinMode(pinButton[0], INPUT);
  pinMode(pinButton[1], INPUT);
  pinMode(pinButton[2], INPUT);
}

boolean debounce(boolean last, int pin) {
  boolean current = digitalRead(pin);
  if (current != last) {
    delay(5);
    current = digitalRead(pin);
  }
  return current;
}
void loop() {
  for (int i = 0; i < 3; i++) {
    currentButton[i] = debounce(lastButton[i], pinButton[i]);
  }
  for (int i = 0; i < 3; i++) {
    if (currentButton[i] == HIGH && lastButton[i] == LOW) {
      ledMode[i] = !ledMode[i];
    }
    lastButton[i] = currentButton[i];
    setMode(ledMode);
  }
}
void setMode(boolean A[]) { 
  digitalWrite(pinLED[0],A[0]);
  digitalWrite(pinLED[1],A[1]);
  digitalWrite(pinLED[2],A[2]);
}
