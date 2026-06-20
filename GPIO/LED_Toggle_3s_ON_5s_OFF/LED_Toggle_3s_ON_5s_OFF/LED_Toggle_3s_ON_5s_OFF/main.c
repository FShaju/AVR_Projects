/*
 * LED_Toggle_3s_ON_5s_OFF.c
 *
 * Created: 2026-06-07 1:55:02 PM
 * Author : fedbi
 */ 

#define F_CPU 16000000UL      // Ardiuno frequency
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = (1<< DDD5);   // setting PORTD5 output
	
    while (1) 
    {
		PORTD |=(1<<PORTD5);   // LED ON;
		_delay_ms(3000);   //delay 3sec
		
		PORTD &= ~(1<<PORTD5);   //LED OFF;	
		_delay_ms(5000);   //delay 5sec
    }
	return 0;
}

