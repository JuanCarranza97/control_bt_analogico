#include "UART.h"
#include <Servo.h>

#define CHAR_J1               'j'
#define CHAR_J2               'p'

Servo direccion;
#define SERVO_DIRECCION_PIN    3
#define LED_PIN                5
void setup() {
  uart_init();
  direccion.attach(SERVO_DIRECCION_PIN);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  if(UART_PORT.available()){
    //j345,234\n
      char caracter;
      int Numbers[20];
      int bufferSize=0;

        if(uart_get(&caracter,&bufferSize,Numbers)){
          if(bufferSize != 2){
            //Serial.println("BufferSize no corresponde :C");
          }
          else{
            switch(caracter){
              case CHAR_J1:
                int intensidad;
                intensidad = map(Numbers[1],0,1023,0,255);
                analogWrite(LED_PIN,intensidad);
                //Serial.println("La intensidad es "+String(intensidad));
                //Serial.println("Se recibio en J1 x = "+String(Numbers[0])+", y = "+String(Numbers[1]));
                break;
              case CHAR_J2:
                //Serial.println("Se recibio en J2 x = "+String(Numbers[0])+", y = "+String(Numbers[1]));
                int posicion;
                posicion = map(Numbers[0],0,1023,0,180);
                direccion.write(posicion);
                //Serial.println("Servo en posicion "+String(posicion));
                
                break;
              default:
                //Serial.println("Joystick no reconocido");
                break;
           }
          }          
        }  
      }
      

}
