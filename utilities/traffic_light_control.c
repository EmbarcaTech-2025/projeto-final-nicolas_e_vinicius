#include <stdlib.h>
#include "pico/stdlib.h"
#include "neopixel.h"
#include "traffic_light_control.h"

void led_green_on(uint8_t people_or_car){
    
    if(people_or_car == PEOPLE)
    {
        np_set_led(PEOPLE_RED_LED_NUM, 0, 0, 0);
        np_set_led(PEOPLE_GREEN_LED_NUM, 0, 200, 0);
    } 
    else if(people_or_car == CAR)
    {
        np_set_led(CAR_RED_LED_NUM, 0, 0, 0);
        np_set_led(CAR_GREEN_LED_NUM, 0, 200, 0);
    }
}

void led_red_on(uint8_t people_or_car){
    
    if(people_or_car == PEOPLE)
    {
        np_set_led(PEOPLE_YELLOW_LED_NUM, 0, 0, 0);
        np_set_led(PEOPLE_RED_LED_NUM, 200, 0, 0);
    } 
    else if(people_or_car == CAR)
    {
        np_set_led(CAR_YELLOW_LED_NUM, 0, 0, 0);
        np_set_led(CAR_RED_LED_NUM, 200, 0, 0);
    }
}

void led_yellow_on(uint8_t people_or_car){
    if(people_or_car == PEOPLE)
    {
        np_set_led(PEOPLE_GREEN_LED_NUM, 0, 0, 0);
        np_set_led(PEOPLE_YELLOW_LED_NUM, 200, 200, 0);
    } 
    else if(people_or_car == CAR)
    {
        np_set_led(CAR_GREEN_LED_NUM, 0, 0, 0);
        np_set_led(CAR_YELLOW_LED_NUM, 200, 200, 0);
    }
}