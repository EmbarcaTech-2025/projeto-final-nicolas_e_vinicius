#ifndef LED_STATE_H
#define LED_STATE_H

#define PEOPLE_GREEN_LED_NUM        10
#define PEOPLE_YELLOW_LED_NUM       9
#define PEOPLE_RED_LED_NUM          0

#define CAR_GREEN_LED_NUM           14
#define CAR_YELLOW_LED_NUM          5
#define CAR_RED_LED_NUM             4

enum TrafficState
{
    PEOPLE_GREEN = 0,
    PEOPLE_YELLOW,
    PEOPLE_RED,
    CAR_GREEN,
    CAR_YELLOW,
    CAR_RED
};

enum Entity
{
    PEOPLE = 0,
    CAR
};

void led_green_on(uint8_t people_or_car);

void led_red_on(uint8_t people_or_car);

void led_yellow_on(uint8_t people_or_car);


#endif