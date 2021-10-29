/* C++ ESP-C3-32S-Kit LED Blink example
   author: corbamico@163.com

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <array>
#include <algorithm>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "sdkconfig.h"

/*
C++17, for, auto is much more easy for coding :-)

ESP-C3-32S-Kit use led as IO3,4,5,18,19:

https://docs.ai-thinker.com/esp32c3
https://docs.ai-thinker.com/_media/esp32/docs/esp-c3-32s-kit-v1.0_%E8%A7%84%E6%A0%BC%E4%B9%A6.pdf
ESP-C3-32S-Kit
IO5 接 RGB 的蓝色灯珠；IO3 接 RGB 的红色灯珠；IO4 接 RGB 的
绿色灯珠；IO19 接冷色灯珠；IO18 接暖色灯珠；

*/

static const char *TAG = "blink";
extern "C" void app_main(void)
{
    std::array LEDs{GPIO_NUM_3,GPIO_NUM_4,GPIO_NUM_5,GPIO_NUM_18,GPIO_NUM_19};

    static uint32_t _s_counter = 0;
    esp_err_t ret = nvs_flash_init();
    if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)   {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    ESP_LOGI(TAG,"init led gpio");
    for(auto led:LEDs){
        gpio_reset_pin(led);
        gpio_set_direction(led,GPIO_MODE_OUTPUT);
    }
    while(1){    
        for(auto led: LEDs){
            ESP_LOGI(TAG,"led tick: %d",_s_counter++);
            gpio_set_level(led,1);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            gpio_set_level(led,0);
            vTaskDelay(1000/portTICK_PERIOD_MS);
        }
    }
}
