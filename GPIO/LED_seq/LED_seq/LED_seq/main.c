/*
 * LED_seq.c
 *
 * Created: 2026-06-07 6:05:45 PM
 * Author : fedbi
 */ 

#define F_CPU 16000000UL      // Ardiuno frequency
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	/*LED setting*/
	DDRB |= 0x3F;   // setting PORTB0-5 only as output
	DDRD |= ((1<<DDD6)|(1<<DDD7));   // setting PORTD6,7 as output 
	PORTB &= ~(0x3F);   // setting all led off state from PB0-5
	PORTD &= ~((1<<PORTD6)|(1<<PORTD7));   // setting D6,D7
		
	while (1)
	{
		for (uint8_t i=0; i< 8;i++ )
		{
			if (i<6)
			{
				PORTD &= ~((1<<PORTD6)|(1<<PORTD7));
				PORTB =(1<<i);   //setting 1,2,4,8,16,32
				_delay_ms(100);
			}
			else
			{
				PORTB &= ~(0x3F);    // setting all led off state from PB0-5
				PORTD =(1<<i);   //64,128 using portD6,D7, AS portb6,B7 not available
				_delay_ms(100);
			}
		}
	}
	return 0;
}
