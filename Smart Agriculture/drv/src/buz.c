#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <buz.h>


void Init_Buz_IO(void)
{
	PINSEL0.P0_10= P0_10_GPIO;
	Set_Bit(IO1DIR,BIT10);
}
 
void Set_Buz(buz_option_t buz_option)
{
	switch(buz_option)
	{
		static bool_t flash=0;
		case	BUZ_OFF:	Set_Bit(IO1CLR,BIT10);  	
							break;
		
		case	BUZ_ON:  	Set_Bit(IO1SET,BIT10);  	
							break;
		
		case	BUZ_FLASH:  if(flash)
							{
								IO0SET=(1<<BIT10); 
							}
							else
							{
								IO0CLR=(1<<BIT10);
							}
							flash=~(flash);
							break;
	}
}
