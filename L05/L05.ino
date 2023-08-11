#include <Keypad.h>
#include <Servo.h>
#include <Stepper.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 4, 3, 2, A4, A5);


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, 11, 10}; 
byte colPins[COLS] = {9, 8, 7, 6}; 
int LCDRow = 0;

int rojo = 13;
int azul = 12;
int cont = 0;


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.setCursor(LCDRow, 0);
   digitalWrite(13,LOW);
   digitalWrite(12,LOW);
   lcd.print("ENTER PASS:");
   }
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
    lcd.print(key);
    lcd.setCursor (++LCDRow, 0);
    if (key=='1'){
      digitalWrite(13,  LOW);
      digitalWrite(12,HIGH);
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("VALIDA");
     cont = 0;
    }
    else if (key=='C'){
      lcd.clear();
      lcd.setCursor(0, 0);
      LCDRow = 0;
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      lcd.setCursor(0, 0);
      lcd.print("ENTER PASS:");
       
    }
    else if (key!='1'){
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("INVALIDA");
      cont = cont +1;
      lcd.setCursor(0, 1);
      lcd.print("TOAL ERRORS: ");
      lcd.setCursor(13, 1);
      lcd.print(cont);
      
    }
    
  }
  
}
