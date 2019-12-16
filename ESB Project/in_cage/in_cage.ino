#include <dht11.h>
#include <Servo.h>

const int pinTilt = 7;
const int pinServo = 5;
const int pinPIR = 4;
const int pinDht11 = 2;
unsigned long l1,l2;
unsigned long interval = 15000;
int fd = 0;

int tVal = 0;
int pVal =0;
Servo servo;
dht11 DHT11;
int ret;
int Change = 75.00;

void setup() {
  l1 = 0;
  pinMode(pinTilt,INPUT);
  pinMode(pinPIR,INPUT);
  Serial.begin(9600);
  servo.attach(pinServo);
}

void loop() {
  l2 = millis();
  if(!checkIn()){
    //열림 -> 작동들 안해도 됨 
    //열림 상태 알려주기 
  }else{
    if((l2-l1>interval) && fd == 0){
      l1=12;
      fd++;
      food();
    }
    ret = DHT11.read(pinDht11);
    checkPee();
    pirCheck();
    
  }
}

bool checkIn(){
   tVal = digitalRead(pinTilt);
  if(tVal == 1){//실버다리로기울었을때 열린걸로 
    return false;
    Serial.println("IN");
  }else{
    return true;
    Serial.println("OUT");
  }
  delay(100);
}

void checkPee(){
  Serial.print("Humidity (%) : ");
  Serial.println((float)DHT11.humidity, 2);
 if((float)DHT11.humidity>Change){
  Serial.println("Change Pad");
 }
   delay(1000);
}

void pirCheck(){
  pVal = digitalRead(pinPIR);
  if(pVal ==1){
    Serial.println("NOT SLEEPING");
  }else{
    Serial.println("SLEEPING");
  }
  Serial.println(pVal);
  delay(1000);
}

void food(){
  Serial.println("Time to Eat!");
  servo.write(135);
  delay(2000);
  servo.write(0);
}
