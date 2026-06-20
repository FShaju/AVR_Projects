/*
 * ACS_PWM.h
 *
 * Created: 2026-06-13 6:44:17 AM
 *  Author: fedbi
 */ 


#ifndef ACS_PWM_H_
#define ACS_PWM_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

void ACS_PWM_init(void);
void ACS_Motor_control(uint8_t speed);




#endif /* ACS_PWM_H_ */

