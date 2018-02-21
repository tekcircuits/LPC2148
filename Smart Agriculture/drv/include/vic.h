/******************************************************************************
 *   vic.h:  Interrupt related Header file for Philips LPC214x Family 
 *   Microprocessors
 *
 *   Copyright(C) 2012, MICROBIT Embedded Solutions
 *   All rights reserved.
 *
 *   History
 *   2012.12.09  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __VIC_H 
#define __VIC_H

/* if nested interrupt is used, NEST_INTERRUPT needs to be set to 1, otherwise 0 */
#define NESTED_INTERRUPT	0

#define I_BIT			0x80
#define F_BIT			0x40

#define SYS32_MODE		0x1F
#define IRQ32_MODE		0x12
#define FIQ32_MODE		0x11
#define	WDT_INT			0
#define SWI_INT			1
#define ARM_CORE0_INT	2
#define	ARM_CORE1_INT	3
#define	TIMER0_INT		4
#define TIMER1_INT		5
#define UART0_INT		6
#define	UART1_INT		7
#define	PWM0_INT		8
#define I2C0_INT		9
#define SPI0_INT		10
#define	SPI1_INT		11
#define	PLL_INT			12
#define RTC_INT			13
#define EINT0_INT		14
#define EINT1_INT		15
#define EINT2_INT		16
#define EINT3_INT		17
#define	ADC0_INT		18
#define I2C1_INT		19
#define BOD_INT			20
#define ADC1_INT		21
#define USB_INT			22

#define IRQ_SLOT_EN		0x20	/* bit 5 in Vector control register */
#define VIC_SIZE		16


#define VECT_ADDR_INDEX	0x100
#define VECT_CNTL_INDEX 0x200

void Init_VIC( void );
bool_t Install_IRQ(u32_t intr_num, void *ISR_addr );
bool_t Uninstall_IRQ(u32_t intr_num );

#endif /* end __VIC_H */

/******************************************************************************
**                            End Of File
******************************************************************************/
