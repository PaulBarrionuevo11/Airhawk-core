#include "esp32_WIFI.h"
#include "esp32_LED.h"

esp32_airhawk_WIFI airhawk_WIFI;
esp32_airhawk_LED airhawk_LED;

void setup() {
    Serial.begin(115200);
    Serial.print("Hello world");
    airhawk_WIFI.start_AP();
    airhawk_LED.toggle_led();
}

void loop() {


}
