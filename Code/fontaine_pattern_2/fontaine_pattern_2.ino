int ENA = 5;
int IN1 = 6;
int IN2 = 7;
int IN3 = 4;
int IN4 = 2;
int ENB = 3;
/*int ENC =
int IN1C =
int IN2C =
int IN3D =
int IN4D =
int END =
*/
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
/*  pinMode(ENC, OUTPUT);
  pinMode(IN1C, OUTPUT);
  pinMode(IN2C, OUTPUT);
  pinMode(IN3D, OUTPUT);
  pinMode(IN4D, OUTPUT);
  pinMode(END, OUTPUT); */
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
/*  digitalWrite(IN1C, HIGH);
  digitalWrite(IN2C, LOW);
  digitalWrite(IN3D, HIGH);
  digitalWrite(IN4D, LOW); */
}

void loop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  analogWrite(ENC, 0);
  analogWrite(END, 0);
  delay(2000);
  analogWrite(ENA, 255);
  analogWrite(ENC, 255);
  delay(2000);
  for (int i=0; i<255; i++){
    analogWrite(ENA, 255-i);
    analogWrite(ENC, 255-i);
    analogWrite(ENB, i);
    analogWrite(END, i);
    delay(15);
  }
  analogWrite(ENB, 0);
  analogWrite(END, 0);
  delay(1000);
  analogWrite(ENA, 255);
  delay(300);
  analogWrite(ENA, 0);
  analogWrite(ENB, 255);
  delay(300);
  analogWrite(ENB, 0);
  analogWrite(ENC, 255);
  delay(300);
  analogWrite(ENC, 0);
  analogWrite(END, 255);
  delay(300);
  analogWrite(END, 0);
  for (int j=0; j<255; j++){
    analogWrite(ENA, i/4);
    analogWrite(ENC, 3*(i/4));
    analogWrite(ENB, i/2);
    analogWrite(END, i);
    delay(15);
  }
  delay(1000);
}
