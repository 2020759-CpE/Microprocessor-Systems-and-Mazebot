#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int buttonpin = 9;
int passFlag = 0;
const unsigned long eventInterval = 300;
unsigned long previousTime = 0;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int initial = 0;
int oldstate = 0;
int buttonstate = 0;
void setup() {
 // put your setup code here, to run once:
 pinMode(buttonpin, INPUT);
 // initialize the LCD
 lcd.begin(16,2);
 // Turn on the blacklight and print a message.
 lcd.backlight();
}
void loop() {
digitalWrite(5,HIGH);
 unsigned long currentTime = millis();
 buttonstate = digitalRead(buttonpin);
 if (buttonstate == HIGH) {
 
 delay(50);
 buttonstate = digitalRead(buttonpin);
 if (buttonstate == LOW) {
 initial = oldstate + 1;
 passFlag = 0;
 }
 }
 else {
 delay(100);
 }
 switch (initial) {
 case 1:
 if (passFlag == 0) {
 hello();
 passFlag++; 
 passFlag; // Increment passFlag
 }
 oldstate = initial;
 break;
 case 2:
 if (passFlag == 0) {
 hi();
 passFlag++; 
 passFlag; // Increment passFlag
 }
 oldstate = initial;
 break;
 case 3:
 if (passFlag == 0) {
 hola();
 passFlag++; 
 passFlag; // Increment passFlag
 }
 while(digitalRead(buttonpin) != HIGH){
 currentTime = millis();
 if (currentTime - previousTime >= eventInterval){
 lcd.scrollDisplayLeft();
 previousTime = currentTime;
 }
 }
 oldstate = initial;
 break;
 default:
 lcd.clear();
 oldstate = 0;
 break;
 }
}
void hello() {
 lcd.clear();
 lcd.print(" HELLO, WORLD!");
 lcd.setCursor(0, 1);
 lcd.print(" ARDUINO");
 lcd.setCursor(17, 1);
}
void hi() {
 lcd.clear();
 lcd.print("Joaquin Castillo");
 lcd.setCursor(0, 1);
 lcd.print(" CPE3-A");
 lcd.setCursor(17, 1);
}
void hola() {
 lcd.clear();
 lcd.print("Mahal na mahal kita, bat moko iniwan");
}