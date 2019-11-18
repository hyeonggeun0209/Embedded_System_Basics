const int led1=8;

const int led2=9;

const int led3=10;

const int pinTrig = 2;

const int pinEcho = 4;

int rangeMax = 200;

int rangeMin = 0;

long T, L;

void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(pinTrig, OUTPUT);

  pinMode(pinEcho, INPUT);

  pinMode(led1,OUTPUT);

  pinMode(led2,OUTPUT);

  pinMode(led3,OUTPUT);

}

 

void loop() {

  // put your main code here, to run repeatedly:

  digitalWrite(pinTrig, LOW); delayMicroseconds(2);

  digitalWrite(pinTrig, HIGH); delayMicroseconds(10);

  digitalWrite(pinTrig, LOW);

 

  T = pulseIn(pinEcho, HIGH);

  L = T/58.82;

  if(L>0&&L<10){

    digitalWrite(led1,1);

    digitalWrite(led2,0);

    digitalWrite(led3,0);

  }else if(L>=10&&L<15){

    digitalWrite(led1,0);

    digitalWrite(led2,1);

    digitalWrite(led3,0);

  }else if(L>=15&&L<30){

    digitalWrite(led1,0);

    digitalWrite(led2,0);

    digitalWrite(led3,1);

  }else{

    digitalWrite(led1,0);

    digitalWrite(led2,0);

    digitalWrite(led3,0);

  }

    delay(100);

}
