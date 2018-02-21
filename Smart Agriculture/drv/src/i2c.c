//*************************************************
//** Polling I2C-Master Library
//** Created by Murali Challa
//** Version: 1.0
//** Description:
//** This Library provides I2C-Master Functions on LPC2000 Microcontrollers.
//** 
//*************************************************

#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <pconp.h>
#include <i2c0.h>

#define Enable_I2C0()	Set_Bit(I2C0CONSET,BIT6)
#define Disable_I2C0()	Set_Bit(I2C0CONCLR,BIT6)

// Initialize I2C
void Init_I2C(void)
{
 // Set I2C SCL Frequency of 100KHz
 // SCL Frequency = PCLK/(I2C0SCLH + I2C0SCLL) 
	I2C0SCLH = 300;
	I2C0SCLL = 300;
	
//	Power On I2C bus interface
	Power_On_I2C0(); // PCONP

//	Enable I2C bus interface
	Enable_I2C0();
}

// Handle I2C Events with Polling Method
__inline static void Wait_for_I2C_Status(void)
{
	//	clear Status Indication(SI) flag
	Set_Bit(I2C0CONCLR,BIT3);
	
	//	Wait for SI to be set
	while(Is_Bit_Clr(I2C0CONSET,BIT3));		
}

//Send "START" condition
s32_t Set_I2C_Start(u32_t addr)
{
/*	The master transmitter mode may now be entered by setting the STA bit. 
	The I2C logic will now test the I2C-bus and generate a start condition 
	as soon as the bus becomes free. When a START condition is transmitted, 
	the serial interrupt flag (SI) is set, and the status code in the status 
	register (I2STAT) will be 0x08.
*/	
	//	clear STOP Bit & Assert Acknowledgement Bit
	I2C0CONCLR |= (1<<BIT4) | (1<<BIT2);	
	//	set START Bit along with SI Bit
	I2C0CONSET |= (1<<BIT5) | (1<<BIT3)
	Wait_for_I2C_Status();
	
	//	clear START Bit
	Clr_Bit(I2C0CONCLR,BIT5);
	
	//	if bus is busy, indicate the same with a return value of -1
	if (I2C0STAT > 0x10) return(-1);				
	
	//	set address
	I2C0DAT = addr;									
	
	Wait_for_I2C_Status();
	
	return (I2C0STAT != 0x40 && I2C0STAT != 0x18);	
}

//Write on I2C bus
int Set_I2C_Write_Bytes(u8_t *buf, u16_t i2c_Byte_ctr)
{
	while (i2c_Byte_ctr--)
	{
		//	load data into I2DAT-Register
		I2C0DAT = *buf++;						
		
		Wait_for_I2C_Status();
		
		if (I2C0STAT != 0x28) return 1;		
	}
	return 0;
}

//Read from I2C bus
int Get_I2C_Read_Byte(void)
{
  // Assert Acknowledge
  Set_Bit(I2C0CONSET,BIT2)
  Wait_for_I2C_Status();
  if(I2C0STAT!=0x50 && I2C0STAT!=0x40)
  {
	return -1; // Not ok
  }
  else
  {
    return I2C0DAT;
  }
}
//Read last byte from I2C Bus
int Get_I2C_Read_Byte_Last()
{
  // Assert No Acknowledge
  Set_Bit(I2C0CONCLR,BIT2);
  Wait_for_I2C_Status();
  
  if(I2C0STAT!=0x58)
  {
    return -1; // Not ok
  }
  else
  {
    return I2C0DAT;
  }
}

//Send "STOP" condition
void Set_I2C_Stop(void)
{
	//	clear SI flag
	Set_Bit(I2C0CONCLR,BIT3);
	
	// Set STOP flag
	Set_Bit(I2C0CONSET,BIT4);
	
	//	Wait for STOP bit to be clear
	while(Is_Bit_Clr(I2C0CONSET,BIT4));		
	
	//	Re-enable I2C bus interface
	Enable_I2C0();
}
