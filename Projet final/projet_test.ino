#include<SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#define RX 5
#define TX 6
SoftwareSerial bluetooth(RX,TX);
int ENA=9;
int ENB=3;
int ENC=10;
int END=11;
char input = "";
int pwm = 128;
 Adafruit_NeoPixel strip = Adafruit_NeoPixel(47, 12, NEO_GRB + NEO_KHZ800);

int RED[3] = {255, 0, 0}; // Couleur Rouge
int GREEN[3] = {0, 255, 0}; // Couleur Verte
int CYAN[3] = {0, 255, 255}; // Couleur Cyan
int YELLOW[3] = {255, 125, 0}; // Couleur Jaune
int ORANGE[3] = {255, 40, 0}; // Couleur Orange
int PURPLE[3] = {255, 0 , 255}; // Couleur Violette
int PINK[3] = {255, 0, 100}; // Couleur Rose
int BLUE[3] = {0, 0, 255}; // Couleur Bleu
int WHITE[3] = {255, 255, 255}; // Couleur Blanche
int OFF[3] = {0, 0, 0}; // Éteint

int PIXEL_COUNT=47;
 
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  // put your setup code here, to run once:
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(ENC,OUTPUT);
 pinMode(END,OUTPUT);
 Serial.begin(9600);
 delay(200);
 strip.begin();
  strip.show();

}

void reset() { //Ã©teint toutes les pompes
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  analogWrite(ENC,0);
  analogWrite(END,0);
  allLeds(OFF);
}
void start() { //allume toutes les pompes
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  analogWrite(ENC,255);
  analogWrite(END,255);
  allLeds(WHITE);
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
  Serial.println("A");
  reset();
  delay(2000);
  anim_fire();
  analogWrite(ENA, 255);
  analogWrite(ENC, 255);
  delay(2000);
  for (int i=150; i<255; i++){
    analogWrite(ENA, 255-i);
    analogWrite(ENC, 255-i);
    analogWrite(ENB, i);
    analogWrite(END, i);
    
    delay(15);
  }
  changeColor(10,CYAN,GREEN);
  analogWrite(ENB, 0);
  analogWrite(END, 0);
  progressiveUp(10,PURPLE);
  delay(1000);
  analogWrite(ENA, 255);
  progressiveUp(10,YELLOW);
  delay(300);
  analogWrite(ENA, 0);
  analogWrite(ENB, 255);
  progressiveUp(10,ORANGE);
  delay(300);
  analogWrite(ENB, 0);
  analogWrite(ENC, 255);
  progressiveUp(10,RED);
  delay(300);
  analogWrite(ENC, 0);
  analogWrite(END, 255);
  progressiveUp(10,PINK);
  delay(300);
  analogWrite(END, 0);
  for (int j=150; j<255; j++){
    analogWrite(ENA, j);
    analogWrite(ENC, j+70);
    analogWrite(ENB, j+40);
    analogWrite(END, j+100);
    delay(15);
  }
  chenillardUp(10, WHITE);
  delay(1000);
  start();
  bluetooth.write('S');
}
void progB() { //deuxiÃ¨me "spectacle"
  Serial.println("B");
  reset();
  allBicolor(CYAN,PINK);
  analogWrite(ENA,220);
  analogWrite(ENB,150);
  analogWrite(ENC,220);
  analogWrite(END,150);  
  delay(3000);
  progressiveUp(10,GREEN);
  analogWrite(ENA,0);
  delay(1000);
  analogWrite(ENB,0);
  delay(1000);
  analogWrite(ENC,0);
  delay(1000);
  analogWrite(END,0);
  delay(1000);
  anim_fire();
 for(int i=150;i<255;i++){
    analogWrite(ENA,i);
    analogWrite(ENB,i);
    analogWrite(ENC,i);
    analogWrite(END,i);
    delay(15);
  }
  analogWrite(ENA,150);
  delay(1000);
  analogWrite(ENB,178);
  delay(1000);
  analogWrite(ENC,220);
  delay(1000);
  analogWrite(END,255);
  delay(2000);
  start();
  bluetooth.write('S');
}
void progC() {//troisiÃ¨me "spectacle"
  Serial.println("C");
  reset();
  analogWrite(ENA,255);
  delay(1000);
  reset();
  delay(1500);
  analogWrite(ENC,255);
  delay(1000);
  reset();
  delay(1500);
  reset();
  analogWrite(ENB,255);
  delay(1000);
  reset();
  delay(1500);
  analogWrite(END,255);
  delay(1000);
  reset();
  delay(1500);
  for(int i=150;i<255;i++){
    analogWrite(ENA,i);
    analogWrite(ENB,i);
    analogWrite(ENC,i);
    analogWrite(END,i);
    delay(15);
  }
  delay(1000);
  analogWrite(ENA,0);  
  delay(1500);
  analogWrite(ENC,0);
  delay(1500);
  analogWrite(ENB,0);
  delay(1500);
  analogWrite(END,0);
  delay(1500);
  start();
  bluetooth.write('S');  
}

