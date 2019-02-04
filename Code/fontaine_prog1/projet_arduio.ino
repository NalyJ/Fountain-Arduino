#include<SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial bluetooth(RX,TX);
char input = "";
int ENA=6;
int IN1=3;
int IN2=7;
int IN3=4;
int IN4=2;
int ENB=5;
int ENC=8;
//int IN5=10;
//int IN6=9;
int END=13;

int PWM=128;

void setup() {
  // put your setup code here, to run once:

  //les pompes 1, 2 et 3:
 pinMode(ENA,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(ENC,OUTPUT);
 //pinMode(IN5,OUTPUT);
 //pinMode(IN6,OUTPUT);
 pinMode(END,OUTPUT);


//Initialisation des moteurs
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);

 //Module bluetooth
 Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  // dialogue bluetooth
  /*while (bluetooth.available()) {
     Serial.print(char(bluetooth.read()));
  }
  while (Serial.available()) {
    bluetooth.write(char(Serial.read()));
  }*/
  //Interrupteur TEST
  
  if (bluetooth.available()) {
    input = bluetooth.read();
    Serial.println(input);
    if (input == 'R'){
      analogWrite(ENB,255);
      analogWrite(ENA,255);
      analogWrite(ENC,255);
      analogWrite(END,255);
    }
    if (input == 'r'){
      analogWrite(ENB,0);
      analogWrite(ENA,0);
      analogWrite(ENC,0);
      analogWrite(END,0);
  }
  /*
    if (input == 'A') {
      PWM = bluetooth.parseInt();
      analogWrite(ENB,255-PWM);
      analogWrite(ENA,255-PWM);
      analogWrite(ENC,255-PWM);
      
    }   */
    
  //regulation de la vitesse 
 /*
  //1er spectacle
if (input == 'A'){
  //1ère étape
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  analogWrite(ENC,255);
  analogWrite(END,255);  
  delay(3000);

  //2ème étape
  analogWrite(ENA,0);
  delay(1000);
  analogWrite(ENB,0);
  delay(1000);
  analogWrite(ENC,0);
  delay(1000);
  analogWrite(END,0);
  delay(1000);

  //3ème étape
  for(int i=0;i<255;i++){
    analogWrite(ENA,i);
    analogWrite(ENB,i);
    analogWrite(ENC,i);
    analogWrite(END,i);
    delay(15);
    }

  ///4ème étape
  analogWrite(ENA,255/4);
  delay(1000);
  analogWrite(ENB,128);
  delay(1000);
  analogWrite(ENC,3*255/4);
  delay(1000);
  analogWrite(END,255);
  delay(2000);
}*/
  }
}
 //
  
  
  
 
  
  
 
