#include <LiquidCrystal.h> 
int count = 0;
int buttonState = 0;
int prevButtonState = 0;
const int buzzer = 9; 

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

void setup() { 
  lcd.begin(16,2);
    
    pinMode(8, INPUT_PULLUP); 
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
 } 

void loop() {


  buttonState = digitalRead(8);
  if (buttonState != prevButtonState) {
    if(buttonState == 0){
      count++;
      Serial.println(count);
      lcd.clear();
      tone(buzzer, 1000);
      delay(25);
      noTone(buzzer); 
      delay(25);
      lcd.print("Clicks: ");
      lcd.print(count);
    }
    delay(1);
  }
   prevButtonState = buttonState;

}






