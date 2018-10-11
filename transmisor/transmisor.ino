#define JOYSTICK_1_X      A0
#define JOYSTICK_1_Y      A1
#define JOYSTICK_2_X      A2
#define JOYSTICK_2_Y      A3

#define BAUD_RATE     115200

#define CHAR_J1           'j'
#define CHAR_J2           'p'

int valores[4];


void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  valores[0] = analogRead(JOYSTICK_1_X);
  valores[1] = analogRead(JOYSTICK_1_Y);
  valores[2] = analogRead(JOYSTICK_2_X);
  valores[3] = analogRead(JOYSTICK_2_Y);

  //jvalores[0],va ....\n
  Serial.println(String(CHAR_J1)+String(valores[0])+","+String(valores[1]));
  delay(250);
  Serial.println(String(CHAR_J2)+String(valores[2])+","+String(valores[3]));
  delay(250);
}
