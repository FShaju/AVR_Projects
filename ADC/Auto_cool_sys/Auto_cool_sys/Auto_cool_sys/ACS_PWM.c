/*
 * ACS_PWM.c
 *
 * Created: 2026-06-13 6:44:41 AM
 *  Author: fedbi
 */ 

#include "ACS_PWM.h"

//volatile uint8_t Ctrl[5] = {0,64,128,191,255};
volatile uint8_t speed=0;

void ACS_PWM_init()
{
	
    DDRD |= (1<<DDD6);    //PWM Output
	DDRB |= (1<<DDB0);    // IN2 as output
	DDRB |= (1<<DDB1);    //IN1 as low output
	
	PORTB |=(1<<PORTB0);   // IN2 is high
	PORTB &= ~(1<<PORTB1);  //IN1 is low 
	
	
	TCCR0A = 0;
	TCCR0B = 0;
	TCCR0A |= ((1<<WGM00)|(1<<WGM01)|(1<<COM0A1));  //Fast PWM mode and non -inverting
	TCCR0A &= ~(1<<COM0A0);
	TCCR0B |= ((1<<CS00)|(1<<CS01));   // Prescalr 64, 976 HZ

	TCNT0 = 0;
	OCR0A = 0;
}

 void ACS_Motor_control(uint8_t speed)
{
	OCR0A =speed;
}

