//#include <EEPROM.h>


/*
################################################################################
# File Name:             cube                                           
# Board:                 Arduino UNO and MAX7219 module or FC-16 display      
# Programming Language:	 Wiring / C /Processing /Fritzing / Arduino IDE          
#						
# Objective:             led cube
#										  
# Operation:	         led cube
#			
# Author:                Christian Dore
# Date:                  Mars 30, 2016	
# Place:                 Quebec, Quebec, Canada
#					
################################################################################
 
 This code is a public example.
 */

#include <Arduino.h>
#include "LedControl.h"
#include <MaxMatrix.h>


int data = 13;    // 8, DIN pin of MAX7219 module
int load = 1209;    // 9, CS pin of MAX7219 module
int clock = 11;  // 10, CLK pin of MAX7219 module

int maxInUse = 1;    //change this variable to set how many MAX7219's you'll use
LedControl lc=LedControl(13,11,12,1);
MaxMatrix m(data, load, clock, maxInUse); // define module
int  timer = 100;

// active sentenses
int j = 0;
int k = 0;
int d = 255;
int f = 0;
int y = 0;
int qq = 1000;  // time between patern


void setup(){
  m.init(); // module initialize
  m.setIntensity(8); // dot matix intensity 0-15
  Serial.begin(9600); // serial communication initialize
  
}

void allume()
{
  
lc.clearDisplay(0);
delay(qq);
for (int tour=0; tour<=15; tour++){
  m.setIntensity(tour); 
  lc.setRow(0,0,B11111111); 
  lc.setRow(0,1,B11111111);  
  lc.setRow(0,2,B11111111); 
  lc.setRow(0,3,B11111111);  
  lc.setRow(0,4,B11111111);  
  lc.setRow(0,5,B11111111);  
  lc.setRow(0,6,B11111111);  
  lc.setRow(0,7,B11111111);  
  delay(200);}
  }
  void ferme()
  {
    delay(qq);
  for (int tour=15; tour>=0; tour--){
  m.setIntensity(tour); 
  lc.setRow(0,0,B11111111); 
  lc.setRow(0,1,B11111111);  
  lc.setRow(0,2,B11111111); 
  lc.setRow(0,3,B11111111);  
  lc.setRow(0,4,B11111111);  
  lc.setRow(0,5,B11111111);  
  lc.setRow(0,6,B11111111);  
  lc.setRow(0,7,B11111111);  
  delay(200);}
  lc.clearDisplay(0);
  delay(qq);
  }

  void ligne() 
  {delay(qq);
   lc.clearDisplay(0);
   m.setIntensity(8); 
   
  lc.setRow(0,0,B10000000);
  delay(timer);
  lc.setRow(0,0,B11000000);
  delay(timer);
  lc.setRow(0,0,B11100000);
  delay(timer);
  lc.setRow(0,0,B11110000);
  delay(timer);
  for (int tour=0; tour<=4; tour++){
  lc.setRow(0,0,B11110000);
  delay(timer);
  lc.setRow(0,0,B00000000); 
  lc.setRow(0,1,B11110000);  
  delay(timer);
  lc.setRow(0,1,000000000); 
  lc.setRow(0,2,B11110000);  
  delay(timer);
  lc.setRow(0,2,B00000000);  
  lc.setRow(0,3,B11110000);  
  delay(timer);
  lc.setRow(0,3,B00001111);   
  delay(timer);
  lc.setRow(0,3,B00000000); 
  lc.setRow(0,2,B00001111);
  delay(timer);
  lc.setRow(0,2,B00000000); 
  lc.setRow(0,1,B00001111);
  delay(timer);
  lc.setRow(0,1,B00000000); 
  lc.setRow(0,0,B00001111);
  delay(timer);
  lc.setRow(0,0,B00000000); // haut   up
  lc.setRow(0,4,B11110000);  
  delay(timer);
  lc.setRow(0,4,000000000); 
  lc.setRow(0,5,B11110000);  
  delay(timer);
  lc.setRow(0,5,B00000000);  
  lc.setRow(0,6,B11110000);  
  delay(timer);
  lc.setRow(0,6,B00000000); 
  lc.setRow(0,7,B11110000);   
  delay(timer); 
  lc.setRow(0,7,B00001111);   
  delay(timer);
  lc.setRow(0,7,B00000000); 
  lc.setRow(0,6,B00001111);
  delay(timer);
  lc.setRow(0,6,B00000000); 
  lc.setRow(0,5,B00001111);
  delay(timer);
  lc.setRow(0,5,B00000000);
  lc.setRow(0,4,B00001111);
  delay(timer); 
  lc.setRow(0,4,B11110000);
  delay(timer); 
  lc.setRow(0,4,B00000000);
  lc.setRow(0,0,B00001111);
  delay(timer); 
 }lc.clearDisplay(0);
 }

 void plateau() 
 {delay(qq);
   int  timer = 100;
   for (int tour=0; tour<=9; tour++){
  lc.setRow(0,0,B11110000);  
  lc.setRow(0,1,B11110000); 
  lc.setRow(0,2,B11110000); 
  lc.setRow(0,3,B11110000); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00001111); 
  lc.setRow(0,1,B00001111);  
  lc.setRow(0,2,B00001111); 
  lc.setRow(0,3,B00001111);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B11110000);  
  lc.setRow(0,5,B11110000);  
  lc.setRow(0,6,B11110000);  
  lc.setRow(0,7,B11110000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00001111);  
  lc.setRow(0,5,B00001111);  
  lc.setRow(0,6,B00001111); 
  lc.setRow(0,7,B00001111); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B11110000); 
  lc.setRow(0,5,B11110000); 
  lc.setRow(0,6,B11110000); 
  lc.setRow(0,7,B11110000); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00001111);  
  lc.setRow(0,1,B00001111); 
  lc.setRow(0,2,B00001111);  
  lc.setRow(0,3,B00001111); 
  delay(timer);
  
  lc.clearDisplay(0);  
 }
}

