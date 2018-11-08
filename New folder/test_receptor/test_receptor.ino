int count,character;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}

void loop() {
  if(Serial.available()){
    count = 1;
    character = Serial.read();
    while(Serial.available()){
      character = Serial.read();
      count++;
    }
    for(int i = 0;i<count;i++){
      digitalWrite(13,HIGH);
      delay(250);
      digitalWrite(13,LOW);
      delay(250);
    }
  }
}
