/*
 * UART_Led_Int.c
 *
 * Created: 2026-06-16 5:55:44 AM
 * Author : fedbi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "UART_pol.h"
#include "PWM_CTL.h"


int main(void)
{
    DDRD |= (1<<DDD6);   //PORTB0 as output
	PORTD &=~(1<<PORTD6); // LED turn OFF
	
	char compare[100];
	uint8_t i =0;
	
	uart_init();
	PWM_init();
	uart_sendString(" Hi");

    while (1) 
    {

		char ctrl_cmd =  uart_rx();
		
		if (ctrl_cmd == '\r' || ctrl_cmd =='\n')
		{
			compare[i]='\0';
			i=0;
			if (strcmp(compare,"ON") == 0 || strcmp(compare,"on")==0)
			{
				OCR0A = 255; // LED turn ON
			}
			else if (strcmp(compare,"OFF") == 0 || strcmp(compare,"off")==0)
			{
				OCR0A =0; // LED turn OFF
			}	
			else 
			{
				uint8_t value_100 = atoi (compare);
				uint8_t value_255 = ((uint32_t) value_100 * 255) / 100;
				OCR0A = value_255;
			}
			
			i = 0;
			compare[0] = '\0';
		}
		
		else 
		{
			compare[i++] = ctrl_cmd;
		}
    }
}

