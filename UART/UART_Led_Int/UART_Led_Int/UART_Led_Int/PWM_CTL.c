/*
 * PWM_CTL.c
 *
 * Created: 2026-06-16 6:00:30 AM
 *  Author: fedbi
 */ 

#include "PWM_CTL.h"

/*
ISR (INT0_vect)
{
	flag=1;
}*/
void PWM_init(void)
{
	DDRD |= (1<<DDD6);    //PWM Output
	
	TCCR0A = 0;
	TCCR0B = 0;
	TCCR0A |= ((1<<WGM00)|(1<<WGM01)|(1<<COM0A1));  //Fast PWM mode and non -inverting
	TCCR0A &= ~(1<<COM0A0);
	TCCR0B |= ((1<<CS00)|(1<<CS01));   // Prescalr 64, 976 HZ

	TCNT0 = 0;
	OCR0A = 0;
}

	/* Interrupt*

	EIMSK |= (1<<INT0);  //enable external interrupt
	MCUCR |= (1<<ISC01);   //falling edge
	MCUCR &= ~(1<<ISC00);
	sei();*/
	
	/*
	while (1)
	{
		if (flag)
		{
			_delay_ms(20);
			OCR0A = Ctrl[incr++];
			if (incr >= 5) incr=0;
			flag=0;
			while (!(PIND &(1<<PORTD2)));
		}
	}
}*/
