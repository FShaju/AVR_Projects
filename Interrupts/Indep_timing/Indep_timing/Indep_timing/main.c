/*
 * Indep_timing.c
 *
 * Created: 2026-06-10 5:49:56 AM
 * Author : fedbi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t ms =0;

ISR (TIMER1_COMPA_vect)
{
	PORTB ^= 1<<PORTB1;  //status LED
}

ISR (TIMER2_COMPA_vect)
{
	ms++;
}

int main(void)
{
    /*LED*/
	DDRB |= ((1<<DDB1)|(1<<DDB2));  //LED blink
	
	
	/* Timer 2*/
	
	TCCR2A = 0;
	TCCR2B = 0;
	TCCR2A |= (1<<WGM21);   // CTC mode
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); //prescalr 1024
	
	TCNT2  = 0;
	OCR2A = 249;
	
	
	
	/*Timer1 */
	TCCR1A = 0;
	TCCR1B = ((1<<CS12)|(1<<CS10)|(1<<WGM12));     // Prescaler  1024, CTC mode
	OCR1A = 31249;
	
	/* Interrupt */
	TIMSK1 |= (1<<OCIE1A);                 //enable Timers 1
	TIMSK2 |= (1<<OCIE2A);                 //enable Timers 2
	sei ();                               // Global interrupt enable
	
    while (1) 
    {
		if (ms >= 32)
		{
			ms -=32;   // to keep left over time
			PORTB ^= 1<<PORTB2;  //heartbeat LED
		}
    }
}

