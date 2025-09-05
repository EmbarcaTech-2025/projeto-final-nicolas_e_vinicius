#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "pico/cyw43_arch.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "traffic_lights_task.h"
#include "neopixel.h"
#include "traffic_light_control.h"
#include "display_task.h"
#include "udp_receive.h"

#define UDP_PORT 4444

#define AP_IP "192.168.4.1"

const char WIFI_SSID[] = "RP_AP";
const char WIFI_PASSWORD[] = "Smart_Crossing";

void sta_task(void *params)
{

    vTaskDelay(pdMS_TO_TICKS(3000));
    
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
    }
    else
    {
        printf("Wi-Fi init successfully\n");
    }

    cyw43_arch_enable_sta_mode();
    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("failed to connect\n");
    } 
    else
    {
        printf("successfully connected\n");
    }

    struct udp_pcb *udppcb;
    udppcb = udp_new();
    udp_bind(udppcb, IP_ADDR_ANY, UDP_PORT); 
    udp_recv(udppcb, udp_recv_function, NULL);
    
    // struct udp_pcb *pcb = udp_new();

    // ip_addr_t ap_addr;
    // ip4addr_aton(AP_IP, &ap_addr);
    // udp_connect(pcb, &ap_addr, UDP_PORT);

    // const char *message = "Hello from Station Pico!";

    // struct pbuf *p = pbuf_alloc(PBUF_TRANSPORT, strlen(message), PBUF_RAM);

    // pbuf_take(p, message, strlen(message));
    // udp_send(pcb, p);

    while (true) {
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}