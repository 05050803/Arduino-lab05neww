#include<Keypad.h>
#include "SevSeg.h"
const byte ROWS=4,COLS=4;
SevSeg sevseg;

char keys[ROWS][COLS] = {{'7','8','9','C'},{'4','5','6','D'},{'1','2','3','E'},{'0','A','B','F'}};

byte rowPins[ROWS] = {8,9,10,11};
byte colPins[COLS] = {2,3,4,5};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup(){
  byte numDigits = 1;
  byte digitPins[] = {7};
  byte segmentPins[] = {6,12,13,14,15,16,17};
  sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
  Serial.begin(9600);
}
void loop(){
  char key = keypad.getKey();

  if(key!=NO_KEY){
    Serial.println(key);
    if(key>='0' && key <='9')
      sevseg.setNumber(key-'0',1);
  }
  sevseg.refreshDisplay();
}
