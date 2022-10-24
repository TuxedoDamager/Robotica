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

void Frente () {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}

void Direita () {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);  
}

void Esquerda () {
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);  
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
//while (IN_A0 > 170) {
//  Esquerda ();
//}
//while (IN_A1 > 170) {
//  Direita ();
//}
if (IN_A0 < 170 && IN_A1 < 170) {
  Frente ();
} else if (IN_A0 > 170) {
  Esquerda ();
} else if (IN_A1 > 170) {
  Direita ();
}
  
value_A0=analogRead(IN_A0);
value_A1=analogRead(IN_A1);
value_D0=digitalRead(IN_D0);
value_D1=digitalRead(IN_D1);
Serial.print(value_A0);
Serial.print("\t");
Serial.print(value_A1);
Serial.print("\t\t");
Serial.print(value_D0);
Serial.print("\t");
Serial.print(value_D1);
Serial.println();
}