void mur() 
 {delay(qq);
   int  timer = 200;
   for (int tour=0; tour<=5; tour++){
  lc.setRow(0,0,B11110000);  
  lc.setRow(0,1,B11110000);         //1
  lc.setRow(0,2,B11110000); 
  lc.setRow(0,3,B11110000); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00010010); 
  lc.setRow(0,1,B00010010);  
  lc.setRow(0,2,B00010010); 
  lc.setRow(0,3,B00010010); 
  lc.setRow(0,4,B01001000);          //2
  lc.setRow(0,5,B01001000);  
  lc.setRow(0,6,B01001000);  
  lc.setRow(0,7,B01001000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00010001);  
  lc.setRow(0,1,B00010001);  
  lc.setRow(0,2,B00010001);  
  lc.setRow(0,3,B00010001);          //3
  lc.setRow(0,4,B00010001);  
  lc.setRow(0,5,B00010001);  
  lc.setRow(0,6,B00010001);  
  lc.setRow(0,7,B00010001);
  delay(timer);  
  lc.clearDisplay(0);
  lc.setRow(0,0,B10001000);  
  lc.setRow(0,1,B01000100);  
  lc.setRow(0,2,B00100010);  
  lc.setRow(0,3,B00010001);          //4
  lc.setRow(0,4,B10001000);  
  lc.setRow(0,5,B01000100);  
  lc.setRow(0,6,B00100010);  
  lc.setRow(0,7,B00010001);
  delay(timer); 
  lc.clearDisplay(0);
  lc.setRow(0,3,B11111111);         //5
  lc.setRow(0,7,B11111111);
  delay(timer); 
  lc.clearDisplay(0);
  lc.setRow(0,0,B11110000);  
  lc.setRow(0,1,B00001111);         //6
  lc.setRow(0,6,B11110000);  
  lc.setRow(0,7,B00001111);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00001111);  
  lc.setRow(0,5,B00001111);        //7
  lc.setRow(0,6,B00001111);  
  lc.setRow(0,7,B00001111);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,2,B00001111);  
  lc.setRow(0,3,B11110000);        //8
  lc.setRow(0,4,B00001111);  
  lc.setRow(0,5,B11110000);   
  delay(timer);  
  lc.clearDisplay(0);
  lc.setRow(0,0,B11111111);        //9
  lc.setRow(0,4,B11111111);   
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B10001000);  
  lc.setRow(0,1,B01000100);  
  lc.setRow(0,2,B00100010);  
  lc.setRow(0,3,B00010001);       //10
  lc.setRow(0,4,B10001000);  
  lc.setRow(0,5,B01000100);  
  lc.setRow(0,6,B00100010);  
  lc.setRow(0,7,B00010001);
  delay(timer);  
  lc.clearDisplay(0);
  lc.setRow(0,0,B10001000);  
  lc.setRow(0,1,B10001000);  
  lc.setRow(0,2,B10001000);       //11
  lc.setRow(0,3,B10001000); 
  lc.setRow(0,4,B10001000);  
  lc.setRow(0,5,B10001000);  
  lc.setRow(0,6,B10001000);  
  lc.setRow(0,7,B10001000);  
  delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B10000100);  
  lc.setRow(0,1,B10000100);  
  lc.setRow(0,2,B10000100);      //12
  lc.setRow(0,3,B10000100); 
  lc.setRow(0,4,B00100001);  
  lc.setRow(0,5,B00100001);  
  lc.setRow(0,6,B00100001);  
  lc.setRow(0,7,B00100001);  
  delay(timer);
  lc.clearDisplay(0);  
 }
}
  
