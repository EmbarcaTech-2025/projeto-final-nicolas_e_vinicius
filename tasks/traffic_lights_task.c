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
            traffic_state = PEOPLE_YELLOW;
            break;

        case PEOPLE_YELLOW:
            led_yellow_on(PEOPLE);
            traffic_state = PEOPLE_RED;
            break;

        case PEOPLE_RED:
            led_red_on(PEOPLE);
            traffic_state = CAR_GREEN;
            break;

        case CAR_GREEN:
            led_green_on(CAR);
            traffic_state = CAR_YELLOW;
            break;

        case CAR_YELLOW:
            led_yellow_on(CAR);
            traffic_state = CAR_RED;
            break;

        case CAR_RED:
            led_red_on(CAR);
            traffic_state = PEOPLE_GREEN;
            break;

        default:
            break;
        }

        np_write();

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}