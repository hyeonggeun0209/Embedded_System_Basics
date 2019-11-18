const int led_red = 11;
const int led_green = 10;
const int led_yellow = 9;
unsigned long l1, l2;
unsigned long interval = 40;
int fDir = 0;
int fade = 0;
int j = 0;


void setup() {
  // put your setup code here, to run once:
  l1 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();
  if (l2 - l1 >= interval) {
    l1 = l2;
    if (!fDir) {
        fade += 5;
        if (fade >= 255) {
          fade = 255;
          fDir = 1;
        }
      } else {
        fade -= 5;
        if (fade <= 0) {
          fade = 0;
          fDir = 0;
          j++;
        }
    }
    if(j%4 == 0) {
      analogWrite(led_red, fade);
      analogWrite(led_green, 0);
      analogWrite(led_yellow, 0);
    }
    if(j%2 == 1) {
      analogWrite(led_red, 0);
      analogWrite(led_green, fade);
      analogWrite(led_yellow, 0);
    }
    if(j%4 == 2) {
      analogWrite(led_red, 0);
      analogWrite(led_green, 0);
      analogWrite(led_yellow, fade);
    }
  }
}
