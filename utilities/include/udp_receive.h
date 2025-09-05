#ifndef UDP_RECEIVE_H
#define UDP_RECEIVE_H

void udp_recv_function(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);

#endif