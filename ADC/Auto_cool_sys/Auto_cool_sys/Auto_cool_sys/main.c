/*
 * Auto_cool_sys.c
 *
 * Created: 2026-06-13 6:31:49 AM
 * Author : fedbi
 */ 

#include "ACS_PWM.h"
#include "ADC.h"
#include <util/delay.h>

int main(void)
{
   ACS_PWM_init();
   adc_init();
   
   DDRD |=(1<<DDD2);
   uint8_t pwm=0;
   
	
    while (1) 
    {
		uint16_t adc_value = read_adc(0);
		
		if ( adc_value>820) pwm=255;
		else if ( adc_value>615) pwm=200;
		else if ( adc_value>410) pwm=130;
		else if ( adc_value>0) pwm=0;
		
		ACS_Motor_control(pwm);
		
	}
		
	return 0;
}

