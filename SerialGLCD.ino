
#include <PCD8544.h>
int LED=7;
static PCD8544 lcd;
void setup()
{
  Serial.begin(9600);
 pinMode(LED,OUTPUT);
  Serial.println("Test Display Oke");
 lcd.begin(84, 48);
}
void loop()
{
  lcd.setContrast(40);
  if (Serial.available()) {
   delay(100);
   lcd.clear();
   digitalWrite(LED,LOW);
    lcd.setCursor(0, 0);
   while (Serial.available() > 0) {
    lcd.write(Serial.read());
      digitalWrite(LED,HIGH);
       lcd.write(0);
    }
  }
}