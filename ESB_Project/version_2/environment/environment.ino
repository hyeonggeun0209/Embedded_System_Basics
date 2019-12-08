#include <dht11.h>

dht11 DHT11;
const int pinLM35 = 2;
const int pinRelay = 8;
const int pinPhoto = 4;
const int pinDHT11 = 7;
const int pinServo = 5;
const int pinTilt = 3;

Servo servo;
int tVal = 0;
bool IN = true;
byte window = 0;
int ret = 0;
int lightval = 0;
bool light = true;
int val = 0;
float tem = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(pinRelay,OUTPUT);
  servo.attach(pinServo);
  
}

void loop() {
  
  lightval = analogRead(pinPhoto); 
  val = analogRead(pinLM35);
  ret = DHT11.read(pinDHT11);
  tem = ((val * 5 * 100) / 1024.0);
  
  //if(light
  val>일정값){ // 밤 30
  // light = true; 
  //}
  //else{ light = false; } 
  
  Serial.print("light:");
  Serial.println(lightval);
  Serial.print("tem :");
  Serial.println(tem);
  Serial.print("Humidity (%) : ");
  Serial.println((float)DHT11.humidity, 2);  
 
  //18-25
  digitalWrite(pinRelay,HIGH);
  if(tem > 30){
    
    //if(!light){--> 5분만 환기 
    
    digitalWrite(pinRelay,HIGH);
    //창문도 열어줘야함
    
    servo.write(90);
    Serial.println("Open");
    Serial.println("Open Window");
    delay(1000);
    servo.write(0);//창문닫음
    
  }else if(tem < 26){
    
    digitalWrite(pinRelay,LOW);
    delay (1000);
    
  }
}