void cube() 
 {delay(qq);
  int  timer = 200;
  
  for (int tour=0; tour<=9; tour++){
  timer=timer-20;
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000000); 
  lc.setRow(0,1,B00000110);  
  lc.setRow(0,2,B00000110); 
  lc.setRow(0,3,B00000000); 
  lc.setRow(0,4,B00000000);         //1
  lc.setRow(0,5,B01100000);  
  lc.setRow(0,6,B01100000);  
  lc.setRow(0,7,B00000000); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,5,B01100110);        //2
  lc.setRow(0,6,B01100110);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,6,B01100110);        //3
  lc.setRow(0,7,B01100110); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,6,B00110011);       //4
  lc.setRow(0,7,B00110011); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,5,B00110011);       //5
  lc.setRow(0,6,B00110011);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,4,B00110011);       //6
  lc.setRow(0,5,B00110011);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,4,B01100110);       //7
  lc.setRow(0,5,B01100110);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,4,B11001100);       //8
  lc.setRow(0,5,B11001100);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,5,B11001100);       //9
  lc.setRow(0,6,B11001100);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,6,B11001100);  
  lc.setRow(0,7,B11001100);      //10
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,2,B00000110); 
  lc.setRow(0,3,B00000110);  
  lc.setRow(0,6,B01100000);     //11
  lc.setRow(0,7,B01100000); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,2,B00000011); 
  lc.setRow(0,3,B00000011);    //12
  lc.setRow(0,6,B00110000);  
  lc.setRow(0,7,B00110000); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,1,B00000011);  
  lc.setRow(0,2,B00000011);    //14
  lc.setRow(0,5,B00110000);  
  lc.setRow(0,6,B00110000);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00000011); 
  lc.setRow(0,1,B00000011);  
  lc.setRow(0,4,B00110000);          //15
  lc.setRow(0,5,B00110000);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00000110); 
  lc.setRow(0,1,B00000110);  
  lc.setRow(0,4,B01100000);          //16
  lc.setRow(0,5,B01100000);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00001100); 
  lc.setRow(0,1,B00001100);  
  lc.setRow(0,4,B11000000);          //17
  lc.setRow(0,5,B11000000);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,1,B00001100);  
  lc.setRow(0,2,B00001100);         //18
  lc.setRow(0,5,B11000000);  
  lc.setRow(0,6,B11000000);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,2,B00001100); 
  lc.setRow(0,3,B00001100);   
  lc.setRow(0,6,B11000000);      //19
  lc.setRow(0,7,B11000000); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,2,B01100110); 
  lc.setRow(0,3,B01100110);     //20
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,2,B00110011); 
  lc.setRow(0,3,B00110011);     //21
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,1,B00110011);     //22
  lc.setRow(0,2,B00110011); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00110011);    //23
  lc.setRow(0,1,B00110011);  
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B01100110); 
  lc.setRow(0,1,B01100110);    //24
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B11001100);   //25
  lc.setRow(0,1,B11001100);  
   delay(timer); 
   lc.clearDisplay(0);
  lc.setRow(0,1,B11001100);  
  lc.setRow(0,2,B11001100);    //26
  lc.clearDisplay(0);
  lc.setRow(0,2,B11001100);    //27
  lc.setRow(0,3,B11001100); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00000000); 
  lc.setRow(0,1,B01100110);  
  lc.setRow(0,2,B01100110); 
  lc.setRow(0,3,B00000000); 
  lc.setRow(0,4,B00000000);    //28
  lc.setRow(0,5,B00000000);  
  lc.setRow(0,6,B00000000);  
  lc.setRow(0,7,B00000000); 
   delay(timer);
  lc.clearDisplay(0);  
   }
}

  void plateau2() 
 {delay(qq);
   lc.clearDisplay(0);
   int  timer = 50;
   for (int tour=0; tour<=4; tour++){
  for (int in=12; in>=0; in--){   
  lc.setRow(0,0,B11110000);  
  lc.setRow(0,1,B11110000); 
  lc.setRow(0,2,B11110000); 
  lc.setRow(0,3,B11110000); 
  delay(timer);
  m.setIntensity(in); 
  delay(50); }
  for (int in1=0; in1<=12; in1++){
  
  lc.setRow(0,0,B00001111); 
  lc.setRow(0,1,B00001111);  
  lc.setRow(0,2,B00001111); 
  lc.setRow(0,3,B00001111);  
  delay(timer);
  m.setIntensity(in1); 
  delay(50); }
  
  lc.clearDisplay(0);
  lc.setRow(0,4,B11110000);  
  lc.setRow(0,5,B11110000);  
  lc.setRow(0,6,B11110000);  
  lc.setRow(0,7,B11110000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00001111);  
  lc.setRow(0,5,B00001111);  
  lc.setRow(0,6,B00001111); 
  lc.setRow(0,7,B00001111); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B11110000); 
  lc.setRow(0,5,B11110000); 
  lc.setRow(0,6,B11110000); 
  lc.setRow(0,7,B11110000); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00001111);  
  lc.setRow(0,1,B00001111); 
  lc.setRow(0,2,B00001111);  
  lc.setRow(0,3,B00001111); 
  delay(timer);
  
  lc.clearDisplay(0);  
 }}
 
 void vague1()
  { delay(qq);
    for (int tour=0; tour<=4; tour++){
    int  timer = 100;
    lc.clearDisplay(0);
   
  lc.setRow(0,7,B0001000);
  delay(timer);
  
   delay(1000);  
  lc.setRow(0,6,B00001000);  
  lc.setRow(0,7,B10000100); 
   delay(timer);
   lc.clearDisplay(0); 
  lc.setRow(0,3,B00001000); 
  lc.setRow(0,5,B00001000);  
  lc.setRow(0,6,B10000100);  
  lc.setRow(0,7,B01000010); 
   delay(timer);
    lc.clearDisplay(0);
  lc.setRow(0,2,B00001000); 
  lc.setRow(0,3,B10000100); 
  lc.setRow(0,4,B00001000);    //4
  lc.setRow(0,5,B10000100);  
  lc.setRow(0,6,B01000010);  
  lc.setRow(0,7,B00100001); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,1,B00001000); 
  lc.setRow(0,2,B10000100); 
  lc.setRow(0,3,B01001010); 
  lc.setRow(0,4,B10000100);    //5
  lc.setRow(0,5,B01000010);  
  lc.setRow(0,6,B00100001);  
  lc.setRow(0,7,B00010000); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00001000); 
  lc.setRow(0,1,B10000100); 
  lc.setRow(0,2,B01001010); 
  lc.setRow(0,3,B00100101); 
  lc.setRow(0,4,B01000010);    //6
  lc.setRow(0,5,B00100001);  
  lc.setRow(0,6,B00010000);  
  lc.setRow(0,7,B10000000);
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B10000100); 
  lc.setRow(0,1,B01001010); 
  lc.setRow(0,2,B00100101); 
  lc.setRow(0,3,B00010010); 
  lc.setRow(0,4,B00100001);    //7
  lc.setRow(0,5,B00010000);  
  lc.setRow(0,6,B10000000);  
  lc.setRow(0,7,B01001000);
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B01001010); 
  lc.setRow(0,1,B00100101); 
  lc.setRow(0,2,B00010010); 
  lc.setRow(0,3,B00000001); 
  lc.setRow(0,4,B00010000);    //8
  lc.setRow(0,5,B10000000);  
  lc.setRow(0,6,B01001000);  
  lc.setRow(0,7,B00101100);
  delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00100101); 
  lc.setRow(0,1,B00010010); 
  lc.setRow(0,2,B00000001); 
  lc.setRow(0,4,B10000000);    //9
  lc.setRow(0,5,B01001000);  
  lc.setRow(0,6,B00101100);  
  lc.setRow(0,7,B00011110);
  delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00010010); 
  lc.setRow(0,1,B00000001); 
  lc.setRow(0,4,B01001000);    //9
  lc.setRow(0,5,B00101100);  
  lc.setRow(0,6,B00011110);  
  lc.setRow(0,7,B00001111);
  delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B00000001); 
  lc.setRow(0,4,B00101100);    //9
  lc.setRow(0,5,B00011110);  
  lc.setRow(0,6,B00001111);  
  lc.setRow(0,7,B00001111);
  delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,4,B00011110);    //9
  lc.setRow(0,5,B00001111);  
  lc.setRow(0,6,B00001111);  
  lc.setRow(0,7,B00001111);
   delay(timer);
   timer =timer+ 200;
   lc.clearDisplay(0);
  lc.setRow(0,4,B00001111);    //9
  lc.setRow(0,5,B00001111);  
  lc.setRow(0,6,B00001111);  
  lc.setRow(0,7,B00001111);
   delay(timer);
    lc.clearDisplay(0);
  lc.setRow(0,4,B00001110);    //9
  lc.setRow(0,5,B00001111);  
  lc.setRow(0,6,B00001111);  
  lc.setRow(0,7,B00001111);
   delay(timer);
    lc.clearDisplay(0);
  lc.setRow(0,4,B00001100);    //9
  lc.setRow(0,5,B00001110);  
  lc.setRow(0,6,B00001111);  
  lc.setRow(0,7,B00001111);
   delay(timer);
    lc.clearDisplay(0);
  lc.setRow(0,4,B00001000);    //9
  lc.setRow(0,5,B00001100);  
  lc.setRow(0,6,B00001110);  
  lc.setRow(0,7,B00001111);
   delay(timer);
    lc.clearDisplay(0);
  lc.setRow(0,4,B00000000);    //9
  lc.setRow(0,5,B00001000);  
  lc.setRow(0,6,B00001100);  
  lc.setRow(0,7,B00001110);
   delay(timer);
    lc.clearDisplay(0);   //9
  lc.setRow(0,5,B00000000);  
  lc.setRow(0,6,B00001000);  
  lc.setRow(0,7,B00001100);
   delay(timer);
    lc.clearDisplay(0);  
  lc.setRow(0,6,B00000000);  
  lc.setRow(0,7,B00001000);
   delay(timer);
   }lc.clearDisplay(0);
   }
   
   void ligneverti()
 {delay(qq);
   int tt=0;
   
  for (int tt=0; tt<=5; tt++){
  for (int tour=7; tour>=0; tour--){
  lc.setRow(0,tour,B10100101); 
  delay(100);
  lc.setRow(0,tour,B00000000); 
}
}
  }
 
