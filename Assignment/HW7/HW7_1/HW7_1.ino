const int pinRLED = 13;
const int pinGLED = 12;
const int pinBLED = 11;
byte c;
int r,g,b;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinRLED, OUTPUT);
  pinMode(pinGLED, OUTPUT);
  pinMode(pinBLED, OUTPUT);
  r = 0;
  g = 0;
  b = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if( Serial.available()) {
    c = Serial.read();

    switch(c) {
      
      case 'r':
        if(r == 0) {
          r = 1;
          digitalWrite(pinRLED, r);
          Serial.println("LED_R On");
          break;
        }else {
          r = 0;
          digitalWrite(pinRLED, r);
          Serial.println("LED_R Off");
          break;
        }
      case 'g':
        if(g == 0) {
          g = 1;
          digitalWrite(pinGLED, g);
          Serial.println("LED_G On");
          break;
        }else {
          g = 0;
          digitalWrite(pinGLED, g);
          Serial.println("LED_G Off");
          break;
        }
      case 'b':
        if(b == 0) {
          b = 1;
          digitalWrite(pinBLED, b);
          Serial.println("LED_B On");
          break;
        }else {
          b = 0;
          digitalWrite(pinBLED, b);
          Serial.println("LED_B Off");
          break;
        }
      
      
    }
  }
}
