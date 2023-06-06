void setup() {
  // put your setup code here, to run once:
#include "dht.h"
#include <LiquidCrystal_I2C.h>
#define dht_apin A0 // Analog Pin sensor is connected to
LiquidCrystal_I2C lcd(0x27, 2, 16);
dht DHT;

int period = 1000;
unsigned long time_now = 0;

int light;
int buttonpin = 9;
int passFlag = 0;
int initial = 0;
int oldstate = 0;
int buttonstate = 0;

void ldr(){
  
  time_now = millis();

  light = analogRead(A1);
  lcd.clear();
  //lcd.setCursor(0,0); 
  lcd.print("Light: ");
  lcd.print(light);

  while(millis() < time_now + 50){
        
    }
  

}
void temperature(){
  time_now = millis();

    DHT.read11(dht_apin);
    lcd.setCursor(0,0); 
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
    while(millis() < time_now + 50){
        
    }
}
 
void setup(){
  pinMode(buttonpin, INPUT);
  lcd.init();
  lcd.backlight();


  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop() {


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
        while(buttonstate!=HIGH){
          buttonstate = digitalRead(buttonpin);
        temperature();}
        passFlag++;                     // Increment passFlag
      }
      oldstate = initial;
      break;

    case 2:

      if (passFlag == 0) {
        while(buttonstate!=HIGH){
          buttonstate = digitalRead(buttonpin);
        ldr();}
        passFlag++;                     // Increment passFlag
      }
      oldstate = initial;
      break;

    default:
      lcd.clear();
      initial = 1;
      break;
  }
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