void cube2() 
 {delay(qq);
  int  timer = 400;
  
  for (int tour=0; tour<=14; tour++){
 
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000000); 
  lc.setRow(0,1,B00000110);  
  lc.setRow(0,2,B00000110); 
  lc.setRow(0,3,B00000000); 
  lc.setRow(0,4,B00000000);         //1
  lc.setRow(0,5,B01100000);  
  lc.setRow(0,6,B01100000);  
  lc.setRow(0,7,B00000000); 
   delay(timer);
   lc.clearDisplay(0);
  lc.setRow(0,0,B11111001); 
  lc.setRow(0,1,B10010000);  
  lc.setRow(0,2,B10010000); 
  lc.setRow(0,3,B11111001); 
  lc.setRow(0,4,B10011111);         //2
  lc.setRow(0,5,B00001001);  
  lc.setRow(0,6,B00001001);  
  lc.setRow(0,7,B10011111); 
   delay(timer);
}lc.clearDisplay(0);
delay(timer);
}

void axe() 
 {delay(qq);
   int  timer = 100;
  
  for (int tour=0; tour<=9; tour++){
  lc.setRow(0,0,B11111000);  //  1
  lc.setRow(0,1,B10000000);  
  lc.setRow(0,2,B10000000);  
  lc.setRow(0,3,B10000000);  
  lc.setRow(0,4,B10001000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B10001111);  // 2
  lc.setRow(0,1,B00001000);  
  lc.setRow(0,2,B00001000); 
  lc.setRow(0,3,B00001000);
  lc.setRow(0,4,B10001000); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B10001000);  // 3
  lc.setRow(0,4,B11111000);  
  lc.setRow(0,5,B10000000);  
  lc.setRow(0,6,B10000000);  
  lc.setRow(0,7,B10000000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B10001000);  // 4
  lc.setRow(0,4,B10001111);  
  lc.setRow(0,5,B00001000);  
  lc.setRow(0,6,B00001000);  
  lc.setRow(0,7,B00001000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B10001000); 
  lc.setRow(0,4,B00001000);  
  lc.setRow(0,5,B10001111);  // 5
  lc.setRow(0,6,B00001000);  
  lc.setRow(0,7,B00001000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,2,B10001000);  
  lc.setRow(0,3,B00000000); 
  lc.setRow(0,4,B00001000);  
  lc.setRow(0,5,B00001000);  // 6
  lc.setRow(0,6,B10001111);  
  lc.setRow(0,7,B00001000);  
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B10001000); 
  lc.setRow(0,4,B00001000);  
  lc.setRow(0,5,B00001000);  // 7
  lc.setRow(0,6,B00001000);  
  lc.setRow(0,7,B10001111);  
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B01000100); 
  lc.setRow(0,4,B00000100);  // 8
  lc.setRow(0,5,B00000100);  
  lc.setRow(0,6,B00000100);  
  lc.setRow(0,7,B01001111);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,3,B00100010); 
  lc.setRow(0,4,B00000010);  
  lc.setRow(0,5,B00000010);  // 9
  lc.setRow(0,6,B00000010);  
  lc.setRow(0,7,B00101111);  
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B00010001); 
  lc.setRow(0,4,B00000001);  // 10
  lc.setRow(0,5,B00000001);  
  lc.setRow(0,6,B00000001);  
  lc.setRow(0,7,B00011111);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,2,B00010001);  
  lc.setRow(0,3,B00000000); 
  lc.setRow(0,4,B00000001);  // 11
  lc.setRow(0,5,B00000001);  
  lc.setRow(0,6,B00011111);  
  lc.setRow(0,7,B00000001);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B00010001); 
  lc.setRow(0,4,B00000001);  // 12
  lc.setRow(0,5,B00011111);  
  lc.setRow(0,6,B00000001);  
  lc.setRow(0,7,B00000001);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00010001);  // 13
  lc.setRow(0,4,B00011111);  
  lc.setRow(0,5,B00000001);  
  lc.setRow(0,6,B00000001);  
  lc.setRow(0,7,B00000001);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00010001);  // 14
  lc.setRow(0,4,B11110001);  
  lc.setRow(0,5,B00010000);  
  lc.setRow(0,6,B00010000);  
  lc.setRow(0,7,B00010000);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00011111);  // 15
  lc.setRow(0,1,B00000001); 
  lc.setRow(0,2,B00000001);  
  lc.setRow(0,3,B00000001); 
  lc.setRow(0,4,B00010001);  
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B11110001);  // 16
  lc.setRow(0,1,B00010000); 
  lc.setRow(0,2,B00010000);  
  lc.setRow(0,3,B00010000); 
  lc.setRow(0,4,B00010001); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B11110010);  // 17
  lc.setRow(0,1,B00100000); 
  lc.setRow(0,2,B00100000);  
  lc.setRow(0,3,B00100000); 
  lc.setRow(0,4,B00100010);   
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B11110100);  // 18
  lc.setRow(0,1,B01000000); 
  lc.setRow(0,2,B01000000);  
  lc.setRow(0,3,B01000000); 
  lc.setRow(0,4,B01000100);   
  delay(timer);
  lc.clearDisplay(0);
  
   }
 }
  
