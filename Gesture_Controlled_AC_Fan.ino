#include <Wire.h>
#include "Adafruit_APDS9960.h"
#include <LiquidCrystal.h>
Adafruit_APDS9960 apds;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int relay = 8;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay,HIGH);
  lcd.begin(16, 2);
  Wire.begin();
  
  if(!apds.begin()){
    lcd.print("Please check your wiring");
  }
  else lcd.print("Give Gesture");

  apds.enableProximity(true);
  apds.enableGesture(true);
}


void loop() {
  
    uint8_t gesture = apds.readGesture();
    lcd.setCursor(0, 1);
    if(gesture == APDS9960_DOWN){
       lcd.print("DOWN");
       digitalWrite(relay, HIGH);
       
    }
    if(gesture == APDS9960_UP){
       lcd.print("UP");
       digitalWrite(relay, LOW);
       
    }
    
}