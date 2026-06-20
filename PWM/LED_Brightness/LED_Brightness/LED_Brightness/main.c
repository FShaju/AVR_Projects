/*
 * LED_Brightness.c
 *
 * Created: 2026-06-11 6:29:34 AM
 * Author : fedbi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t Ctrl[5] = {0,64,128,191,255};
volatile uint8_t incr =0;
volatile uint8_t flag =0;

ISR (INT0_vect)
{
 flag=1;
}

int main(void)
{
    DDRD |= (1<<DDD6);    //PWM Output
	
	DDRD &= ~(1<<DDD2);  // input 
	PORTD |= (1<<PORTD2);  //pull up 
	
	TCCR0A = 0;
	TCCR0B = 0;
	TCCR0A |= ((1<<WGM00)|(1<<WGM01)|(1<<COM0A1));  //Fast PWM mode and non -inverting
	TCCR0A &= ~(1<<COM0A0);
	TCCR0B |= ((1<<CS00)|(1<<CS01));   // Prescalr 64, 976 HZ

	TCNT0 = 0;
	OCR0A = 0;

	/* Interrupt*/

	EIMSK |= (1<<INT0);  //enable external interrupt
	MCUCR |= (1<<ISC01);   //falling edge
	MCUCR &= ~(1<<ISC00);
	sei();
	
	
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
}

