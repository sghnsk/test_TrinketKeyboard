/*
TrinketKeyboard example
For Trinket by Adafruit Industries
*/
#include <Arduino.h>

#include <TrinketKeyboard.h>

#define LED_PIN 1
#define KEY_CAPS_LOCK 0x39

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // start USB stuff
  TrinketKeyboard.begin();
}

void loop() {
  TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  TrinketHidCompatibleDelay(1000);

  uint8_t led_state = TrinketKeyboard.getLEDstate();

  //test prints
  uint8_t buttonLEDstate = TrinketKeyboard.getLEDstate();
  TrinketKeyboard.print(buttonLEDstate,BIN); TrinketKeyboard.print(", "); TrinketKeyboard.println(buttonLEDstate);
  TrinketKeyboard.print("test"); TrinketKeyboard.print(", "); TrinketKeyboard.println(buttonLEDstate);
  TrinketKeyboard.println();

  //light up onboard LED when Caps Lock is on
  digitalWrite(LED_PIN, (TrinketKeyboard.getLEDstate()&KB_LED_CAPS)?HIGH:LOW);  


}

//this is a USB-compatible delay, so that the 10ms max time between poll calls is not exceeded
void TrinketHidCompatibleDelay(unsigned int desiredDelay) {
  unsigned long t_start = millis(); //ms
  while (millis()-t_start<desiredDelay) {
    TrinketKeyboard.poll();
  }
}