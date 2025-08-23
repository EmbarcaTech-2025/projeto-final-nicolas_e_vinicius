#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "FreeRTOS.h"
#include "task.h"
#include "vl53l0x_wrapper.h"
#include "ssd1306.h"
#include "display_task.h"
#include "task_handles.h"

ssd1306_t disp;

void write_in_display(uint32_t x, uint32_t y, uint32_t scale, const char *s)
{
    ssd1306_draw_string(&disp, x, y, scale, s);
    xTaskNotifyGive(handle_display_task);
}

void draw_line_in_display(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
    ssd1306_draw_line(&disp, x1, y1, x2, y2);
    xTaskNotifyGive(handle_display_task);
}

void draw_empty_square_in_display(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
    ssd1306_draw_empty_square(&disp, x, y, width, height);
    xTaskNotifyGive(handle_display_task);
}

void clear_display()
{
    ssd1306_clear(&disp);
}

void display_task(void *params)
{
    i2c_init(I2C_PORT, 1000*1000);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);
    ssd1306_show(&disp);
    vTaskDelay(pdMS_TO_TICKS(20));
    
    while(1)
    {
        ssd1306_show(&disp);
        ulTaskNotifyTake(pdTRUE, MAX_TIME_UPDATE_DISPLAY);
    }

}