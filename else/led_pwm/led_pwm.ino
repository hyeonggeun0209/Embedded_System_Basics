const int led_pwm = 11;
const int led = 13;
unsigned long l3, l4;
unsigned long interval = 30;
int fDir = 0;
int fade = 0;
int fON = 0;
int i;

void setup() {
  // put your setup code here, to run once:
  l3 = 0;
  i = 0;
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  l4 = millis();
  if(l4 - l3 >= interval) {
    ++i;
    l3 = l4;
    if(i%51 == 0) {
      if(!fON) {
        fON = HIGH;
      } else {
        fON = LOW;
      }
      digitalWrite(led, fON);
    }
    if(!fDir) {
      fade += 5;
      if (fade >= 255) {
        fade = 255; fDir = 1;
      }
    } else {
      fade -= 5;
      if (fade <= 0) {
        fade = 0; fDir = 0;
      }
    }
    analogWrite(led_pwm,fade);
  }
}