void aleatoir()
 
  {int a=0;
   int cc=0;
   int dd=0;
   int ee=0;
   delay(qq);
   for (int a=0; a<=200; a++){
     
    dd = random(8); 
    if (dd == 0){ee=(B10000000);}
    if (dd == 1){ee=(B01000000);}
    if (dd == 2){ee=(B00100000);}
    if (dd == 3){ee=(B00010000);}
    if (dd == 4){ee=(B00001000);}
    if (dd == 5){ee=(B00000100);}
    if (dd == 6){ee=(B00000010);}
    if (dd == 7){ee=(B00000001);}
    cc = random(8);
    cc = random(8);
    lc.setRow(0,cc,ee);
    delay(50);
  } lc.clearDisplay(0);
   }  

  
void aleatoir2()
 
  {int a=0;
   int cc=0;
   int dd=0;
   int ee=0;
  delay(qq);
   for (int a=0; a<=200; a++){
     
    dd = random(8); 
    if (dd == 0){ee=(B10000000);}
    if (dd == 1){ee=(B01000000);}
    if (dd == 2){ee=(B00100000);}
    if (dd == 3){ee=(B00010000);}
    if (dd == 4){ee=(B00001000);}
    if (dd == 5){ee=(B00000100);}
    if (dd == 6){ee=(B00000010);}
    if (dd == 7){ee=(B00000001);}
    cc = random(8);
    lc.setRow(0,cc,ee);
    delay(50);
    lc.clearDisplay(0);
  } lc.clearDisplay(0);
   }  

 
void elice() 
 {delay(qq);
  for (int a=0; a<=8; a++){
  lc.setRow(0,0,B11110000);  // xxxxoooo  1
  lc.setRow(0,1,B00001111);  // xxxxoooo
  lc.setRow(0,6,B11110000);  // oooooooo
  lc.setRow(0,7,B00001111);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00001111);  // oooooooo  3
  lc.setRow(0,1,B00001111);  // oooooooo
  lc.setRow(0,6,B11110000);  // xxxxoooo
  lc.setRow(0,7,B11110000);  // xxxxoooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B11110000);  // xxxxoooo  4
  lc.setRow(0,5,B11110000);  // xxxxoooo
  lc.setRow(0,2,B00001111);  // oooooooo
  lc.setRow(0,3,B00001111);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00001111);  // ooooxxxx  2
  lc.setRow(0,5,B11110000);  // ooooxxxx
  lc.setRow(0,2,B00001111);  // oooooooo
  lc.setRow(0,3,B11110000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);  
  lc.setRow(0,2,B11111111);  // ooooxxxx
  lc.setRow(0,5,B11111111);  // oooooooo
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,1,B11111111);  // ooooxxxx
  lc.setRow(0,6,B11111111);  // oooooooo
  delay(timer);
  lc.clearDisplay(0); 
 }lc.clearDisplay(0);
 }
 
void vague2()
 {delay(qq);
  int  timer = 125;
  lc.setRow(0,3,B11110000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,3,B00001111);
  lc.setRow(0,2,B11110000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B11110000);
  lc.setRow(0,2,B00001111);
  lc.setRow(0,7,B11110000);
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,0,B11110000);
  lc.setRow(0,1,B00001111);
  lc.setRow(0,6,B11110000);
  lc.setRow(0,7,B00001111);
  delay(timer);
  lc.clearDisplay(0);
  for (int a=0; a<=8; a++){ 
  lc.setRow(0,0,B00001111);
  lc.setRow(0,6,B00001111);
  lc.setRow(0,5,B11110000);
  lc.setRow(0,7,B00001111);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B11110000);
  lc.setRow(0,5,B00001111);
  lc.setRow(0,6,B00001111);
  lc.setRow(0,7,B11110000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00001111);
  lc.setRow(0,3,B00001111);
  lc.setRow(0,6,B11110000);
  lc.setRow(0,5,B00001111);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,3,B11110000);
  lc.setRow(0,2,B00001111);
  lc.setRow(0,5,B11110000);
  lc.setRow(0,4,B00001111);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,3,B11110000);
  lc.setRow(0,1,B00001111);
  lc.setRow(0,2,B11110000);
  lc.setRow(0,4,B11110000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B11110000);
  lc.setRow(0,0,B00001111);
  lc.setRow(0,2,B11110000);
  lc.setRow(0,3,B00001111);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B11110000);
  lc.setRow(0,2,B00001111);
  lc.setRow(0,1,B11110000);
  lc.setRow(0,7,B11110000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B11110000);
  lc.setRow(0,1,B00001111);
  lc.setRow(0,6,B11110000);
  lc.setRow(0,7,B00001111);
  delay(timer);
  lc.clearDisplay(0);}
  lc.setRow(0,0,B00001111);
  lc.setRow(0,6,B00001111);
  lc.setRow(0,5,B11110000);
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,5,B00001111);
  lc.setRow(0,4,B11110000);
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,4,B00001111);
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,4,B0000000);
  delay(500);
  lc.clearDisplay(0); 
 }


 
