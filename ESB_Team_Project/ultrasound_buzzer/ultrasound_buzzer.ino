const int pinBuzzer = 3;

const int pinTrig = 2;

const int pinEcho = 4;

const int pinLED = 8; 

int rangeMax = 200;

int rangeMin = 0;

long T, L;

void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(pinTrig, OUTPUT);

  pinMode(pinEcho, INPUT);

  pinMode(pinLED, OUTPUT);

  pinMode(pinBuzzer, OUTPUT); //C D E F G A B C

}

void loop() {

  // put your main code here, to run repeatedly:

  digitalWrite(pinTrig, LOW); delayMicroseconds(2);

  digitalWrite(pinTrig, HIGH); delayMicroseconds(10);

  digitalWrite(pinTrig, LOW);

  T = pulseIn(pinEcho, HIGH);

  L = T/58.82;

  if(L>0&&L<10){
    
    tone(pinBuzzer, 523); // C

    digitalWrite(pinLED, HIGH);
    
  }else{
    
    noTone(pinBuzzer); // digitalWrite(pinBuzzer, LOW);

    digitalWrite(pinLED, LOW);
    
  }
  
    delay(100);
    
}
