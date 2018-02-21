#include<global.h>
#include<lpc2148.h>
#include<pconp.h>
#include<pcb.h>
#include<pwm.h>


void Init_PWM_Timer(void)
{
	PINSEL0.P0_8=P0_8_PWM4;
	Power_On_PWM();
	PWMTCR=(1<<BIT1);
	PWMPR=(60-1);
	PWMTC=0;
	PWMMCR=(1<<BIT1);
	PWMMR0=(10000-1);
	PWMPCR=(1<<BIT12);
	PWMTCR=(1<<BIT3)|(1<<BIT0);
}


void set_PWM_width(u32_t pwm_width)
{
	PWMMR4=PWM_width;
	PWMLER=(1<<BIT4);
}