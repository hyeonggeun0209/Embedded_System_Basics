const int pinBuzzer = 3;
const int pinButton[8]={6,7,8,9,10,11,12,13};

void setup() {
                             
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinButton[0],INPUT);
  pinMode(pinButton[1],INPUT);
  pinMode(pinButton[2],INPUT);
  pinMode(pinButton[3],INPUT);
  pinMode(pinButton[4],INPUT);
  pinMode(pinButton[5],INPUT);
  pinMode(pinButton[6],INPUT);
  pinMode(pinButton[7],INPUT);
 
}




void loop() {
  if (digitalRead(pinButton[0])==HIGH) {
    tone(pinBuzzer, 262); // C
    
    } else if (digitalRead(pinButton[1])==HIGH) {
    tone(pinBuzzer, 294); // D
    
    } else if (digitalRead(pinButton[2])==HIGH) {
    tone(pinBuzzer, 330); // E
    
    } else if (digitalRead(pinButton[3])==HIGH) {
    tone(pinBuzzer, 349); // F
    
    } else if (digitalRead(pinButton[4])==HIGH) {
    tone(pinBuzzer, 392); // G
    
    } else if (digitalRead(pinButton[5])==HIGH) {
    tone(pinBuzzer, 440); // A
    
    } else if (digitalRead(pinButton[6])==HIGH) {
    tone(pinBuzzer, 494); // B
    
    } else if (digitalRead(pinButton[7])==HIGH) {
    tone(pinBuzzer, 523); // C
    
    } else
    noTone(pinBuzzer); // digitalWrite(pinBuzzer, LOW);
    
    Serial.println(0);delay(100);
}
