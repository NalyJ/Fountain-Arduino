int ENA=6;
int IN1=3;
int IN2=7;
int IN3=4;
int IN4=2;
int ENB=5;
//les 2 dernières pompes /*
//int ENC=;
//int IN5=;
//int IN6=;
//int IN7=;
//int IN8=;
//int END=;

void setup() {
  // put your setup code here, to run once:

  //les 2 premières pompes 1 et 2:
 pinMode(ENA,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 
 //les 2 dernières pompes 3 et 4:
 //pinMode(ENC,OUTPUT);
 //pinMode(IN5,OUTPUT);
 //pinMode(IN6,OUTPUT);
 //pinMode(END,OUTPUT);
 //pinMode(IN7,OUTPUT);
 //pinMode(IN8,OUTPUT);

//Initialisation des moteurs
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
 //digitalWrite(IN5,HIGH);
 //digitalWrite(IN6,LOW);
 //digitalWrite(IN7,HIGH);
 //digitalWrite(IN8,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 //par défaut
  analogWrite(ENB,255);
  analogWrite(ENA,255);
  //analogWrite(ENC,255);
  //analogWrite(END,255);  
  

  //1er spectacle

  //1ère étape
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  //analogWrite(ENC,255);
  //analogWrite(END,255);  
  delay(3000);

  //2ème étape
  analogWrite(ENA,0);
  delay(1000);
  analogWrite(ENB,0);
  delay(1000);
  //analogWrite(ENC,0);
  //delay(1000);
  //analogWrite(END,0);
  //delay(1000);

  //3ème étape
  for(int i=0;i<255;i++){
    analogWrite(ENA,i);
    analogWrite(ENB,i);
    //analogWrite(ENC,i);
    //analogWrite(END,i);
    delay(15);
    }

  ///4ème étape
  analogWrite(ENA,255/4);
  delay(1000);
  analogWrite(ENB,128);
  delay(1000);
  //analogWrite(ENC,3*255/4);
  //delay(1000);
  //analogWrite(END,255);
  //delay(2000);

 //
  

  
  
 
  
  
 
}
