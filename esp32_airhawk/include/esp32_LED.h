#ifndef ESP32_AIRHAWK__LED_H
#define ESP32_AIRHAWK_LED_ H

#include "driver/gpio.h"

#define LED_RED         (5)
#define LED_BLUE        (4)
#define LED_BUILTIN     (2)
#define LED_ON          (1)      
#define LED_OFF         (0)      


class esp32_airhawk_LED
{
    private:
    gpio_config_t io_pin0_config = {
        .pin_bit_mask = (1UL << LED_BUILTIN),      // Select GPIO 5 for RED
        .mode = GPIO_MODE_OUTPUT,            // Set as output
        .pull_up_en = GPIO_PULLUP_DISABLE,  // Disable pull-up
        .pull_down_en = GPIO_PULLDOWN_DISABLE,  // Disable pull-down
        .intr_type = GPIO_INTR_DISABLE             // Disable interrupts
    };
    gpio_config_t io_pin1_config = {
        .pin_bit_mask = (1UL << LED_RED),      // Select GPIO 5 for RED
        .mode = GPIO_MODE_OUTPUT,            // Set as output
        .pull_up_en = GPIO_PULLUP_DISABLE,  // Disable pull-up
        .pull_down_en = GPIO_PULLDOWN_DISABLE,  // Disable pull-down
        .intr_type = GPIO_INTR_DISABLE             // Disable interrupts
    };
    gpio_config_t io_pin2_config = {
        .pin_bit_mask = (1UL << LED_BLUE),      // Select GPIO 5 for RED
        .mode = GPIO_MODE_OUTPUT,            // Set as output
        .pull_up_en = GPIO_PULLUP_DISABLE,  // Disable pull-up
        .pull_down_en = GPIO_PULLDOWN_DISABLE,  // Disable pull-down
        .intr_type = GPIO_INTR_DISABLE             // Disable interrupts
    };
    public:
    void toggle_led();         
    void LED_red_enable();
    void LED_red_disable();
    void LED_blue_enable();
    void LED_blue_disable();
    esp32_airhawk_LED()
    {
        gpio_config(&io_pin0_config);   // BUILTIN LED
        gpio_config(&io_pin1_config);
        gpio_config(&io_pin2_config);
    }
    ~esp32_airhawk_LED();


};

#endif