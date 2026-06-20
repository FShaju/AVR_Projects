/*
 * Push_but_Swt.c
 *
 * Created: 2026-06-07 3:35:36 PM
 * Author : fedbi
 */ 

#define F_CPU 16000000UL      // Ardiuno frequency
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	/*LED setting*/
	DDRD |= (1<< DDD5);   // setting PORTD5 output
	DDRD |= (1<< DDD4);   // setting PORTD4 output
	/*switch setting*/
	DDRB &= ~(1<< DDB4);   // setting PORTB4 input
	PORTB |= (1<<PORTB4);   //enable internal pull up
	
	uint8_t status = 0;
	
	while (1)
	{
		
		if(!(PINB & (1<< PINB4)))
		{
			_delay_ms(50);           //debounce
			
			if(!(PINB & (1<< PINB4)))  //prevent false triggering
			{
				if (status ==0)
				{
					PORTD |=(1<<PORTD5); // Red led ON
					PORTD &= ~(1<<PORTD4); // Green led OFF
					status =1;
				}
				
				else
				{
					PORTD &= ~(1<<PORTD5); // Green led OFF
					PORTD |=(1<<PORTD4); // Red led ON
					status =0;
				}
				
				while (!(PINB & (1<< PINB4)));  // until press released
			}				
		}
		
	}
	return 0;
}