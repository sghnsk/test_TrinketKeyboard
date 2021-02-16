/*
TrinketHidCombo example
For Trinket by Adafruit Industries
*/
#include <Arduino.h>

#include <TrinketHidCombo.h>

#define LED_PIN 1
#define KEY_CAPS_LOCK 0x39

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // start USB stuff
  TrinketHidCombo.begin();
}

void loop() {
  TrinketHidCombo.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  TrinketHidCompatibleDelay(1000);

  uint8_t led_state = TrinketHidCombo.getLEDstate();

  //test prints
  uint8_t buttonLEDstate = TrinketHidCombo.getLEDstate();
  TrinketHidCombo.print(buttonLEDstate,BIN); TrinketHidCombo.print(", "); TrinketHidCombo.println(buttonLEDstate);
  TrinketHidCombo.print("test"); TrinketHidCombo.print(", "); TrinketHidCombo.println(buttonLEDstate);
  TrinketHidCombo.println();

  //light up onboard LED when Caps Lock is on
  digitalWrite(LED_PIN, (TrinketHidCombo.getLEDstate()&KB_LED_CAPS)?HIGH:LOW);  


}

//this is a USB-compatible delay, so that the 10ms max time between poll calls is not exceeded
void TrinketHidCompatibleDelay(unsigned int desiredDelay) {
  unsigned long t_start = millis(); //ms
  while (millis()-t_start<desiredDelay) {
    TrinketHidCombo.poll();
  }
}