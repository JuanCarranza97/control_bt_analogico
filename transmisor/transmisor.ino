#define JOYSTICK_1_X      A0
#define JOYSTICK_1_Y      A1
#define JOYSTICK_2_X      A3
#define JOYSTICK_2_Y      A5

#define BAUD_RATE     9600

#define CHAR_J1           'j'
#define CHAR_J2           'p'

int valores[4];

bool state = true;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(2,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
  /*if(digitalRead(2) == 0){
    digitalWrite(13,HIGH);
    Serial.println("Boton 1");
    while(digitalRead(2) == 0);
    digitalWrite(13,LOW);
    delay(50);
  }*/
  if(digitalRead(4) == 0){
    digitalWrite(13,HIGH);
    state = !state;
    if(state) Serial.println("j200,34");
    else      Serial.println("j22,34");
    delay(200);
    while(digitalRead(4) == 0);
    digitalWrite(13,LOW);
    delay(50);
  }
  //valores[0] = analogRead(JOYSTICK_1_X);
  //valores[1] = analogRead(JOYSTICK_1_Y);
  //valores[2] = analogRead(JOYSTICK_2_X);
  //valores[3] = analogRead(JOYSTICK_2_Y);

  //jvalores[0],va ....\n
  //Serial.println(String(CHAR_J1)+String(valores[0])+","+String(valores[1]));
  //delay(250);
  //Serial.println(String(CHAR_J2)+String(valores[2])+","+String(valores[3]));
  //delay(250);
}
