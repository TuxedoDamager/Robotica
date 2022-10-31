//sensores
const int IN_A0 = A1;
const int IN_D0 = 2;
const int IN_A1 = A2;
const int IN_D1 = 3;

//motores
const int M1A = 5;
const int M1B = 6;
const int M2A = 9;
const int M2B = 10;

int value_A0; //sensor esquerda
int value_A1; //sensor direita
int value_D0;
int value_D1;
int vel_1 = 110;
int vel_2 = 120;
int vel_3 = 150;
int vel_4 = 180;
int vel_5 = 240;

void Frente () {
  analogWrite(M1A, 0);
  analogWrite(M1B, vel_1);
  analogWrite(M2A, 0);
  analogWrite(M2B, vel_1);
}

void Direita () {
  analogWrite(M1A, 0);
  analogWrite(M1B, vel_2);
  analogWrite(M2A, vel_2);
  analogWrite(M2B, 0);  
}


void Direita_Acentuada () {
  analogWrite(M1A, 0);
  analogWrite(M1B, vel_5);
  analogWrite(M2A, vel_5);
  analogWrite(M2B, 0);  
}

void Esquerda () {
  analogWrite(M1A, vel_2);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, vel_2);  
}

void Esquerda_Acentuada () {
  analogWrite(M1A, vel_5);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, vel_5);   
}

void setup() {
Serial.begin(9600);
pinMode (IN_A0, INPUT);
pinMode (IN_A1, INPUT);
pinMode (IN_D0, INPUT);
pinMode (IN_D1, INPUT); 

pinMode (M1A, OUTPUT);
pinMode (M1B, OUTPUT);
pinMode (M2A, OUTPUT);
pinMode (M2B, OUTPUT); 


}

void loop() {
if (value_A0 <= 40 && value_A1 <= 70) {
  Frente ();
  delay(5);
} else if (value_A0 > 45) {
  Esquerda ();
  delay(20);
} else if (value_A1 > 70 ) {
  Direita ();
  delay(20);

}

else if (value_A1 > 135) {
  Direita_Acentuada();
  delay(93);
} else if (value_A0 > 60) {
  Esquerda_Acentuada();
  delay(93); 
}


  
value_A0=analogRead(IN_A0);
value_A1=analogRead(IN_A1);
Serial.print(value_A0);
Serial.print("\t");
Serial.print(value_A1);
Serial.print("\t\t");
Serial.print(value_D0);
Serial.print("\t");
Serial.print(value_D1);
Serial.println();

delay(10);
}
