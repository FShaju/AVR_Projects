/*
 * UART_pol.c
 *
 * Created: 2026-05-17 12:16:15 PM
 *  Author: fedbi
 */ 
#include "UART_pol.h"
#include <avr/io.h>

char rx_data[20];
char tx_data[20];

void uart_init (void)
{
	UBRR0L = 103;   //setting Baud Rate
	UCSR0B |= ((1<<TXEN0)|(1<<RXEN0)); // enable TX and RX on UCSR0
	UCSR0B &= ~(1<<UCSZ02);
	UCSR0C |= ((1<<UCSZ01)|(1<<UCSZ00)); // Setting 8 bit, stop bit and parity mode
	UCSR0C &= ~((1<<UPM01)|(1<<UPM00));
	UCSR0C &= ~(1<<USBS0);
}

void uart_tx (char c)
{
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}

char uart_rx (void)
{
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void uart_sendString (char *tx_data) // pointer to char (start i\of string)
{
	while (*tx_data != '\0')
	{
	 uart_tx(*tx_data);
	 tx_data++;
	}
}

void uart_receiveString (char *rx_data) // receving string
{	
	uint8_t i =0;
	while (1)
	{
		char c = uart_rx();
		
		if (c== '\r'||c=='\n')
		{
			rx_data[i] = '\0';
			break;
		}
		
		rx_data[i++] = c;
	}
}

