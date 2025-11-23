#include "esp32_LED.h"
#include "Arduino.h"

esp32_airhawk_LED::~esp32_airhawk_LED()
{

}
void esp32_airhawk_LED::toggle_led()
{
    /*
        GPIO_02 = BUILTIN
        GPIO_05 = LED RED
        GPIO_04 = LED BLUE
    */

    for (int i=0; i<3; i++)
    {
    delay(1500);
    gpio_set_level(GPIO_NUM_2, LED_ON);     
    delay(1500);
    gpio_set_level(GPIO_NUM_2, LED_OFF);
    delay(1500);
    gpio_set_level(GPIO_NUM_2, LED_ON);
    delay(1500);
    gpio_set_level(GPIO_NUM_2, LED_OFF);

    }


}     
void esp32_airhawk_LED::LED_red_enable()
{
    gpio_set_level(GPIO_NUM_5, LED_ON);

}
void esp32_airhawk_LED::LED_red_disable()
{
    gpio_set_level(GPIO_NUM_5, LED_OFF);

}
void esp32_airhawk_LED::LED_blue_enable()
{
    gpio_set_level(GPIO_NUM_4, LED_ON);
}
void esp32_airhawk_LED::LED_blue_disable()
{
    gpio_set_level(GPIO_NUM_4, LED_OFF);
}
