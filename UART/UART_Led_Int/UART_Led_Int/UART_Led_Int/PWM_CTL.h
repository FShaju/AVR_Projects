/*
 * PWM_CTL.h
 *
 * Created: 2026-06-16 6:00:12 AM
 *  Author: fedbi
 */ 


#ifndef PWM_CTL_H_
#define PWM_CTL_H_


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//volatile uint8_t Ctrl[5] = {0,64,128,191,255};
//volatile uint8_t incr =0;
//volatile uint8_t flag =0;

void PWM_init(void);




#endif /* PWM_CTL_H_ */