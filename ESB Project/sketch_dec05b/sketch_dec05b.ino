const int pinTrig1 = 2;
const int pinEcho1 = 4;
const int pinINT = 3;
const int pinTrig2 = 5;
const int pinEcho2 = 7;
const int pinButton = 6;
const int pinLED = 8;
const int pinBuzzer = 9;
const int pinVib = 10;

volatile byte mode = LOW; //매니저모드 평상시 LOW
volatile byte state = LOW;
boolean currentButton = LOW;
boolean lastButton = LOW;

int rangeMax = 200;
int rangeMin = 0;
long T, T2, L, L2;

// 매니저모드 -> 해제 버튼 누르면 소리 중지

void setup() {

  Serial.begin(9600);

  pinMode(pinTrig1, OUTPUT);

  pinMode(pinEcho1, INPUT);

  pinMode(pinTrig2, OUTPUT);

  pinMode(pinEcho2, INPUT);

  pinMode(pinLED, OUTPUT);

  pinMode(pinBuzzer, OUTPUT); // C D E F G A B C
  
  pinMode(pinVib, INPUT);

  pinMode(pinINT, INPUT_PULLUP);
  
  pinMode(pinButton, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(pinINT), turnoff , FALLING);
  
}

void loop() {
  currentButton = debounce(lastButton); // debounce
  
  //if (관리자모드 ON)버튼이 눌렸을 때 
  if(currentButton == HIGH && lastButton == LOW){
    mode = HIGH;
  }
  lastButton = currentButton;
  
  if(state) {
    
    tone(pinBuzzer, 523); // C

    digitalWrite(pinLED, HIGH);
  } else {
    
    noTone(pinBuzzer); // digitalWrite(pinBuzzer, LOW);

    digitalWrite(pinLED, LOW);
  }
  
  if(mode) {
    
    digitalWrite(pinTrig1, LOW); delayMicroseconds(2);

    digitalWrite(pinTrig1, HIGH); delayMicroseconds(10);

    digitalWrite(pinTrig1, LOW);

    T = pulseIn(pinEcho1, HIGH);
  
    L = T/58.82;
    
    digitalWrite(pinTrig2, LOW); delayMicroseconds(2);

    digitalWrite(pinTrig2, HIGH); delayMicroseconds(10);

    digitalWrite(pinTrig2, LOW);
    
    T2 = pulseIn(pinEcho2, HIGH);
  
    L2= T2/58.82;

    Serial.print("L :");
    Serial.println(L);
    Serial.print("L2 :");
    Serial.println(L2);
      
    delay(1000);
  }
  
}

//버튼 해제 눌리면 모두 중단
void turnoff() {
  
  mode = LOW;
  state = LOW;
  
}

boolean debounce(boolean last) {
  boolean current = digitalRead(pinButton);
  if (current != last) {
    delay(5);
    current = digitalRead(pinButton);
  }
  return current;
}
