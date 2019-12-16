#include <dht11.h>

const int pinLM35 = 2;
const int pinRelay = 8;
const int pinPhoto = 4;
const int pinDHT11 = 7;
int ret;
dht11 DHT11;
int lightval = 0;
bool light = true;
int val = 0;
float tem = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinRelay,OUTPUT);
}

void loop() {
 lightval = analogRead(pinPhoto); 
 val = analogRead(pinLM35);
 ret = DHT11.read(pinDHT11);
 tem = ((val*5*100)/1024.0);
 //if(ligthval>일정값){ // 밤 30
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
  Serial.println("Open Window");
  delay(1000);
 }else if(tem < 26){
  digitalWrite(pinRelay,LOW);
  delay (1000);
 }
}
