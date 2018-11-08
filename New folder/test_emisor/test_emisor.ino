#define analog A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}

void loop() {
  if(analogRead(analog) > 512){
    for(int i = 0;i<5;i++){
      digitalWrite(13,HIGH);
      delay(100);
      digitalWrite(13,LOW);
      delay(100);
    }
    digitalWrite(13,HIGH);
    while(analogRead(analog) > 512);
    delay(1000);
    digitalWrite(13,LOW);
  }
}
