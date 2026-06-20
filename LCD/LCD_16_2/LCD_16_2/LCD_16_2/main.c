/*
 * LCD_PRM.c
 *
 * Created: 2026-04-23 6:40:25 PM
 * Author : fedbi
 */ 

//#define F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
#include "LCD_PRM.h"

volatile uint32_t ms=0;
volatile uint32_t count=0;
volatile uint8_t button_state=0;
volatile uint32_t Press_start=0;
char value[100];

ISR (TIMER2_COMPA_vect)
{
	ms++;
}

/*ISR(INT0_vect)
{
	Button_press++;
}*/


int main(void)
{
    lcd_init();
    lcd_set_cursor(0, 0);           //lcd_set_cursor(1, 0);
    lcd_print("*** Welcome****");         //lcd_print("It works! ");
	
	lcd_set_cursor(1, 0);           //lcd_set_cursor(1, 0);
	lcd_print("*9-digit Counter *");
	
	DDRB &=~(1<<DDB2);     //PORTBO as input
	PORTB |=(1<<PORTB2);  //internal pull up enable
	
	
	/* Timer 2*/
	
	TCCR2A = 0;
	TCCR2B = 0;
	TCCR2A |= (1<<WGM21);   // CTC mode
	TCCR2B |= (1 << CS22);/* | (1 << CS21) | (1 << CS20); //prescalr 1024*/
	
	TCNT2  = 0;
	OCR2A = 249;
	
	TIMSK2 |= (1 << OCIE2A);
	sei();
	
	count = 0;
	itoa(count, value, 10);

	lcd_clear();
	sprintf(value,"%09lu",count);
	lcd_set_cursor(0,0);
	lcd_print("Number Count");
	lcd_set_cursor(1,0);
	lcd_print(value);

    while (1) 
    {
		
		
		if (!(PINB & (1<<PINB2)))
		{
			if (button_state==0)
			{
				button_state=1;
				Press_start=ms;
			}
		}
		else
		{
			if (button_state ==1)
			{
				uint32_t press_time = ms-Press_start;
				button_state=0;
				Press_start = 0;
				
				if (press_time < 2000)
					{
						count++;
					}
				else
					{
						count=0;
					}
			   
		     sprintf(value,"%09lu",count);
		     lcd_clear();
		     lcd_set_cursor(0, 0);
		     lcd_print("Number Count");
		     lcd_set_cursor(1, 0);
		     lcd_print(value);
			}
		}
    }
}

