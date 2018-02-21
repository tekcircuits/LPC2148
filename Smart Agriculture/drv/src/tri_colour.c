#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <tri_colour.h>

void Init_TRI_LED_IO(void)
{
	PINSEL0.P0_8= P0_8_GPIO;
	PINSEL0.P0_9= P0_9_GPIO;
	
	Set_Bit(IO0DIR,BIT8);
	Set_Bit(IO0DIR,BIT9);
	
}

void Set_Tri_LED(t_led_option_t led_option)
{
	switch(led_option)
	{
		case GREEN_LED: Set_Bit(IO0SET,BIT8);
				            Set_Bit(IO0CLR,BIT9);
				            break;

		case RED_LED  : Set_Bit(IO0SET,BIT9);
			              Set_Bit(IO0CLR,BIT8);
				            break;

		case AMBER_LED: Set_Bit(IO0CLR,BIT8);
										Set_Bit(IO0CLR,BIT9);
				            break;
		case TRI_LED_OFF: Set_Bit(IO0SET,BIT8);
										Set_Bit(IO0SET,BIT9);
				            break;
										 
		
		
										 
		
	}
}
