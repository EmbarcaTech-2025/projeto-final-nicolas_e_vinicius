#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led_task.h"
#include "neopixel.h"

void led_task(void *params)
{
    np_init(LED_PIN);

    while(1)
    {
        np_clear();
        np_set_led(0, 200, 0, 0);
        np_write();
        vTaskDelay(pdMS_TO_TICKS(1000));
        np_clear();
        np_set_led(9, 200, 200, 0);
        np_write();
        vTaskDelay(pdMS_TO_TICKS(1000));
        np_clear();
        np_set_led(10, 0, 200, 0);
        np_write();
        vTaskDelay(pdMS_TO_TICKS(1000));        
    }
}