const int pinLED[6] = {8, 9, 10, 11, 12, 13};
const int pinButton[6] = {2, 3, 4, 5, 6, 7};
boolean lastButton[6] = {LOW, LOW, LOW, LOW, LOW, LOW};
boolean currentButton[6] = {LOW, LOW, LOW, LOW, LOW, LOW};
boolean ledMode[6] = {LOW, LOW, LOW, LOW, LOW, LOW};

void setup() {
  pinMode(pinLED[0], OUTPUT);
  pinMode(pinLED[1], OUTPUT);
  pinMode(pinLED[2], OUTPUT);
  pinMode(pinLED[3], OUTPUT);
  pinMode(pinLED[4], OUTPUT);
  pinMode(pinLED[5], OUTPUT);
  pinMode(pinButton[0], INPUT);
  pinMode(pinButton[1], INPUT);
  pinMode(pinButton[2], INPUT);
  pinMode(pinButton[3], INPUT);
  pinMode(pinButton[4], INPUT);
  pinMode(pinButton[5], INPUT);
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
  for (int i = 0; i < 6; i++) {
    currentButton[i] = debounce(lastButton[i], pinButton[i]);
  }
  for (int i = 0; i < 6; i++) {
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
  digitalWrite(pinLED[3],A[3]);
  digitalWrite(pinLED[4],A[4]);
  digitalWrite(pinLED[5],A[5]);
}
