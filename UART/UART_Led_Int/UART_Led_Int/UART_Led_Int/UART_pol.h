/*
 * UART_pol.h
 *
 * Created: 2026-05-17 12:16:37 PM
 *  Author: fedbi
 */ 


#ifndef UART_POL_H_
#define UART_POL_H_

#define F_CPU 16000000UL
#include <stdint.h>

extern char rx_data[20];
extern char tx_data[20];

void uart_init (void);

void uart_tx ( char c);
char uart_rx (void);

void uart_sendString (char *str);
void uart_sendString (char *buffer);



#endif /* UART_POL_H_ */