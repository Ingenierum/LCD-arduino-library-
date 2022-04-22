
/*
This libraty is for control a LCD 16x2. Only We have the way to control
it, but needs the functions for write letters. You can modify and 
improve this code, I hope this code and explications help you. Thanks.

Author: Ingenierum
Channel: https://www.youtube.com/channel/UCORwLUePMYM2PxiMYqH7JxQ
Date: 2022-apr-22

*/

#define E 10 //Enable
#define rs 9 //RS pin
#define rw 8 //This pin make write/read function
#define d7 7 //D7
#define d6 6 //D6
#define d5 5 //D5
#define d4 4 //D4

//ENTRY MODE SET CONTROLS
#define ID HIGH //Increments (I/D = 1) or decrements (I/D = 0) the DDRAM address by 1 when a character code is written into or read from DDRAM
#define S LOW //Shifts the entire display either to the right (I/D = 0) or to the left (I/D = 1) when S is 1. The display does not shift if S is 0
//END ENTRY MODE SET CONTROLS

//DISPLAY ON/OFF CONTROL
#define C LOW //cursor
#define B HIGH //blinck
//END DISPLAY ON/OFF CONTROL 

//FUNCTION SET CONTROL
//#define DL LOW //data 8bits when DL is HIGHT and 4bits when is LOW
#define N  LOW //sets number of display lines
#define F  LOW //sets the charter fonts
//END FUNCTION SET CONTROL 

//--------BEGIN FUNCTIONS ------

//*************FUNCTION SET 8bits***************
void function_set8(){
digitalWrite(d7,LOW);
digitalWrite(d6,LOW);
digitalWrite(d5,HIGH);
digitalWrite(d4,HIGH);
delayMicroseconds(40);
enable();
}
//END FUNCTION SET 8bits

//FUNCTION SET 4BITS WHITOUT N,F PARAMETERS
void function_set4(){
  digitalWrite(d7,LOW);
  digitalWrite(d6,LOW);
  digitalWrite(d5,HIGH);
  digitalWrite(d4,LOW);
  delayMicroseconds(40);
enable();
}
//FUNCTION SET 4bits with parameters
void function_set(){
digitalWrite(d7,LOW);
digitalWrite(d6,LOW);
digitalWrite(d5,HIGH);
digitalWrite(d4,LOW);
delayMicroseconds(40);
enable();
digitalWrite(d7,N);
digitalWrite(d6,F);
digitalWrite(d5,LOW);
digitalWrite(d4,LOW);
delayMicroseconds(40);
enable();
}
//END FUNCTION SET 4bits

//**************END FUNCTION SET***************

//DISPLAY OFF
void off(){
digitalWrite (d7,LOW);
digitalWrite (d6,LOW);
digitalWrite (d5,LOW);
digitalWrite (d4,LOW);
delayMicroseconds(40);
enable();
digitalWrite (d7,HIGH);
digitalWrite (d6,LOW);
digitalWrite (d5,C);
digitalWrite (d4,B);
delayMicroseconds(40);
enable();
}
//END DISPLAY OFF

//DISPLAY ON 
void on(){
digitalWrite(d7,LOW);
digitalWrite(d6,LOW);
digitalWrite(d5,LOW);
digitalWrite(d4,LOW);
delayMicroseconds(40);
enable();
digitalWrite(d7, HIGH);
digitalWrite(d6, HIGH);
digitalWrite(d5, C);
digitalWrite(d4, B);
delayMicroseconds(40);
enable();
}
//END DISPLAY ON 

//ENTRY MODE SET
void mode_set(){
digitalWrite(d7, LOW);
digitalWrite(d6, LOW);
digitalWrite(d5, LOW);
digitalWrite(d4, LOW);
delayMicroseconds(40);
enable();
digitalWrite(d7, LOW);
digitalWrite(d6, HIGH);
digitalWrite(d5, ID);
digitalWrite(d4, S);
delayMicroseconds(40);
enable();
}
//END ENTRY MODE SET

//CLEAR DISPLAY
void clear_(){
digitalWrite(d7, LOW);
digitalWrite(d6, LOW);
digitalWrite(d5, LOW);
digitalWrite(d4, LOW);
delayMicroseconds(40);
enable();
digitalWrite(d7, LOW);
digitalWrite(d6, LOW);
digitalWrite(d5, LOW);
digitalWrite(d4, HIGH);
delayMicroseconds(40);
enable();
}

//END CLEAR DISPLAY

//INIT LCD FUNCTION 
void lcd_init(){
 delay(50);
 function_set8();
 delay(4.1);
 function_set8();
 delayMicroseconds(100);
 function_set8();
 function_set4();
 function_set();
 off();
 clear_();
 mode_set();
}
//END LCD INIT 

//ENABLE
void enable(){
digitalWrite(E, LOW);
delay(40);
digitalWrite(E, HIGH);
delay(40);
digitalWrite(E, LOW);
delay(40);
}
//END ENABLE
//-----------------END -------------

/*THERE ARE TWO NUMBERS: THREE AND FOUR. YOU CAN TRY
TO MAKE OTHERS CARACTERS AND IMPROVE THIS CODE. 
YOU'RE FREE TO MODIFY AND USE THIS CODE LIKE YOU WANT. 
                     GOOD LOOK!!
*/
void tres(){//PRINT NUMBER THREE 
  digitalWrite(rs, HIGH);

  digitalWrite(d7, LOW);
  digitalWrite(d6, LOW);
  digitalWrite(d5, HIGH);
  digitalWrite(d4, HIGH);
  delayMicroseconds(40);
  enable();
  digitalWrite(d7, LOW);
  digitalWrite(d6, LOW);
  digitalWrite(d5, HIGH);
  digitalWrite(d4, HIGH);
  delayMicroseconds(40);
  enable();
  digitalWrite(rs, LOW);
  delayMicroseconds(40);
  enable();
}


void cuatro(){//PRINT NUMBER FOUR
  digitalWrite(rs, HIGH);

  digitalWrite(d7, LOW);
  digitalWrite(d6, HIGH);
  digitalWrite(d5, LOW);
  digitalWrite(d4, LOW);
  delayMicroseconds(40);
  enable();
  digitalWrite(d7, LOW);
  digitalWrite(d6, LOW);
  digitalWrite(d5, HIGH);
  digitalWrite(d4, HIGH);
  delayMicroseconds(40);
  enable();
  digitalWrite(rs, LOW);
  delayMicroseconds(40);
  enable();
}


void setup() {
  
for (int i = 4; i <= 11; i++){
    pinMode(i, OUTPUT);
  }
  analogWrite(3,200); //CHANGUE BACKGROUND LIGHT INTENSITY
  
  analogWrite(11,100);//CHANGE DOTS INTENSITY 

//BEGIN WITH RW AND RS WITH A LOW VALUE
  digitalWrite(rw, LOW); //MAKES RW LOW (READ/WIRTE)
  digitalWrite(rs,LOW); //MAKES RS LOW
}

void loop() {
  lcd_init(); //LCD INIT FUNCTION
  on(); //TURN ON LCD
  tres(); //PRINT NUMBER THREE ON SCREEN
  cuatro();//PRINT NUMBER FOUR ON SCREEN 
  while(true){}
}
