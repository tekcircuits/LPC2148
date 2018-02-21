#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <led.h>

void Config_LED_Pin(void)
{
	PINSEL0.P0_10 = P0_10_GPIO;//GPIO function on P0.10
	IO0DIR |=(1<<BIT10);//Set direction to o/p pin                             
}
 
void Set_LED(led_option_t led_option)
{
	static bool_t toggle=0;
	switch(led_option)
	{
		case	LED_OFF:	IO0CLR=(1<<BIT10);	
							break;
		
		case	LED_ON:  	IO0SET=(1<<BIT10);  	
							break;
			
		case	LED_FLASH:  if(toggle)
							{
								IO0SET=(1<<BIT10); 
							}
							else
							{
								IO0CLR=(1<<BIT10);
							}
							toggle=~(toggle);
							break;
			
	}
}
