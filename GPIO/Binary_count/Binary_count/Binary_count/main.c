/*
 * Binary_count.c
 *
 * Created: 2026-06-07 7:33:26 PM
 * Author : fedbi
 */ 
#define F_CPU 16000000UL      // Ardiuno frequency
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/*LED setting*/
	DDRB |= 0x0F;   // setting PORTB 0-3 only as output
	PORTB = 0x00;   // setting all led off state
	
	DDRD &=(~(1<<DDD2));  //setting portD2 input
	PORTD |=(1<<PORTD2); //internal pull up enable
	uint8_t bin=0x00;
	
	while (1)
	{
		if (!(PIND & (1<<PORTD2)))
		{
			_delay_ms(50);
			
			if (!(PIND & (1<<PORTD2)))
			{
				PORTB = (PORTB & 0xF0)|(bin & 0x0F);
				bin++;
			}
			while (!(PIND & (1 << PIND2)));
		}
	}
	return 0;
}


