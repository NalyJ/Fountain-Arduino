#include<SoftwareSerial.h>
#define RX 11
#define TX 12
SoftwareSerial bluetooth(RX,TX);
char input = "";
int ENA=6;
int ENB=5;
int ENC=8;
int END=13;
int PWM=128;

void setup() {
 //les pompes 1, 2, 3 et 4 :
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(ENC,OUTPUT);
 pinMode(END,OUTPUT);
 
 //Module bluetooth
 Serial.begin(9600);
  bluetooth.begin(9600);
}

void reset() { //éteint toutes les pompes
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  analogWrite(ENC,0);
  analogWrite(END,0);
}

void slider() {
  int pwm = 128;
  pwm = bluetooth.parseInt();
  analogWrite(ENA,pwm);
  analogWrite(ENB,pwm);
  analogWrite(ENC,pwm);
  analogWrite(END,pwm);
}

void progA() {  //premier "spectacle"
  reset();
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

void progB() { //deuxième "spectacle"
  reset();
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  analogWrite(ENC,255);
  analogWrite(END,255);  
  delay(3000);
  analogWrite(ENA,0);
  delay(1000);
  analogWrite(ENB,0);
  delay(1000);
  analogWrite(ENC,0);
  delay(1000);
  analogWrite(END,0);
  delay(1000);
  for(int i=0;i<255;i++){
    analogWrite(ENA,i);
    analogWrite(ENB,i);
    analogWrite(ENC,i);
    analogWrite(END,i);
    delay(15);
  }
  analogWrite(ENA,255/4);
  delay(1000);
  analogWrite(ENB,128);
  delay(1000);
  analogWrite(ENC,3*255/4);
  delay(1000);
  analogWrite(END,255);
  delay(2000);
}

void progC() { //troisième "spectacle"
}

void loop() {
  if (bluetooth.available()) {
    input = bluetooth.read();
    Serial.println(input);
    if (input == 'A') {
      while (input == 'A') {
        progA();
      }
    }
    if (input == 'B') {
      while (input == 'B') {
        progB();
      }
    }
    if (input == 'C') {
      while (input == 'C') {
        progC();
      }
    }
    if (input == 'S') {
      reset();
    }
    if (input == 'P') {
      slider();
    }
  }
}
