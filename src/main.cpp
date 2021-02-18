/*
TrinketKeyboard example
For Trinket by Adafruit Industries
*/
#include <Arduino.h>

#include <TrinketKeyboard.h>

#define LED_PIN 1

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // start USB stuff
  TrinketKeyboard.begin();
}

void loop() {
  delay(5);
  TrinketKeyboard.poll();
  
  //light up onboard LED when Caps Lock is on
  digitalWrite(LED_PIN, (TrinketKeyboard.getLEDstate()&KB_LED_SCROLL)?HIGH:LOW);  


}

