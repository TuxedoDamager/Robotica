#include <Servo.h>

#define IN0 A0
#define IN1 A1
#define IN2 A2
#define IN3 A3

Servo servo_9;
Servo servo_10;
Servo servo_11;
Servo servo_6;

// pwm 6  - garra
// pwm 9  - direita
// pwm 11 - esquerda
// pwm 10 - base
//
// digital 12    - s2
// digital 13    - s3
// digital pwm 3 - s0
// digital 4     - s1
// digital pwm 5 - out

int ini_1=0;
int ini_2=0;
int ini_3=0;
int ini_4=0;

void setup()
{
   
  Serial.begin(9600);
  servo_9.attach(9, 544, 2400);
  servo_10.attach(10, 500, 2500);
  servo_11.attach(11, 500, 2500);
  servo_6.attach(6, 500, 2500);
}

void mudar (Servo servo,int inicial, int final) {

   if(inicial < final) {
      for(int i=inicial; i<=final; i++){
         servo.write(i);
         delay(15);
      }
   } else {
      for(int i=inicial; i>=final; i--){
         servo.write(i);
         delay(15);
      }
    
   }
  
}


void loop()
{
  int valor1 = analogRead(IN0);
  int valor2 = analogRead(IN1);
  int valor3 = analogRead(IN2);
  int valor4 = analogRead(IN3);
  byte pos1 = map (valor1, 0, 1023, 0,179);
  byte pos2 = map (valor2, 0, 1023, 0,179);
  byte pos3  = map (valor3, 0, 1023, 0,179);
  byte pos4  = map (valor4, 0, 1023, 0,179);
  servo_9.write(pos2);
  servo_10.write(pos1);
  servo_11.write(pos3);
  servo_6.write(pos4);

   delay(50);
  Serial.print(pos1);
  Serial.print("  :  ");
  Serial.print(pos2);
  Serial.print("  :  ");
  Serial.print(pos3);
  Serial.print("  :  ");
  Serial.print(pos4);
  Serial.println();

 //posiciao inicial 
  pos1= 100;
  pos2=88;
  pos3=135;
  pos4=60;

  servo_9.write(pos2);
  servo_10.write(pos1);
  servo_11.write(pos3);
  servo_6.write(pos4);
  ini_1 = pos1;
  ini_2 = pos2;
  ini_3= pos3;
  ini_4= pos4;
 //================================================
//pegar peca
  delay(4000);
  pos1= 134;
  pos2= 165;
  pos3= 84;
  pos4= 43;
  mudar(servo_10,ini_1,pos1);
  mudar(servo_9,ini_2,pos2);
  mudar(servo_11,ini_3,pos3);
  mudar(servo_6,ini_4,pos4);
  ini_1 = pos1;
  ini_2 = pos2;
  ini_3= pos3;
  ini_4= pos4;

  delay(4000);
}

////soltar peca
//  delay(4000);
//  pos1= 150;
//  pos2= 150 ;
//  pos3= 140;
//  pos4= 83;
//  mudar(servo_10,ini_1,pos1);
//  mudar(servo_9,ini_2,pos2);
//  mudar(servo_11,ini_3,pos3);
//  mudar(servo_6,ini_4,pos4);
//  ini_1 = pos1;
//  ini_2 = pos2;
//  ini_3= pos3;
//  ini_4= pos4;
//
//  delay(8000); 
