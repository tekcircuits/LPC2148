/*  Motor Driver */
#include<lpc2148.h>
#include<l293d.h>
#include<pcb.h>
#include<global.h>

void Init_L293D(void)
{
	PINSEL2.P1_36_26 = P1_36_26_GPIO;
	IO1DIR |= L293D_MASK;
	IO1CLR |= L293D_MASK;
	
}

void L293D_Motor_Control(motor_dir_t motor_option)
{
	switch(motor_option)
	{
		case FORWARD:		IO1CLR |= L293D_MASK;	IO1SET |= L293D_FORWARD();	break;
		case BACKWARD:	IO1CLR |= L293D_MASK;	IO1SET |= L293D_BACK();	 		break;
		case LEFT_TURN:	IO1CLR |= L293D_MASK;	IO1SET |= L293D_LEFT();			break;
		case RIGHT_TURN:IO1CLR |= L293D_MASK;	IO1SET |= L293D_RIGHT(); 		break;
		
	}
}



