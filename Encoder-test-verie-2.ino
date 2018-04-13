//
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x38, 16, 2); // Zet het i2c adres op 0x38 16 karakters en 2 regels.
int val;
int encoder0PinA = 3;
int encoder0PinB = 4;
int encoder0Pos = 0;
byte Schakelaar = 7;
int encoder0PinALast = LOW;
int n = LOW;
byte Waarde_schakelaar = HIGH;



void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Zet een melding op het scherm.
  lcd.backlight();
  lcd.setCursor(2, 0);      //Zet de cursor op positie 4  regel 0
  lcd.print("Encoder test");

  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (Schakelaar, INPUT);
}




void loop() 
{
  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
    lcd.setCursor (0, 1);    //Zet de cursor aan het begin van de regel
    lcd.print("     ");      //Print wat spaties om het scherm schoon te maken
    lcd.setCursor (0, 1);   //En zet de cursor weer terug op postie 1
    lcd.print(encoder0Pos); //Print dan de waarde van de var

  }
  encoder0PinALast = n;
  {
    Waarde_schakelaar = digitalRead (Schakelaar);//Hier wordt de waarde van pin#7 ingelezen en in de var Waarde_schakelaar gezet
    lcd.setCursor (8, 1);                        //Zet de cursor op regel 1 positie 8
    lcd.print("Waarde ");
    lcd.print( Waarde_schakelaar);               //Print de waarde van de var Waarde_schakelaar
    if (Waarde_schakelaar == 0 ) {               //Als de Waarde_schakelaar < 1 dan reset LET op == 2 is gelijk teken!!
      lcd.setCursor (0, 1);
      lcd.print ("Reset");
      lcd.setCursor (0, 1);
      delay (1000);
      lcd.print ("           ");

    }

  }
  if(encoder0Pos == 20 || encoder0Pos == -20) // If var > 20 OR (||) == -20 De or funtie = de 2 ||
    { 
      lcd.setCursor (0,1);
      lcd.print("Max bereikt         ");
      delay(1000);
      lcd.setCursor (0,1);
      //lcd.print( "                    ") ;
      lcd.clear();                      //Hiermee wis je het hele scherm! en zet je de cursor op postie 0 en regel 0 
      lcd.print (" Encoder test");      //En print dan opnieuw de text "Encoder test"
      encoder0Pos =0;
      
    }
}

