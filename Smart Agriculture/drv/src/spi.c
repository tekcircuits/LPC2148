#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <pconp.h>
#include <spi.h>


#define Wait_SPIO()	while(Is_Bit_Clr(S0SPSR,BIT7))

__inline void Config_SPI0_Pins(void)
{
	PINSEL0.P0_4  = P0_4_SCK0;
	PINSEL0.P0_5  = P0_5_MISO0;
	PINSEL0.P0_6  = P0_6_MOSI0;
	PINSEL0.P0_7  = P0_7_GPIO; // In Master Mode, SSEL pin is a GPIO Pin
	
	/* Direction setting for SPI0 SSEL0 Pin as GPIO Output */
	Set_Bit(IO0DIR,BIT7);  
	
	/* set SSEL to high */
	IO0SET = SPI_SSEL0_BIT;
}


void Init_SPI0( void )
{
	u8_t dummy_data=0; 
	
	Config_SPI0_Pins();
	Power_On_SPI0();

	/* SPI Clock Setting to ~4MHz */
	S0SPCCR = 16; // This should be always an even Number
	
	/* SPI Default Configuration */
	// BitEnable = 0(BIT2)-> 8-bit data Format
	//      CPHA = 0(BIT3) 
	//      CPOL = 0(BIT4)
	//      LSBF = 0(BIT6) -> MSB First
	//			SPIE = 0(BIT7) -> Interrupt Disabled
	//		MSTR = 1(BIT5) -> The SPI operates in Master mode
	S0SPCR = 0x0020;
	
	/* Clear Receive Buffer */
	dummy_data = S0SPDR;
	
	dummy_data = SPI_Transfer_Data(0xff);
}	

/*
* SPI_Transfer_Data , sends one byte , returns received Data byte

1) Load the data byte into SPDR
2) Wait for Transfer Complete
3) Read SPDR to get the SPI Slave response

*/

u8_t SPI_Transfer_Data(u8_t spi_data)
{		
	S0SPDR = spi_data;
	
	/* Wait for Transfer Complete */
	Wait_SPIO();
	
	spi_data = S0SPDR; // Dummy while Master Send
		
	return (spi_data);
}






