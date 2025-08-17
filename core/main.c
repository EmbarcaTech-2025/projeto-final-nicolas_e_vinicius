#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led_task.h"

int main() {

    stdio_init_all();

    xTaskCreate(led_task, "Traffic Lights", configMINIMAL_STACK_SIZE + 256, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1)
    {
        
    }

    return 0;
}
