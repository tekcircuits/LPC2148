#include <global.h>
#include <lpc2148.h>
#include <pll0.h>

void Init_PLL0(void)
{
	/* Set Multiplier and Divider of PLL0 to give 60MHz */
	PLL0CFG  = 0x24;

	/* Enable PLL0 */
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	PLL0CON  = 0x01;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	/* Update PLL Registers with Feed Sequence */
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	// Check the Lock Bit
	while(Is_Bit_Clr(PLL0STAT,BIT10));

	PLL0CON  = 0x03;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	MAMCR    = 0x02; 
	MAMTIM   = 0x04; 
	VPBDIV   = 0x01;
}

