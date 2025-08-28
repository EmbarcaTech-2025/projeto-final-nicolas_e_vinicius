#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "FreeRTOS.h"
#include "task.h"
#include "traffic_lights_task.h"
#include "sensor_task.h"
#include "display_task.h"
#include "wifi_task.h"
#include "vl53l0x_wrapper.h"
#include "task_handles.h"

#define VL0X_SDA 0
#define VL0X_SCL 1
#define I2C_PORT i2c0
#define SENSOR_ADDR 0x29

TaskHandle_t handle_tl_task         = NULL;
TaskHandle_t handle_sensor_task     = NULL;
TaskHandle_t handle_display_task    = NULL;
TaskHandle_t handle_wifi_task       = NULL;

int main() {

    stdio_init_all();

    xTaskCreate(traffic_lights_task, "Traffic Lights", configMINIMAL_STACK_SIZE + 256, NULL, 1, &handle_tl_task);
    xTaskCreate(sensor_task, "Presence Sensor", configMINIMAL_STACK_SIZE + 256, NULL, 1, &handle_sensor_task);
    xTaskCreate(display_task, "Display", configMINIMAL_STACK_SIZE + 256, NULL, 1, &handle_display_task);
    xTaskCreate(wifi_task, "WIFI", configMINIMAL_STACK_SIZE + 256, NULL, 1, &handle_wifi_task);

    vTaskStartScheduler();

    while (1)
    {
        
    }

    return 0;
}