void roue()
 {delay(qq);
   int  timer = 25;
  for (int a=0; a<=8; a++){ 
  lc.setRow(0,1,B10000000);  // xxxxoooo  1
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00001000);  // oooooooo  3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B10000000);  // xxxxoooo  4
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,5,B00001000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0);  
  lc.setRow(0,6,B00001000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,7,B10000000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B00001000);  
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,2,B10000000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,1,B01000000);  //ttttttttttttt2
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000100);  // oooooooo  3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B01000000);  // xxxxoooo  4
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,5,B00000100);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0);  
  lc.setRow(0,6,B00000100);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,7,B01000000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B00000100);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,2,B01000000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,1,B00100000);  //ttttttttttttt3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000010);  // oooooooo  3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00100000);  // xxxxoooo  4
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,5,B00000010);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0);  
  lc.setRow(0,6,B00000010);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,7,B00100000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B00000010);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,2,B00100000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,1,B00010000);  //ttttttttttttt4
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000001);  // oooooooo  3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00010000);  // xxxxoooo  4
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,5,B00000001);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0);  
  lc.setRow(0,6,B00000001);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,7,B00010000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B00000001);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,2,B00010000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,1,B00100000);  //ttttttttttttt3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000010);  // oooooooo  3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00100000);  // xxxxoooo  4
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,5,B00000010);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0);  
  lc.setRow(0,6,B00000010);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,7,B00100000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B00000010);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,2,B00100000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,1,B01000000);  //ttttttttttttt2
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000100);  // oooooooo  3
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B01000000);  // xxxxoooo  4
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,5,B00000100);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0);  
  lc.setRow(0,6,B00000100);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,7,B01000000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,3,B00000100);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); 
  lc.setRow(0,2,B01000000);  // ooooxxxx
  delay(timer);
  lc.clearDisplay(0); }
  delay(1000);
 }
 
   void vague3()
   {delay(qq);
     int a=0;
   int a7 =(B11000011);
   int a6 =(B10001110);
   int a5 =(B00011100);
   int a4 =(B00110000);
   int a3 =(B00110000);
   int a2 =(B01100000);
   int a1 =(B01100000);
   int a0 =(B11000000);
   int b0 = 0;
   int b1 = 1;
   int b2 = 2;
   int b3 = 3;
   int b4 = 4;
   int b5 = 5;
   int b6 = 6;
   int b7 = 7;
   
   for (int a=0; a<=200; a++){
   lc.setRow(0,b0,a0);
   lc.setRow(0,b1,a1);
   lc.setRow(0,b2,a2);
   lc.setRow(0,b3,a3);
   lc.setRow(0,b4,a4);
   lc.setRow(0,b5,a5);
   lc.setRow(0,b6,a6);
   lc.setRow(0,b7,a7);
   b0=b0+1; 
   b1=b1+1; 
   b2=b2+1; 
   b3=b3+1; 
   b4=b4+1; 
   b5=b5+1;
   b6=b6+1; 
   b7=b7+1; 
   if (b0 > 7){b0=0;}
   if (b1 > 7){b1=0;}
   if (b2 > 7){b2=0;}
   if (b3 > 7){b3=0;}
   if (b4 > 7){b4=0;}
   if (b5 > 7){b5=0;}
   if (b6 > 7){b6=0;}
   if (b7 > 7){b7=0;}
      delay(100); }  
  lc.clearDisplay(0); 
  delay(300);
  lc.clearDisplay(0); 
  }
  
  
void diago() 

 {delay(qq);
  int  timer = 40;
  for (int a=0; a<=20; a++){
  lc.setRow(0,0,B10000000);
  lc.setRow(0,1,B00000100); 
  lc.setRow(0,6,B00100000);
  lc.setRow(0,7,B00000001);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B10000100); 
  lc.setRow(0,6,B00100001); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,2,B10000100); 
  lc.setRow(0,5,B00100001); 
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,3,B10000000);
  lc.setRow(0,2,B00000100); 
  lc.setRow(0,5,B00100000);
  lc.setRow(0,4,B00000001);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00000010);
  lc.setRow(0,5,B00100000); 
  lc.setRow(0,2,B00000100);
  lc.setRow(0,3,B01000000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00000100);
  lc.setRow(0,5,B01000000); 
  lc.setRow(0,2,B00000010);
  lc.setRow(0,3,B00100000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,4,B00001000);
  lc.setRow(0,5,B01000000); 
  lc.setRow(0,2,B00000010);
  lc.setRow(0,3,B00010000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,5,B01001000); 
  lc.setRow(0,2,B00010010);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,6,B01001000); 
  lc.setRow(0,1,B00010010);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00010000);
  lc.setRow(0,6,B01000000); 
  lc.setRow(0,1,B00000010);
  lc.setRow(0,7,B00001000);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00100000);
  lc.setRow(0,1,B00000010); 
  lc.setRow(0,6,B01000000);
  lc.setRow(0,7,B00000100);
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B01000000);
  lc.setRow(0,1,B00000100); 
  lc.setRow(0,6,B00100000);
  lc.setRow(0,7,B00000010);
  delay(timer);
  lc.clearDisplay(0);}
  delay(500);
 }
  
 
