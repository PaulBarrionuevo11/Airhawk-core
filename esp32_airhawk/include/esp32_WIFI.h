#ifndef ESP32_AIRHAWK_WIFI_H
#define ESP32_AIRHAWK_WIFI_H

#include <WiFi.h>
#include "stdint.h"



class esp32_airhawk_WIFI
{
private:
    const char* AP_ssid = "DroneXplore";
    const char* AP_password = "MyDrone12345";   
    const char* ssid = "MyNetwork";
    const char* password = "MyPassword"; 

public:
    esp32_airhawk_WIFI(/* args */);     // (const char* s, const char* p) : ssid(s), password(p) {}
    ~esp32_airhawk_WIFI();
    void start_AP();
    void connect_WIFI(const char* s, const char* p);                     // Connect to wifi TODO:
    void disconnect_WIFI();
    void start_server_communication();                                  // Handles first series of comm with server
    void transmit_data();                                               // Send data to python server
    uint32_t receive_data();                                            // Receive data from python server
    void check_WIFI_status();
};

esp32_airhawk_WIFI::esp32_airhawk_WIFI(/* args */)
{
    // connect_WIFI(ssid, password);

}
void esp32_airhawk_WIFI::start_AP()
{
    Serial.println("Setting up Access Point...");
    delay(1000);
    WiFi.softAP(AP_ssid, AP_password);
    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP());
    delay(1500);
    Serial.println(WiFi.status());
    delay(1500);
}

void esp32_airhawk_WIFI::connect_WIFI(const char* s, const char* p)
{
    Serial.printf("Connecting to network: %s with password: %s\n", ssid, password);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\nConnected!");
    Serial.printf("IP Address: %s\n", WiFi.localIP().toString().c_str());
}

void esp32_airhawk_WIFI::disconnect_WIFI()
{
    WiFi.disconnect(true);
    if (WiFi.status() == WL_DISCONNECTED)
    {
        Serial.println("Disconnected from Wi-Fi!");
    } 
    else {
        Serial.println("Failed to disconnect from WiFi.");
    }
}

esp32_airhawk_WIFI::~esp32_airhawk_WIFI()
{
    // disconnect_WIFI();
}

void esp32_airhawk_WIFI::check_WIFI_status()
{
}


#endif