///////////////////////////////////////////////////////////////////////////////
void chenillardUp(int temps, int color[3])
  {
  for(int i = 0 ; i < 47 ; i++)
    {
    strip.setPixelColor(i, color[0], color[1], color[2]);
    strip.show();
    delay(temps);
  }
}
////////////////////////////////////////////////////////////////////////////
void allLeds(int COLOR[])
{
  for(int i = 0 ; i < 47 ; i++)
  {
  strip.setPixelColor(i, COLOR[0], COLOR[1], COLOR[2]);
  }
  strip.show();
  }
///////////////////////////////////////////////////////////////////////////
void changeColor(int temps, int colorDebut[3], int colorFin[3])
{
    
    int color[3] = {0};
    
    color[0] = colorDebut[0];
    color[1] = colorDebut[1];
    color[2] = colorDebut[2];
    
    while(color[0] != colorFin[0] || color[1] != colorFin[1] || color[2] != colorFin[2])
    {
    
    if(color[0] > colorFin[0])
    {
    color[0]--;
    }
    else if(color[0] < colorFin[0])
    {
    color[0]++;
    }
    
    if(color[1] > colorFin[1])
    {
    color[1]--;
    }
    else if(color[1] < colorFin[1])
    {
    color[1]++;
    }
    
    if(color[2] > colorFin[2])
    {
    color[2]--;
    }
    else if(color[2] < colorFin[2])
    {
    color[2]++;
    }
    
    delay(temps);
    allLeds(color);
}
}
//////////////////////////////////////////////////////////////////////////////////////////
void progressiveUp(int temps, int COLOR[])
{
for(int lumi = 0 ; lumi < 100 ; lumi++)
{
for(int i = 0 ; i < 150 ; i++)
{
strip.setPixelColor(i, COLOR[0], COLOR[1], COLOR[2]);
}
strip.setBrightness(lumi);
strip.show();
delay(temps);
}
}
////////////////////////////////////////////////////////////////
void allBicolor(int COLOR_LEFT[], int COLOR_RIGHT[])
{
for(int i = 0 ; i < PIXEL_COUNT/2 ; i++)
{
strip.setPixelColor(i, COLOR_LEFT[0], COLOR_LEFT[1], COLOR_LEFT[2]);
}

for(int i = PIXEL_COUNT/2 ; i < PIXEL_COUNT ; i++)
{
strip.setPixelColor(i, COLOR_RIGHT[0], COLOR_RIGHT[1], COLOR_RIGHT[2]);
}
strip.show();
}
//////////////////////////////////////////////////////////////
void ledUp(int temps, int color[3])
{
for(int i = 0 ; i < 150 ; i++)
{
strip.setPixelColor(i, color[0], color[1], color[2]);
strip.show();
strip.setPixelColor(i,0,0,0);
strip.show();
delay(temps);
}
}
/////////////////////////////////////////////////////////////
void anim_fire()
{
int r = ORANGE[0];
int g = ORANGE[1]+5;
int b = ORANGE[2];

int variation = 45;

for(int x = 0; x <PIXEL_COUNT; x++)
{
int flicker = random(0,variation);
int r1 = r-flicker;
int g1 = g-flicker;
int b1 = b-flicker;
if(g1<0) g1=0;
if(r1<0) r1=0;
if(b1<0) b1=0;
strip.setPixelColor(x,r1,g1, b1);
}
strip.show();
delay(random(50,115));
}

void loop() {
  // put your main code here, to run repeatedly:
//par dÃ©faut




if (bluetooth.available()) {
  while (bluetooth.available()) {
    input = bluetooth.read();
    Serial.println(char(input));
    if (input == 'A') {
      
        progA();
        
        
      
    }
    if (input == 'B') {
      
       progB();
       ;
      
    }
    if (input == 'C') {
      
        progC();
      
    }
    if (input == 'S') {
      
      reset();
      
    }
    if (input == 'P') {
      
      slider();
      
    }
    if (input == 'G') {
     
        start();
      
    }
  } 
  delay(200);
 }
 else {
  start();
 }
}
