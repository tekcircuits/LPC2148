//***************************************************************************
//** SAA1064 Library
//** Created by Murali Challa
//** Version: 1.0
//** Description:
//** Device Driver Functions for I2C SAA1064, 4-digit 7-Segment Display.
//** 
//***************************************************************************/

#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <pll0.h>
#include <delay.h>
#include <i2c.h>
#include <i2c.h>


#define SSD_SLAVE_ADDR	0x70

#define SSD_CMD_NEXT			0

#define SSD_INTENSITY_OFF					0x00	
#define SSD_INTENSITY_ULTRA_LOW		0x17	
#define SSD_INTENSITY_LOW			    0x27
#define SSD_INTENSITY_MID			    0x37
#define SSD_INTENSITY_HIGH			  0x67
#define SSD_INTENSITY_ULTRA_HIGH	0x77

#define SSD_DIGIT_ONE			1
#define SSD_DIGIT_TWO			2
#define SSD_DIGIT_THREE		3
#define SSD_DIGIT_FOUR		4


u8_t ssd_digit_data[10]	=	
												{
													0x3F, // 0
													0x06, // 1
													0x5B, // 2
													0x4F, // 3
													0x66, // 4
													0x6D, // 5
													0x7D, // 6
													0x07, // 7
													0x7F, // 8
													0x6F, // 9
											
											};


__inline static void Config_SSD(void)
{
	Set_I2C_Start(SSD_SLAVE_ADDR);					

	Set_I2C_Write_Byte(SSD_CMD_NEXT);
 	Set_I2C_Write_Byte(SSD_INTENSITY_ULTRA_LOW);
	
	Set_I2C_Stop();
}

											
void Set_SSD_All(void) // Test Function
{
	Set_I2C_Start(SSD_SLAVE_ADDR);				
		
 	Set_I2C_Write_Byte(SSD_DIGIT_ONE);

	Set_I2C_Write_Byte(0xff);
	Set_I2C_Write_Byte(0xff);
	Set_I2C_Write_Byte(0xff);
	Set_I2C_Write_Byte(0xff);

	Set_I2C_Stop();
}

void Clr_SSD_All(void)
{
	Set_I2C_Start(SSD_SLAVE_ADDR);				
		
 	Set_I2C_Write_Byte(SSD_DIGIT_ONE);

	Set_I2C_Write_Byte(0);
	Set_I2C_Write_Byte(0);
	Set_I2C_Write_Byte(0);
	Set_I2C_Write_Byte(0);

	Set_I2C_Stop();
}

void Update_SSD_Digit_Four(u8_t num) // 0 - 9
{
	Set_I2C_Start(SSD_SLAVE_ADDR);				
	
 	Set_I2C_Write_Byte(SSD_DIGIT_FOUR);
	Set_I2C_Write_Byte(ssd_digit_data[num]);		

	Set_I2C_Stop();
}

void Update_SSD_Digit_Three(u8_t num) // 0 - 9
{
	Set_I2C_Start(SSD_SLAVE_ADDR);				
		
	Set_I2C_Write_Byte(SSD_DIGIT_THREE);
	Set_I2C_Write_Byte(ssd_digit_data[num]);		

	Set_I2C_Stop();
}

void Update_SSD_Digit_Two(u8_t num) // 0 - 9
{
	Set_I2C_Start(SSD_SLAVE_ADDR);				
		
 	Set_I2C_Write_Byte(SSD_DIGIT_TWO);
	Set_I2C_Write_Byte(ssd_digit_data[num]);		

	Set_I2C_Stop();
}

void Update_SSD_Digit_One(u8_t num) // 0 - 9
{
	Set_I2C_Start(SSD_SLAVE_ADDR);				
		
 	Set_I2C_Write_Byte(SSD_DIGIT_ONE);
	Set_I2C_Write_Byte(ssd_digit_data[num]);		

	Set_I2C_Stop();
}

void Init_SSD(void)
{
	Init_I2C();

	Config_SSD();
}
