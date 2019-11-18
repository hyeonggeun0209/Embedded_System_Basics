const int led_red = 13;
const int led_green = 12;
const int led_yellow = 8;
unsigned long l1, l2;
unsigned long interval = 1000;
int fON1 = LOW;
int fON2 = LOW;
int fON3 = LOW;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  l1 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();
  if (l2 - l1 >= interval) {
    ++i;
    l1 = l2;
    if(!fON1) {
      fON1 = HIGH;
    } else {
      fON1 = LOW;
    }
    digitalWrite(led_red, fON1);
    
    if(i % 2 == 0) {
        if(!fON2) {
          fON2 = HIGH;
      } else {
          fON2 = LOW;
      }  
    }
    digitalWrite(led_green, fON2);

    if(i % 3 == 0) {
        if(!fON3) {
          fON3 = HIGH;
      } else {
          fON3 = LOW;
      }  
    }
    digitalWrite(led_yellow, fON3);
  }
}
