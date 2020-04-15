#include <Keypad.h>
int seg7[]={6,12,13,14,15,16,17};
char ch;
char TAB[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};
char bbb[]={0x77,0x7C,0x39,0x5E,0x79,0x71};
int i,j;
byte no=0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {{'7','8','9','C'},{'4','5','6','D'},{'1','2','3','E'},{'0','A','B','F'}};
byte rowPins[ROWS] = {8,9,10,11};
byte colPins[COLS] = {2,3,4,5};
Keypad keypad =Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );

void setup() {
for(i=0;i<7;i++){
    pinMode(seg7[i],OUTPUT);
  }
 Serial.begin(9600);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY){
    Serial.println(key);
    if(key>='0'&&key<='9')
  {
    no=key-'0';
  
    OutPort(TAB[no]);
    delay(500);
  }

   if(key>='A'&&key<='F')
  {
    no=key-'A';
  
    OutPort(bbb[no]);
    delay(500);
  }

  }
}
void OutPort(byte dat){
  for(j=0;j<7;j++){
    if(dat%2==1)
      digitalWrite(seg7[j],HIGH);
    else
      digitalWrite(seg7[j],LOW);
      dat=dat/2;
  }
}
