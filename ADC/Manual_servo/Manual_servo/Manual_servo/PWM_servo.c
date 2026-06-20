/*
 * PWM_servo.c
 *
 * Created: 2026-06-13 1:44:54 PM
 *  Author: fedbi
 */ 
#include "PWM_Servo.h"

volatile uint8_t speed=0;

void PWM_Servo_init()
{
	
	DDRB |= (1<<DDB1);    //PWM Output PORTB1
	
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1A |= (1<<WGM11);  //PWM, phase correct mode
	TCCR1A |= (1<<COM1A1);    //OC1A output
	TCCR1B |= ((1<<WGM13)|(1<<CS11));   // Prescalr 8
	
	ICR1 = 20000;

	OCR1A=0;
}

void PWM_Servo_control(uint16_t angle)
{
	OCR1A =angle;
}

