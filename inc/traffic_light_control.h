#ifndef LED_STATE_H
#define LED_STATE_H

#define PEOPLE_GREEN_LED_NUM                10
#define PEOPLE_YELLOW_LED_NUM               9
#define PEOPLE_RED_LED_NUM                  0

#define CAR_GREEN_LED_NUM                   14
#define CAR_YELLOW_LED_NUM                  5
#define CAR_RED_LED_NUM                     4

#define TIME_GREEN_PEOPLE_DEFAULT           2000
#define TIME_GREEN_CAR_DEFAULT              2000
#define TIME_TO_TURN_GREEN_PEOPLE_DEFAULT   1000
#define TIME_TO_TURN_GREEN_CAR_DEFAULT      1000

#define YELLOW_TIME                         500
#define RED_TIME                            2000

#define IS_PEOPLE(var)              ((var) == PEOPLE)
#define IS_CAR(var)                 ((var) == CAR)

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

void set_time_green(uint8_t people_or_car, uint16_t new_time);

void set_time_to_turn_green(uint8_t people_or_car, uint16_t new_time);

uint8_t get_time_green(uint8_t people_or_car);

uint8_t get_time_to_turn_green(uint8_t people_or_car);

#endif