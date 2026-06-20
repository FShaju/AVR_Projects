/*
 * Traffic_Light.c
 *
 * Created: 2026-06-08 6:10:51 AM
 * Author : fedbi
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

typedef enum {
	Green_LED,
	Yellow_LED,
	Red_LED
	}Light_t;
	
typedef enum {
		normal_mode,
		interrupt_mode
	}Modes;

volatile Modes stat = normal_mode;
volatile Light_t order = Green_LED;
volatile uint16_t ms=0;

ISR(TIMER0_COMPA_vect)
{
	ms++;
}

ISR(INT0_vect)
{
	stat =interrupt_mode;
	ms=0;
}


int main(void)
{
	DDRD &= ~(1<<DDD2);   //Setting portD2 as input
	PORTD |= (1<<PORTD2);  //enabling internal pull-up
	
	DDRB |= ((1<<DDB0)|(1<<DDB1)|(1<<DDB2));  //setting portB0-2 as output
	PORTB &= ~(0x07);   // clears PB0-2
	TCNT0 =0;
	TCCR0A =0x02;  //setting CTC mode WGM01=1, WGM00=0
	TCCR0B =0x03;  //prescaler 64
	OCR0A =249;
	
	/* intterupts */
	TIMSK0 |= (1 << OCIE0A);  //timer intterupt
	EIMSK |= (1 << INT0);    //external interrupts
	EICRA &= ~((1<<ISC01) | (1<<ISC00));           //external interrupts low triggering
	sei();
	
	
	
    PORTB |=(1<<PORTB0);  //turn green LED ON
	
    while (1) 
    {
		if (stat == normal_mode)
		{
			switch (order)
			{
				case Green_LED:
				if (ms >= 10000)
				{
					PORTB &= ~(0x07);   // clears PB0-2
					PORTB |=(1<<PORTB1);  //turn yellow LED ON
					order = Yellow_LED;
					ms=0;
				}
				break;
				case Yellow_LED:
				if (ms >= 3000)
				{
					PORTB &= ~(0x07);   // clears PB0-2
					PORTB |=(1<<PORTB2);  //turn red LED ON
					order = Red_LED;
					ms=0;
				}
				break;
				
				case Red_LED:
				if (ms >= 10000)
				{
					PORTB &= ~(0x07);   // clears PB0-2
					PORTB |=(1<<PORTB0);  //turn Green LED ON
					order = Green_LED;
					ms=0;
				}
			    break;
			}
		}
		if (stat ==interrupt_mode)
		{
			PORTB &= ~(0x07);   // clears PB0-2
			PORTB |=(1<<PORTB0);  //turn Green LED ON
			if (ms >10000)
			{
				stat =normal_mode;
				order = Green_LED;
				ms=0;
			}	
		}	
    }
}

