/*
 * PWM_Servo.h
 *
 * Created: 2026-06-13 1:44:36 PM
 *  Author: fedbi
 */ 


#ifndef PWM_SERVO_H_
#define PWM_SERVO_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

void PWM_Servo_init(void);
void PWM_Servo_control(uint16_t Angle);





#endif /* PWM_SERVO_H_ */