/***********************************************************************/
/*  This file is part of the MICROBIT ARM development tools            */
/*  Copyright MICROBIT Embedded Solutions 2011-2012                    */
/***********************************************************************/
/*                                                                     */
/*  PCONP.H:  Common Header									  				     */
/*                                                                     */
/*  V1.0: Initial Version                                              */
/*                                                                     */
/***********************************************************************/

#ifndef _PCONP_H
#define _PCONP_H

/*    
	******* POWER CONTROL OF PERIPHERALS (PCONP) *******
            ------------------------------------   
	LPC2148 Peripherals can be enabled or disabled via PCONP 32-bit Register.
	
	Each Peripheral is assigned one bit of a 32-bit value.
	
	If the appropriate control bit it set to 1 then the device will be enabled. 
	If the bit is set to 0, the device will be disabled. 

	Bit definitions of PCONP 32-bit Register
	----------------------------------------
	Bit 	Description 	Value at Reset
	----------------------------------------
	0 	 	Reserved 			NA
	1 	 	Timer0 				1
	2 	 	Timer1 				1
	3 	 	UART0 				1
	4 	 	UART1 				1
	5 	 	PWM0 				1
	7 	 	I²C0 				1
	8 	 	SPI0 				1
	9 	 	RTC		 			1
	10 		SPI1 				1
	12 		ADC0 				1
	19 		1²C1 				1
	20 		ADC1 				1
	31 		USB					0


   All of the peripherals on the LPC2148 except USB are enabled by default.
	That means you're probably consuming more electrical current than you need to be. 
	
	It's generally a good practice to disable all peripherals with a few lines of code
 	when the microcontroller is first started, and only enable the ones you need as you need them.

	
*/

/*  LPC2148 Peripheral Power Control Macroes */

#define Power_Off_Peripherals()	PCONP = 0x00000000

#define Power_On_Peripherals()	PCONP = 0xFFFFFFFF

#define Power_On_Timer0()	Set_Bit(PCONP,BIT1)
#define Power_Off_Timer0()	Clr_Bit(PCONP,BIT1)

#define Power_On_Timer1()	Set_Bit(PCONP,BIT2)
#define Power_Off_Timer1()	Clr_Bit(PCONP,BIT2)

#define Power_On_UART0()	Set_Bit(PCONP,BIT3)
#define Power_Off_UART0()	Clr_Bit(PCONP,BIT3)

#define Power_On_UART1()	Set_Bit(PCONP,BIT4)
#define Power_Off_UART1()	Clr_Bit(PCONP,BIT4)

#define Power_On_PWM()		Set_Bit(PCONP,BIT5)
#define Power_Off_PWM()		Clr_Bit(PCONP,BIT5)

#define Power_On_I2C0()		Set_Bit(PCONP,BIT7)
#define Power_Off_I2C0()	Clr_Bit(PCONP,BIT7)

#define Power_On_SPI0()		Set_Bit(PCONP,BIT8)
#define Power_Off_SPI0()	Clr_Bit(PCONP,BIT8)

#define Power_On_RTC()		Set_Bit(PCONP,BIT9)
#define Power_Off_RTC()		Clr_Bit(PCONP,BIT9)

#define Power_On_SPI1()		Set_Bit(PCONP,BIT10)
#define Power_Off_SPI1()	Clr_Bit(PCONP,BIT10)

#define Power_On_ADC0()		Set_Bit(PCONP,BIT12)
#define Power_Off_ADC0()	Clr_Bit(PCONP,BIT12)

#define Power_On_I2C1()		Set_Bit(PCONP,BIT19)
#define Power_Off_I2C1()	Clr_Bit(PCONP,BIT19)

#define Power_On_ADC1()		Set_Bit(PCONP,BIT20)
#define Power_Off_ADC1()	Clr_Bit(PCONP,BIT20)

#define Power_On_USB()		Set_Bit(PCONP,BIT31)
#define Power_Off_USB()		Clr_Bit(PCONP,BIT31)

#endif

