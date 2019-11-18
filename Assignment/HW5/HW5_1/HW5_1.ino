const int pinVibM = 3;

byte count = 0;

const int led1=8;

const int led2=9;

const int led3=10;

 

void setup() {

  // put your setup code here, to run once:

  pinMode(pinVibM, INPUT);

  Serial.begin(9600);

  attachInterrupt(1,countVib,FALLING);

  pinMode(led1,OUTPUT); 

  pinMode(led2,OUTPUT); 

  pinMode(led3,OUTPUT);

}

 

void loop() {

  // put your main code here, to run repeatedly:

  if(count !=0){

    count =0;

    digitalWrite(led1,1);

    digitalWrite(led2,1);

    digitalWrite(led3,1);

    delay(100);

  }else{

    digitalWrite(led1,0);

    digitalWrite(led2,0);

    digitalWrite(led3,0);

    delay(100);

  }

}

 

void countVib(){

   count++;

}
