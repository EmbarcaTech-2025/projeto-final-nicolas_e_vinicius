#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "pico/cyw43_arch.h"
#include "lwip/pbuf.h"
#include "lwip/tcp.h"
#include "traffic_lights_task.h"
#include "neopixel.h"
#include "traffic_light_control.h"
#include "display_task.h"

const char *AP_NAME = "RP_AP";
const char *AP_PASS = "Smart_Crossing";

void ap_task(void *params)
{
    vTaskDelay(pdMS_TO_TICKS(3000));

    if (cyw43_arch_init()) {
        printf("Failed to initialise cyw43\n");
    }

    cyw43_arch_enable_ap_mode(AP_NAME, AP_PASS, CYW43_AUTH_WPA2_AES_PSK);

    while(1)
    {
        cyw43_arch_poll();
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}
