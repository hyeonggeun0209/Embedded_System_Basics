const int pinTilt = 3;

int tVal = 0;
bool IN = true;

void setup() {
  
  pinMode(pinTilt,INPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  tVal = digitalRead(pinTilt);
  
  if(tVal == 1){ //실버다리로기울었을때 열린걸로 
    
    IN = false;
    Serial.println("IN");
    
  }else{
    
    IN = true;
    Serial.println("OUT");
    
  }
  
  delay(1000);

}
