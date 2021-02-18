#include <Arduino.h>
#include <TrinketKeyboard.h>

#define LED_PIN 1
#define LED_PIN_DELAY 200
#define KB_LED_STATE_MASK KB_LED_NUM
#define KB_LED_STATE_WAIT 1500
#define KB_LED_STATE_NUM 4

unsigned long previousMillis = 0;
uint8_t lastKbLedState = 0;
int countKbLedState = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  TrinketKeyboard.begin();
}

void loop() {
  delay(5);
  TrinketKeyboard.poll();

  uint8_t kbledState = TrinketKeyboard.getLEDstate() & KB_LED_STATE_MASK;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= KB_LED_STATE_WAIT) {
    previousMillis = currentMillis;
    countKbLedState = 0;
  } else {
    if (kbledState != lastKbLedState)
        countKbLedState++;
  }
  lastKbLedState = kbledState;
  if (countKbLedState == KB_LED_STATE_NUM) {
    countKbLedState = 0;
    digitalWrite(LED_PIN, HIGH);
    delay(LED_PIN_DELAY);
    digitalWrite(LED_PIN, LOW);
  }
}