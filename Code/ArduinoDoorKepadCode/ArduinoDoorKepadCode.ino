#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


const String password = "4123";
  static String enterpassword;
 long i=0;
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};
byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
void setup()
{
    Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
   //Serial.begin(9600);
  lcd.init();          
  lcd.backlight();
  pinMode(13, OUTPUT);
  
  
 
}

void loop()
{
  
  char key = keypad.getKey();
    
  if (key != NO_KEY){
  if(key!='D')
    { if(enterpassword=="")
    {lcd.clear();}
    enterpassword += key;
     Serial.println(key);
     lcd.print(key);
  }}
  //Serial.println(enterpassword);
  //Serial.println(password);
  if(key=='D')
    {if (enterpassword.length() == password.length()) {
   if (enterpassword == password){
     Serial.println("Correct");
     enterpassword="";
     lcd.clear();
   lcd.setCursor(0,0);
     lcd.print("Correct");
     digitalWrite(13, HIGH);
     delay(1000);              
  digitalWrite(13, LOW);   
  delay(1000);    
   }
     else if(enterpassword != password)
     {Serial.println("Incorrect");
      enterpassword="";
      lcd.clear();
   lcd.setCursor(0,0);
     lcd.print("Incorrect");}
    }
   
      else if(enterpassword.length() != password.length())
      {Serial.println("Enter 4 characters");
       enterpassword="";
       lcd.clear();
   lcd.setCursor(0,0);
     lcd.print("Enter four");
        lcd.setCursor(0,1);
       lcd.print("character");
      }
  
    }
 if(key=='C')
 {enterpassword="";
 Serial.println("Cleared");
   lcd.clear();
   lcd.setCursor(0,0);
     lcd.print("Cleared");
 }
   if(key=='#')
 {enterpassword="";
 Serial.println("SLEEPING");
   lcd.clear();
   lcd.setCursor(0,0);
     lcd.print("SLEEPING");
 }
   if(key=='*')
   {enterpassword="";
    lcd.clear();
   lcd.setCursor(0,0);
     lcd.print("Privacy Mode");
    lcd.setCursor(0,1);
     lcd.print("Activated");
     lcd.setCursor(0,0);
    delay(1000);
    lcd.clear();
   lcd.setCursor(0,0);
     while(1)
   {
        char key = keypad.getKey();
        lcd.print("Press key to");
       lcd.setCursor(0,1);
       lcd.print("unlock except  *");
        if (key != NO_KEY && key!='*'){
          if(enterpassword=="")
    {lcd.clear();}
    enterpassword += key;
     Serial.println(key);
           lcd.clear();
   lcd.setCursor(0,0);
     lcd.print("Correct wait for");
          lcd.setCursor(0,1);
          lcd.print("5 second");
          delay(5000);
          digitalWrite(13, HIGH);
     delay(1000);              
  digitalWrite(13, LOW);   
  delay(1000); 
            enterpassword="";
           lcd.clear();
   lcd.setCursor(0,0);
  }
       
    if(key=='*')
    {enterpassword="";
      lcd.clear();
   lcd.setCursor(0,0);
          lcd.print("Privacy Mode");
    lcd.setCursor(0,1);
     lcd.print("Deactivated");
       delay(2000);
     lcd.clear();
   lcd.setCursor(0,0);
      break;
    
    } 
   }
   
   }

}