void tunel() 
 {delay(qq);
   int  timer = 45;
  lc.clearDisplay(0);
   delay(900);
   for (int a=0; a<=50; a++){
  lc.setRow(0,1,B00000001);  // xxxxoooo  1
  lc.setRow(0,2,B00000001);  // xxxxoooo
  lc.setRow(0,5,B00010000);  // oooooooo
  lc.setRow(0,6,B00010000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B00000010);  // xxxxoooo  1
  lc.setRow(0,2,B00000010);  // xxxxoooo
  lc.setRow(0,5,B00100000);  // oooooooo
  lc.setRow(0,6,B00100000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B00000100);  // xxxxoooo  1
  lc.setRow(0,2,B00000100);  // xxxxoooo
  lc.setRow(0,5,B01000000);  // oooooooo
  lc.setRow(0,6,B01000000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,1,B00001000);  // xxxxoooo  1
  lc.setRow(0,2,B00001000);  // xxxxoooo
  lc.setRow(0,5,B10000000);  // oooooooo
  lc.setRow(0,6,B10000000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00001000);  // oooooooo  3
  lc.setRow(0,1,B10000000);  // oooooooo
  lc.setRow(0,2,B10000000);  // xxxxoooo
  lc.setRow(0,3,B00001000);  // xxxxoooo
  lc.setRow(0,4,B10000000);  // xxxxoooo  1
  lc.setRow(0,5,B00001000);  // xxxxoooo
  lc.setRow(0,6,B00001000);  // oooooooo
  lc.setRow(0,7,B10000000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B10001000);  // oooooooo  3
  lc.setRow(0,1,B10000000);  // oooooooo
  lc.setRow(0,2,B10000000);  // xxxxoooo
  lc.setRow(0,3,B10001000);  // xxxxoooo
  lc.setRow(0,4,B10001000);  // xxxxoooo  1
  lc.setRow(0,5,B00001000);  // xxxxoooo
  lc.setRow(0,6,B00001000);  // oooooooo
  lc.setRow(0,7,B10001000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B01000100);  // oooooooo  3
  lc.setRow(0,1,B01000000);  // oooooooo
  lc.setRow(0,2,B01000000);  // xxxxoooo
  lc.setRow(0,3,B01000100);  // xxxxoooo
  lc.setRow(0,4,B01000100);  // xxxxoooo  1
  lc.setRow(0,5,B00000100);  // xxxxoooo
  lc.setRow(0,6,B00000100);  // oooooooo
  lc.setRow(0,7,B01000100);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00100010);  // oooooooo  3
  lc.setRow(0,1,B00100000);  // oooooooo
  lc.setRow(0,2,B00100000);  // xxxxoooo
  lc.setRow(0,3,B00100010);  // xxxxoooo
  lc.setRow(0,4,B00100010);  // xxxxoooo  1
  lc.setRow(0,5,B00000010);  // xxxxoooo
  lc.setRow(0,6,B00000010);  // oooooooo
  lc.setRow(0,7,B00100010);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00010001);  // oooooooo  3
  lc.setRow(0,1,B00010000);  // oooooooo
  lc.setRow(0,2,B00010000);  // xxxxoooo
  lc.setRow(0,3,B00010001);  // xxxxoooo
  lc.setRow(0,4,B00010001);  // xxxxoooo  1
  lc.setRow(0,5,B00000001);  // xxxxoooo
  lc.setRow(0,6,B00000001);  // oooooooo
  lc.setRow(0,7,B00010001);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
  lc.setRow(0,0,B00000001);  // oooooooo  3
  lc.setRow(0,1,B00010000);  // oooooooo
  lc.setRow(0,2,B00010000);  // xxxxoooo
  lc.setRow(0,3,B00000001);  // xxxxoooo
  lc.setRow(0,4,B00010000);  // xxxxoooo  1
  lc.setRow(0,5,B00000001);  // xxxxoooo
  lc.setRow(0,6,B00000001);  // oooooooo
  lc.setRow(0,7,B00010000);  // oooooooo
  delay(timer);
  lc.clearDisplay(0);
   
 }lc.clearDisplay(0);
 }
 

