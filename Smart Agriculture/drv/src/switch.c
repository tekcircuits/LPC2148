#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <switch.h>


// Define a driver function to read P0.14 Pin status and return TRUE if it is LOW else return FALSE 
 
void Config_Switch(void)
{
	PINSEL0.P0_14 = P0_14_GPIO;
	Clr_Bit(IO0DIR,BIT14); // P0.14 configured as Input
} 

bool_t Get_Switch(void)
 {
	bool_t sw_stat = FALSE;
	
	if(Is_Bit_Clr(IO0PIN,BIT14))
	sw_stat = TRUE;
	
	return sw_stat;
}


