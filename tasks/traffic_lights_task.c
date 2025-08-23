#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "traffic_lights_task.h"
#include "neopixel.h"
#include "traffic_light_control.h"

uint8_t traffic_state;

void traffic_lights_task(void *params)
{
    np_init(LED_PIN);
    traffic_state = PEOPLE_GREEN;

    led_green_on(PEOPLE);
    led_red_on(CAR);

    while(1)
    {
        
        switch (traffic_state)
        {
        case PEOPLE_GREEN:
            led_green_on(PEOPLE);
            np_write();
            vTaskDelay(pdMS_TO_TICKS(get_time_green(PEOPLE)));
            traffic_state = PEOPLE_YELLOW;
            break;

        case PEOPLE_YELLOW:
            led_yellow_on(PEOPLE);
            np_write();            vTaskDelay(pdMS_TO_TICKS(YELLOW_TIME));
            traffic_state = PEOPLE_RED;
            break;

        case PEOPLE_RED:
            led_red_on(PEOPLE);
            np_write();
            vTaskDelay(pdMS_TO_TICKS(get_time_to_turn_green(CAR)));
            traffic_state = CAR_GREEN;
            break;

        case CAR_GREEN:
            led_green_on(CAR);
            np_write();
            ulTaskNotifyTake(pdTRUE, pdMS_TO_TICKS(get_time_green(CAR)));
            vTaskDelay(pdMS_TO_TICKS(TIME_TO_CLOSE_CAR_AFTER_PRESENCE));
            traffic_state = CAR_YELLOW;
            break;

        case CAR_YELLOW:
            led_yellow_on(CAR);
            np_write();
            vTaskDelay(pdMS_TO_TICKS(YELLOW_TIME));
            traffic_state = CAR_RED;
            break;

        case CAR_RED:
            led_red_on(CAR);
            np_write();
            vTaskDelay(pdMS_TO_TICKS(get_time_to_turn_green(PEOPLE)));
            traffic_state = PEOPLE_GREEN;
            break;

        default:
            break;
        }
    }
}