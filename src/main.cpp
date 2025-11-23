#include <Arduino.h>
#include "esp32_airhawk_WIFI.h"

esp32_airhawk_WIFI airhawk_WIFI;


void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.print("Hello world");
    airhawk_WIFI.start_AP();
}

void loop() {
  Serial.println("Hi there");
  delay(1000);
  // put your main code here, to run repeatedly:
}
