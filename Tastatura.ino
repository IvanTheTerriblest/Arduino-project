
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const byte ROWS = 4;
const byte COLS = 4;
String firstRow;
String secondRow;
String letterSecondRow;
  int counter;
  String letter;

int nrPresses=0;
int cursorRand = 1;

char keys[ROWS][COLS] ={
{'1', '2', '3', 'A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

char alfabet[36]={'A','B','C','1','D','E','F','2','G','H','I','3','J','K','L','4','M','N','O','5','P','Q','R','6','S','T','U','7','V','W','X','8','Y','Z','0','9'};

byte rowPins[ROWS]={33,32,31,30};
byte colPins[COLS] = {29,28,27,26};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins,colPins,ROWS,COLS);
LiquidCrystal_I2C lcd(0x27,16,2);  

void setup(){
 
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Ivan Smecher");
  Serial.begin(9600);
  lcd.clear();
       lcd.setCursor(15,0);
    lcd.print(nrPresses);
    lcd.setCursor(0,0);
}

void loop(){
  char myKey = customKeypad.getKey();

 
  if (myKey == 'D'){
    nrPresses=(nrPresses+1)%4;
    lcd.setCursor(15,0);
    lcd.print(nrPresses);
    
  }
  else{
    
    
    if(myKey == '1'){
       letter = String(alfabet[nrPresses]);
       letterSecondRow = String(alfabet[nrPresses]);
   firstRow += letter;
   cursorRand++;
   
     lcd.print(letter);
    }
    if(myKey == '2'){
       letter = String(alfabet[nrPresses+4]);
       letterSecondRow = String(alfabet[nrPresses+4]);
   firstRow += letter;
    cursorRand++;
    
     lcd.print(letter);
    }
     if(myKey == '3'){
       letter = String(alfabet[nrPresses+8]);
       letterSecondRow = String(alfabet[nrPresses+8]);
   firstRow += letter;
    cursorRand++;
    
     lcd.print(letter);
    }
     if(myKey == '4'){
       letter = String(alfabet[nrPresses+12]);
       letterSecondRow = String(alfabet[nrPresses+12]);
   firstRow += letter;
    cursorRand++;
    lcd.print(letter);
    }
     if(myKey == '5'){
       letter = String(alfabet[nrPresses+16]);
       letterSecondRow = String(alfabet[nrPresses+16]);
   firstRow += letter;
    cursorRand++;
    lcd.print(letter);
    }
     if(myKey == '6'){
       letter = String(alfabet[nrPresses+20]);
       letterSecondRow = String(alfabet[nrPresses+20]);
   firstRow += letter;
    cursorRand++;
    lcd.print(letter);
    }
     if(myKey == '7'){
       letter = String(alfabet[nrPresses+24]);
       letterSecondRow = String(alfabet[nrPresses+24]);
   firstRow += letter;
    cursorRand++;
    lcd.print(letter);
    }
     if(myKey == '8'){
       letter = String(alfabet[nrPresses+28]);
       letterSecondRow = String(alfabet[nrPresses+28]);
   firstRow += letter;
    cursorRand++;
    lcd.print(letter);
    }
     if(myKey == '9'){
       letter = String(alfabet[nrPresses+32]);
       letterSecondRow = String(alfabet[nrPresses+32]);
   firstRow += letter;
    cursorRand++;
    lcd.print(letter);
    }
    if(myKey == '0'){
       letter = " ";
       letterSecondRow = " ";
   firstRow += letter;
    cursorRand++;
    lcd.print(letter);
    }
    
    if (myKey == 'A'){
      lcd.clear();
       lcd.setCursor(15,0);
    lcd.print(nrPresses);
    lcd.setCursor(0,0);
    letter=' ';
      firstRow.remove(0,firstRow.length());
      cursorRand=1;
    }
    
if(myKey == '#'){
      lcd.setCursor(firstRow.length()-1,0);
      lcd.print(' ');
       firstRow.remove(firstRow.length()-1,1);
       lcd.setCursor(0,0);
       lcd.print(firstRow);
       
       cursorRand--;
    }
     
     

  
  if(firstRow.length()<16 ){
     lcd.setCursor(cursorRand-1,0);
     
     
  }else{
    
  
   //lcd.print(myWord.length());
    secondRow += letterSecondRow;
    lcd.setCursor(cursorRand%16,1);
    lcd.print(letterSecondRow);
   }

   }
  }
  
