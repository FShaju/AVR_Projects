/*
 * Manual_servo.c
 *
 * Created: 2026-06-13 1:43:01 PM
 * Author : fedbi
 */ 

#include "PWM_Servo.h"
#include "ADC.h"
#include <util/delay.h>

int main(void)
{
	PWM_Servo_init();
	adc_init();
	
	uint16_t Angle=0;
	
	while (1)
	{
		uint16_t adc_value = read_adc(0);
		
		if ( adc_value>820) Angle=2500;
		else if ( adc_value>615) Angle=2000;
		else if ( adc_value>410) Angle=1500;
		else if ( adc_value>210) Angle=1000;
		else if ( adc_value>0) Angle=500;
		
		PWM_Servo_control(Angle);
		_delay_ms(1000);
		
	}
	
	return 0;
}

