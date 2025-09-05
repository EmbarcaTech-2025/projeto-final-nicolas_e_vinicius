#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "udp_receive.h"

void udp_recv_function(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port) {
    if (p != NULL) {
        // Copy the received data into a temporary buffer
        char buffer[p->tot_len + 1];
        pbuf_copy_partial(p, buffer, p->tot_len, 0);
        buffer[p->tot_len] = '\0'; // Null-terminate the string

        // Print the message and the sender's info
        printf("Received packet from %s:%d: '%s'\n", ip4addr_ntoa(addr), port, buffer);

        // IMPORTANT: You must free the pbuf packet buffer after you're done with it
        pbuf_free(p);
    }
}