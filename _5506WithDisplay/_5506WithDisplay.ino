//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("LightSensor 5506"); // print a simple message
 pinMode(2, OUTPUT);
}
 
void loop()
{
 int adc_in = analogRead(A1);

 lcd.setCursor(0,1);            // move to the begining of the second line
 lcd.print(adc_in);             // print a simple message
 if(adc_in>300){
   lcd.display();
   delay(250);
 } else {
   lcd.noDisplay();
   digitalWrite(2, HIGH);
   delay(250);
   lcd.display();
   digitalWrite(2, LOW);
 }
 delay(250);
 lcd.print("    ");

}

