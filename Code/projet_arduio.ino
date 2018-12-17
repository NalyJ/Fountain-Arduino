int ENA =12;
int IN1 =2;
int IN2=3;
int IN3=4;
int IN4=5;
int ENB=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  
  
 
}