void serpent() 
 {delay(qq);
   int  timer = 75;
  lc.clearDisplay(0);
   delay(900);
   for (int a=0; a<=10; a++){
  lc.setRow(0,1,B00001000);
  lc.setRow(0,7,B00000000);
  delay(timer);
  lc.setRow(0,1,B00001100);
  lc.setRow(0,6,B00000000); 
  delay(timer);
  lc.setRow(0,1,B00001110); 
  lc.setRow(0,5,B00000000);
  delay(timer);
  lc.setRow(0,2,B00000010);  
  delay(timer);
  lc.setRow(0,1,B00000110); 
  lc.setRow(0,2,B00000010);
  lc.setRow(0,3,B00000010);
  delay(timer);
  lc.setRow(0,1,B00000010); 
  lc.setRow(0,2,B00000010);
  lc.setRow(0,3,B00000010);
  lc.setRow(0,7,B00100000);
  delay(timer);
  lc.setRow(0,1,B00000000); 
  lc.setRow(0,2,B00000010);
  lc.setRow(0,3,B00000010);
  lc.setRow(0,7,B00100010);
  delay(timer);  
  lc.setRow(0,2,B00000000);
  lc.setRow(0,3,B00000010);
  lc.setRow(0,7,B00100110);
  delay(timer);  
  lc.setRow(0,3,B00000000);
  lc.setRow(0,7,B00101110);
  delay(timer);  
  lc.setRow(0,6,B00001000);
  lc.setRow(0,7,B00001110);
  delay(timer);  
  lc.setRow(0,5,B00001000);
  lc.setRow(0,6,B00001000);
  lc.setRow(0,7,B00001100);
  delay(timer); 
  lc.setRow(0,4,B00001000); 
  lc.setRow(0,5,B00001000);
  lc.setRow(0,6,B00001000);
  lc.setRow(0,7,B00001000);
  delay(timer);  
  lc.setRow(0,4,B00001000); 
  lc.setRow(0,5,B01001000);
  lc.setRow(0,6,B00001000);
  lc.setRow(0,7,B00000000);
  delay(timer);  
  lc.setRow(0,4,B00001000); 
  lc.setRow(0,5,B01001000);
  lc.setRow(0,6,B00000000);
  lc.setRow(0,2,B00000010);
  delay(timer); 
  lc.setRow(0,4,B00001000); 
  lc.setRow(0,5,B01000000);
  lc.setRow(0,3,B00010000);
  lc.setRow(0,2,B00000010);
  delay(timer);  
  lc.setRow(0,4,B00000000); 
  lc.setRow(0,5,B01000000);
  lc.setRow(0,3,B00010000);
  lc.setRow(0,2,B00010010);
  delay(timer);  
  lc.setRow(0,1,B00010000); 
  lc.setRow(0,5,B00000000);
  lc.setRow(0,3,B00010000);
  lc.setRow(0,2,B00010010);
  delay(timer);  
  lc.setRow(0,1,B00010000); 
  lc.setRow(0,0,B00010000);
  lc.setRow(0,3,B00010000);
  lc.setRow(0,2,B00010000);
  delay(timer);  
  lc.setRow(0,1,B00010000); 
  lc.setRow(0,0,B00110000);
  lc.setRow(0,3,B00000000);
  lc.setRow(0,2,B00010000);
  delay(timer);
  lc.setRow(0,1,B00010000); 
  lc.setRow(0,0,B01110000);
  lc.setRow(0,3,B00000000);
  lc.setRow(0,2,B00000000);
  delay(timer);
  lc.setRow(0,1,B00000000); 
  lc.setRow(0,0,B01110100);
  lc.setRow(0,3,B00000000);
  lc.setRow(0,2,B00000000);
  delay(timer);  
  lc.setRow(0,1,B00000000); 
  lc.setRow(0,0,B01100100);
  lc.setRow(0,4,B01000000);
  lc.setRow(0,2,B00000000);
  delay(timer); 
  lc.setRow(0,1,B00000000); 
  lc.setRow(0,0,B01000100);
  lc.setRow(0,4,B01000100);
  lc.setRow(0,2,B00000000);
  delay(timer);  
  lc.setRow(0,1,B00000000); 
  lc.setRow(0,0,B00000100);
  lc.setRow(0,4,B01000100);
  lc.setRow(0,5,B00000100);
  delay(timer);  
  lc.setRow(0,6,B00000100); 
  lc.setRow(0,0,B00000000);
  lc.setRow(0,4,B01000100);
  lc.setRow(0,5,B00000100);
  delay(timer);  
  lc.setRow(0,6,B00000100); 
  lc.setRow(0,7,B00000100);
  lc.setRow(0,4,B00000100);
  lc.setRow(0,5,B00000100);
  delay(timer);  
  lc.setRow(0,6,B00000100); 
  lc.setRow(0,7,B00000110);
  lc.setRow(0,4,B00000000);
  lc.setRow(0,5,B00000100);
  delay(timer); 
  lc.setRow(0,6,B00000100); 
  lc.setRow(0,7,B00000111);
  lc.setRow(0,4,B00000000);
  lc.setRow(0,5,B00000000);
  delay(timer);  
  lc.setRow(0,6,B00000001); 
  lc.setRow(0,7,B00000111);
  lc.setRow(0,4,B00000000);
  lc.setRow(0,5,B00000000);
  delay(timer);  
  lc.setRow(0,6,B00000001); 
  lc.setRow(0,7,B00000011);
  lc.setRow(0,4,B00000000);
  lc.setRow(0,5,B00000001);
  delay(timer); 
  lc.setRow(0,6,B00000001); 
  lc.setRow(0,7,B00000001);
  lc.setRow(0,4,B00000001);
  lc.setRow(0,5,B00000001);
  delay(timer); 
  lc.setRow(0,6,B00000001); 
  lc.setRow(0,7,B00000000);
  lc.setRow(0,4,B00010001);
  lc.setRow(0,5,B00000001);
  delay(timer); 
  lc.setRow(0,6,B00000000); 
  lc.setRow(0,0,B00000001);
  lc.setRow(0,4,B00010001);
  lc.setRow(0,5,B00000001);
  delay(timer); 
  lc.setRow(0,1,B00000001); 
  lc.setRow(0,0,B00000001);
  lc.setRow(0,4,B00010001);
  lc.setRow(0,5,B00000000);
  delay(timer); 
  lc.setRow(0,1,B00000001); 
  lc.setRow(0,0,B00000001);
  lc.setRow(0,4,B00010000);
  lc.setRow(0,2,B00000001);
  delay(timer); 
  lc.setRow(0,1,B00000001); 
  lc.setRow(0,0,B00000001);
  lc.setRow(0,4,B00000000);
  lc.setRow(0,2,B00000001);
  lc.setRow(0,3,B00000001);
  delay(timer); 
  lc.setRow(0,1,B00000001); 
  lc.setRow(0,0,B00000000);
  lc.setRow(0,2,B00000001);
  lc.setRow(0,3,B00000011);
  delay(timer); 
  lc.setRow(0,1,B00000000); 
  lc.setRow(0,2,B00000001);
  lc.setRow(0,3,B00000111);
  delay(timer); 
  lc.setRow(0,2,B00000000);
  lc.setRow(0,3,B00001111);
  delay(timer); 
  lc.setRow(0,7,B10000000);
  lc.setRow(0,3,B00001110);
  delay(timer); 
  lc.setRow(0,7,B10001000);
  lc.setRow(0,3,B00001100);
  delay(timer); 
  lc.setRow(0,7,B10001000);
  lc.setRow(0,3,B00001000);
  lc.setRow(0,6,B00001000);
  delay(timer); 
  lc.setRow(0,7,B10001000);
  lc.setRow(0,3,B00000000);
  lc.setRow(0,6,B00001000);
  lc.setRow(0,5,B00001000);
  delay(timer); 
  lc.setRow(0,7,B00001000);
  lc.setRow(0,3,B00000000);
  lc.setRow(0,6,B00001000);
  lc.setRow(0,5,B10001000);
  delay(timer); 
   }lc.clearDisplay(0);
 }
 

 
 
void loop()

{
  allume();
  ferme();
  ligne();
  plateau();
  aleatoir2();
  mur();
  cube();
  plateau2();
  vague1();
  ligneverti();
  cube2();
  axe();
  aleatoir();
  elice();
  roue();
  vague2();
  vague3();
  diago();
  tunel();
  serpent();
}
