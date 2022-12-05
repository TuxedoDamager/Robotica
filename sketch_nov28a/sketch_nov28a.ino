#include <Servo.h>

#define IN1 A0
#define IN2 A1

Servo servo_9;
Servo servo_6;

void setup()
{
  servo_9.attach(9, 500, 2500);
  
}

void loop()
{
  int valor1 = analogRead(IN1);
  int valor2 = analogRead(IN2);
  byte pos1 = map (valor1, 0, 1023, 0,179);
  servo_9.write(pos1);
  
  delay(50);
  
}
