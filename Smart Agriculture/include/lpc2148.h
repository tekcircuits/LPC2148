/***********************************************************************/
/*  This file is part of the MICROBIT ARM development tools            */
/*  Copyright MICROBIT Embedded Solutions 2011-2012                    */
/***********************************************************************/
/*                                                                     */
/*  LPC214X.H:  Header file for Philips LPC2141/42/44/46/48            */
/*                                                                     */
/*  V1.0: Initial Version                                              */
/*                                                                     */
/***********************************************************************/

#ifndef __LPC214x_H
#define __LPC214x_H

/* Vectored Interrupt Controller (VIC) */
#define VICIRQStatus    (*((volatile u32_t *) 0xFFFFF000))
#define VICFIQStatus    (*((volatile u32_t *) 0xFFFFF004))
#define VICRawIntr      (*((volatile u32_t *) 0xFFFFF008))
#define VICIntSelect    (*((volatile u32_t *) 0xFFFFF00C))
#define VICIntEnable    (*((volatile u32_t *) 0xFFFFF010))
#define VICIntEnClr     (*((volatile u32_t *) 0xFFFFF014))
#define VICSoftInt      (*((volatile u32_t *) 0xFFFFF018))
#define VICSoftIntClr   (*((volatile u32_t *) 0xFFFFF01C))
#define VICProtection   (*((volatile u32_t *) 0xFFFFF020))
#define VICVectAddr     (*((volatile u32_t *) 0xFFFFF030))
#define VICDefVectAddr  (*((volatile u32_t *) 0xFFFFF034))
#define VICVectAddr0    (*((volatile u32_t *) 0xFFFFF100))
#define VICVectAddr1    (*((volatile u32_t *) 0xFFFFF104))
#define VICVectAddr2    (*((volatile u32_t *) 0xFFFFF108))
#define VICVectAddr3    (*((volatile u32_t *) 0xFFFFF10C))
#define VICVectAddr4    (*((volatile u32_t *) 0xFFFFF110))
#define VICVectAddr5    (*((volatile u32_t *) 0xFFFFF114))
#define VICVectAddr6    (*((volatile u32_t *) 0xFFFFF118))
#define VICVectAddr7    (*((volatile u32_t *) 0xFFFFF11C))
#define VICVectAddr8    (*((volatile u32_t *) 0xFFFFF120))
#define VICVectAddr9    (*((volatile u32_t *) 0xFFFFF124))
#define VICVectAddr10   (*((volatile u32_t *) 0xFFFFF128))
#define VICVectAddr11   (*((volatile u32_t *) 0xFFFFF12C))
#define VICVectAddr12   (*((volatile u32_t *) 0xFFFFF130))
#define VICVectAddr13   (*((volatile u32_t *) 0xFFFFF134))
#define VICVectAddr14   (*((volatile u32_t *) 0xFFFFF138))
#define VICVectAddr15   (*((volatile u32_t *) 0xFFFFF13C))
#define VICVectCntl0    (*((volatile u32_t *) 0xFFFFF200))
#define VICVectCntl1    (*((volatile u32_t *) 0xFFFFF204))
#define VICVectCntl2    (*((volatile u32_t *) 0xFFFFF208))
#define VICVectCntl3    (*((volatile u32_t *) 0xFFFFF20C))
#define VICVectCntl4    (*((volatile u32_t *) 0xFFFFF210))
#define VICVectCntl5    (*((volatile u32_t *) 0xFFFFF214))
#define VICVectCntl6    (*((volatile u32_t *) 0xFFFFF218))
#define VICVectCntl7    (*((volatile u32_t *) 0xFFFFF21C))
#define VICVectCntl8    (*((volatile u32_t *) 0xFFFFF220))
#define VICVectCntl9    (*((volatile u32_t *) 0xFFFFF224))
#define VICVectCntl10   (*((volatile u32_t *) 0xFFFFF228))
#define VICVectCntl11   (*((volatile u32_t *) 0xFFFFF22C))
#define VICVectCntl12   (*((volatile u32_t *) 0xFFFFF230))
#define VICVectCntl13   (*((volatile u32_t *) 0xFFFFF234))
#define VICVectCntl14   (*((volatile u32_t *) 0xFFFFF238))
#define VICVectCntl15   (*((volatile u32_t *) 0xFFFFF23C))

/* Pin Connect Block */
typedef struct
{
	u32_t	P0_0: 2;	
	u32_t	P0_1: 2;	
	u32_t	P0_2: 2;	
	u32_t	P0_3: 2;	
	u32_t	P0_4: 2;	
	u32_t	P0_5: 2;	
	u32_t	P0_6: 2;	
	u32_t	P0_7: 2;	
	u32_t	P0_8: 2;	
	u32_t	P0_9: 2;	
	u32_t	P0_10:2;	
	u32_t	P0_11:2;	
	u32_t	P0_12:2;	
	u32_t	P0_13:2;	
	u32_t	P0_14:2;	
	u32_t	P0_15:2;	
}pcb0_t;

typedef struct
{
	u32_t	P0_16:2;	
	u32_t	P0_17:2;	
	u32_t	P0_18:2;	
	u32_t	P0_19:2;	
	u32_t	P0_20:2;	
	u32_t	P0_21:2;	
	u32_t	P0_22:2;	
	u32_t	P0_23:2;	
	u32_t	P0_24:2;	
	u32_t	P0_25:2;	
	u32_t	P0_26:2;	
	u32_t	P0_27:2;	
	u32_t	P0_28:2;	
	u32_t	P0_29:2;	
	u32_t	P0_30:2;	
	u32_t	P0_31:2;	
}pcb1_t;

typedef struct
{
	u32_t	RESERVED1	:2;	
	u32_t	P1_36_26	:1;	
	u32_t	P1_25_16	:1;	
	u32_t	RESERVED2	:28;	
}pcb2_t;

#define PINSEL0        (*((volatile pcb0_t *) 0xE002C000))
#define PINSEL1        (*((volatile pcb1_t *) 0xE002C004))
#define PINSEL2        (*((volatile pcb2_t *) 0xE002C014))

/* General Purpose Input/Output (GPIO) */

#define IO0PIN          (*((volatile u32_t *) 0xE0028000))
#define IO0SET          (*((volatile u32_t *) 0xE0028004))
#define IO0DIR          (*((volatile u32_t *) 0xE0028008))
#define IO0CLR          (*((volatile u32_t *) 0xE002800C))

#define IO1PIN          (*((volatile u32_t *) 0xE0028010))
#define IO1SET          (*((volatile u32_t *) 0xE0028014))
#define IO1DIR          (*((volatile u32_t *) 0xE0028018))
#define IO1CLR          (*((volatile u32_t *) 0xE002801C))

#define FIO0DIR         (*((volatile u32_t *) 0x3FFFC000))
#define FIO0MASK        (*((volatile u32_t *) 0x3FFFC010))
#define FIO0PIN         (*((volatile u32_t *) 0x3FFFC014))
#define FIO0SET         (*((volatile u32_t *) 0x3FFFC018))
#define FIO0CLR         (*((volatile u32_t *) 0x3FFFC01C))

#define FIO1DIR         (*((volatile u32_t *) 0x3FFFC020))
#define FIO1MASK        (*((volatile u32_t *) 0x3FFFC030))
#define FIO1PIN         (*((volatile u32_t *) 0x3FFFC034))
#define FIO1SET         (*((volatile u32_t *) 0x3FFFC038))
#define FIO1CLR         (*((volatile u32_t *) 0x3FFFC03C))

/* Memory Accelerator Module (MAM) */
#define MAMCR           (*((volatile u8_t *) 0xE01FC000))
#define MAMTIM          (*((volatile u8_t *) 0xE01FC004))
#define MEMMAP          (*((volatile u8_t *) 0xE01FC040))

/* Phase Locked Loop 0 (PLL0) */
#define PLL0CON         (*((volatile u8_t *) 0xE01FC080))
#define PLL0CFG         (*((volatile u8_t *) 0xE01FC084))
#define PLL0STAT        (*((volatile u16_t*) 0xE01FC088))
#define PLL0FEED        (*((volatile u8_t *) 0xE01FC08C))
		
/* Phase Locked Loop 1 (PLL1) */
#define PLL1CON         (*((volatile u8_t *) 0xE01FC0A0))
#define PLL1CFG         (*((volatile u8_t *) 0xE01FC0A4))
#define PLL1STAT        (*((volatile u16_t*) 0xE01FC0A8))
#define PLL1FEED        (*((volatile u8_t *) 0xE01FC0AC))

/* VPB Divider */
#define VPBDIV          (*((volatile u8_t *) 0xE01FC100))

/* Power Control */
#define PCON            (*((volatile u8_t *) 0xE01FC0C0))
#define PCONP           (*((volatile u32_t *) 0xE01FC0C4))

/* External Interrupts */
#define EXTINT          (*((volatile u8_t *) 0xE01FC140))
#define INTWAKE         (*((volatile u16_t*) 0xE01FC144))
#define EXTMODE         (*((volatile u8_t *) 0xE01FC148))
#define EXTPOLAR        (*((volatile u8_t *) 0xE01FC14C))

/* Reset */
#define RSID            (*((volatile u8_t *) 0xE01FC180))

/* Code Security / Debugging */
#define CSPR            (*((volatile u8_t *) 0xE01FC184))

/* System Control Miscellaneous */
#define SCS             (*((volatile u32_t *) 0xE01FC1A0))

/* Timer 0 */
#define T0IR            (*((volatile u32_t *) 0xE0004000))
#define T0TCR           (*((volatile u32_t *) 0xE0004004))
#define T0TC            (*((volatile u32_t *) 0xE0004008))
#define T0PR            (*((volatile u32_t *) 0xE000400C))
#define T0PC            (*((volatile u32_t *) 0xE0004010))
#define T0MCR           (*((volatile u32_t *) 0xE0004014))
#define T0MR0           (*((volatile u32_t *) 0xE0004018))
#define T0MR1           (*((volatile u32_t *) 0xE000401C))
#define T0MR2           (*((volatile u32_t *) 0xE0004020))
#define T0MR3           (*((volatile u32_t *) 0xE0004024))
#define T0CCR           (*((volatile u32_t *) 0xE0004028))
#define T0CR0           (*((volatile u32_t *) 0xE000402C))
#define T0CR1           (*((volatile u32_t *) 0xE0004030))
#define T0CR2           (*((volatile u32_t *) 0xE0004034))
#define T0CR3           (*((volatile u32_t *) 0xE0004038))
#define T0EMR           (*((volatile u32_t *) 0xE000403C))
#define T0CTCR          (*((volatile u32_t *) 0xE0004070))

/* Timer 1 */
#define T1IR            (*((volatile u32_t *) 0xE0008000))
#define T1TCR           (*((volatile u32_t *) 0xE0008004))
#define T1TC            (*((volatile u32_t *) 0xE0008008))
#define T1PR            (*((volatile u32_t *) 0xE000800C))
#define T1PC            (*((volatile u32_t *) 0xE0008010))
#define T1MCR           (*((volatile u32_t *) 0xE0008014))
#define T1MR0           (*((volatile u32_t *) 0xE0008018))
#define T1MR1           (*((volatile u32_t *) 0xE000801C))
#define T1MR2           (*((volatile u32_t *) 0xE0008020))
#define T1MR3           (*((volatile u32_t *) 0xE0008024))
#define T1CCR           (*((volatile u32_t *) 0xE0008028))
#define T1CR0           (*((volatile u32_t *) 0xE000802C))
#define T1CR1           (*((volatile u32_t *) 0xE0008030))
#define T1CR2           (*((volatile u32_t *) 0xE0008034))
#define T1CR3           (*((volatile u32_t *) 0xE0008038))
#define T1EMR           (*((volatile u32_t *) 0xE000803C))
#define T1CTCR          (*((volatile u32_t *) 0xE0008070))

/* Pulse Width Modulator (PWM) */
#define PWMIR           (*((volatile u32_t *) 0xE0014000))
#define PWMTCR          (*((volatile u32_t *) 0xE0014004))
#define PWMTC           (*((volatile u32_t *) 0xE0014008))
#define PWMPR           (*((volatile u32_t *) 0xE001400C))
#define PWMPC           (*((volatile u32_t *) 0xE0014010))
#define PWMMCR          (*((volatile u32_t *) 0xE0014014))
#define PWMMR0          (*((volatile u32_t *) 0xE0014018))
#define PWMMR1          (*((volatile u32_t *) 0xE001401C))
#define PWMMR2          (*((volatile u32_t *) 0xE0014020))
#define PWMMR3          (*((volatile u32_t *) 0xE0014024))
#define PWMMR4          (*((volatile u32_t *) 0xE0014040))
#define PWMMR5          (*((volatile u32_t *) 0xE0014044))
#define PWMMR6          (*((volatile u32_t *) 0xE0014048))
#define PWMPCR          (*((volatile u32_t *) 0xE001404C))
#define PWMLER          (*((volatile u32_t *) 0xE0014050))

/* Universal Asynchronous Receiver Transmitter 0 (UART0) */
#define U0RBR           (*((volatile u8_t *) 0xE000C000))
#define U0THR           (*((volatile u8_t *) 0xE000C000))
#define U0IER           (*((volatile u32_t *) 0xE000C004))
#define U0IIR           (*((volatile u32_t *) 0xE000C008))
#define U0FCR           (*((volatile u8_t *) 0xE000C008))
#define U0LCR           (*((volatile u8_t *) 0xE000C00C))
#define U0MCR           (*((volatile u8_t *) 0xE000C010))
#define U0LSR           (*((volatile u8_t *) 0xE000C014))
#define U0MSR           (*((volatile u8_t *) 0xE000C018))
#define U0SCR           (*((volatile u8_t *) 0xE000C01C))
#define U0DLL           (*((volatile u8_t *) 0xE000C000))
#define U0DLM           (*((volatile u8_t *) 0xE000C004))
#define U0ACR           (*((volatile u32_t *) 0xE000C020))
#define U0FDR           (*((volatile u32_t *) 0xE000C028))
#define U0TER           (*((volatile u8_t *) 0xE000C030))

/* Universal Asynchronous Receiver Transmitter 1 (UART1) */
#define U1RBR           (*((volatile u8_t *) 0xE0010000))
#define U1THR           (*((volatile u8_t *) 0xE0010000))
#define U1IER           (*((volatile u32_t *) 0xE0010004))
#define U1IIR           (*((volatile u32_t *) 0xE0010008))
#define U1FCR           (*((volatile u8_t *) 0xE0010008))
#define U1LCR           (*((volatile u8_t *) 0xE001000C))
#define U1MCR           (*((volatile u8_t *) 0xE0010010))
#define U1LSR           (*((volatile u8_t *) 0xE0010014))
#define U1MSR           (*((volatile u8_t *) 0xE0010018))
#define U1SCR           (*((volatile u8_t *) 0xE001001C))
#define U1DLL           (*((volatile u8_t *) 0xE0010000))
#define U1DLM           (*((volatile u8_t *) 0xE0010004))
#define U1ACR           (*((volatile u32_t *) 0xE0010020))
#define U1FDR           (*((volatile u32_t *) 0xE0010028))
#define U1TER           (*((volatile u8_t *) 0xE0010030))

/* I2C Interface 0 */
#define I2C0CONSET      (*((volatile u8_t *) 0xE001C000))
#define I2C0STAT        (*((volatile u8_t *) 0xE001C004))
#define I2C0DAT         (*((volatile u8_t *) 0xE001C008))
#define I2C0ADR         (*((volatile u8_t *) 0xE001C00C))
#define I2C0SCLH        (*((volatile u16_t*) 0xE001C010))
#define I2C0SCLL        (*((volatile u16_t*) 0xE001C014))
#define I2C0CONCLR      (*((volatile u8_t *) 0xE001C018))

/* I2C Interface 1 */
#define I2C1CONSET      (*((volatile u8_t *) 0xE005C000))
#define I2C1STAT        (*((volatile u8_t *) 0xE005C004))
#define I2C1DAT         (*((volatile u8_t *) 0xE005C008))
#define I2C1ADR         (*((volatile u8_t *) 0xE005C00C))
#define I2C1SCLH        (*((volatile u16_t*) 0xE005C010))
#define I2C1SCLL        (*((volatile u16_t*) 0xE005C014))
#define I2C1CONCLR      (*((volatile u8_t *) 0xE005C018))

/* SPI0 (Serial Peripheral Interface 0) */
#define S0SPCR          (*((volatile u16_t*) 0xE0020000))
#define S0SPSR          (*((volatile u8_t *) 0xE0020004))
#define S0SPDR          (*((volatile u16_t*) 0xE0020008))
#define S0SPCCR         (*((volatile u8_t *) 0xE002000C))
#define S0SPINT         (*((volatile u8_t *) 0xE002001C))

/* SSP Controller (SPI1) */
#define SSPCR0          (*((volatile u16_t*) 0xE0068000))
#define SSPCR1          (*((volatile u8_t *) 0xE0068004))
#define SSPDR           (*((volatile u16_t*) 0xE0068008))
#define SSPSR           (*((volatile u8_t *) 0xE006800C))
#define SSPCPSR         (*((volatile u8_t *) 0xE0068010))
#define SSPIMSC         (*((volatile u8_t *) 0xE0068014))
#define SSPRIS          (*((volatile u8_t *) 0xE0068018))
#define SSPMIS          (*((volatile u8_t *) 0xE006801C))
#define SSPICR          (*((volatile u8_t *) 0xE0068020))

/* Real Time Clock */
#define ILR             (*((volatile u8_t *) 0xE0024000))
#define CTC             (*((volatile u16_t*) 0xE0024004))
#define CCR             (*((volatile u8_t *) 0xE0024008))
#define CIIR            (*((volatile u8_t *) 0xE002400C))
#define AMR             (*((volatile u8_t *) 0xE0024010))
#define CTIME0          (*((volatile u32_t *) 0xE0024014))
#define CTIME1          (*((volatile u32_t *) 0xE0024018))
#define CTIME2          (*((volatile u32_t *) 0xE002401C))
#define SEC             (*((volatile u8_t *) 0xE0024020))
#define MIN             (*((volatile u8_t *) 0xE0024024))
#define HOUR            (*((volatile u8_t *) 0xE0024028))
#define DOM             (*((volatile u8_t *) 0xE002402C))
#define DOW             (*((volatile u8_t *) 0xE0024030))
#define DOY             (*((volatile u16_t*) 0xE0024034))
#define MONTH           (*((volatile u8_t *) 0xE0024038))
#define YEAR            (*((volatile u16_t*) 0xE002403C))
#define ALSEC           (*((volatile u8_t *) 0xE0024060))
#define ALMIN           (*((volatile u8_t *) 0xE0024064))
#define ALHOUR          (*((volatile u8_t *) 0xE0024068))
#define ALDOM           (*((volatile u8_t *) 0xE002406C))
#define ALDOW           (*((volatile u8_t *) 0xE0024070))
#define ALDOY           (*((volatile u16_t*) 0xE0024074))
#define ALMON           (*((volatile u8_t *) 0xE0024078))
#define ALYEAR          (*((volatile u16_t*) 0xE002407C))
#define PREINT          (*((volatile u16_t*) 0xE0024080))
#define PREFRAC         (*((volatile u16_t*) 0xE0024084))

/* A/D Converter 0 (AD0) */
#define AD0CR           (*((volatile u32_t *) 0xE0034000))
#define AD0GDR          (*((volatile u32_t *) 0xE0034004))
#define AD0STAT         (*((volatile u32_t *) 0xE0034030))
#define AD0INTEN        (*((volatile u32_t *) 0xE003400C))
#define AD0DR0          (*((volatile u32_t *) 0xE0034010))
#define AD0DR1          (*((volatile u32_t *) 0xE0034014))
#define AD0DR2          (*((volatile u32_t *) 0xE0034018))
#define AD0DR3          (*((volatile u32_t *) 0xE003401C))
#define AD0DR4          (*((volatile u32_t *) 0xE0034020))
#define AD0DR5          (*((volatile u32_t *) 0xE0034024))
#define AD0DR6          (*((volatile u32_t *) 0xE0034028))
#define AD0DR7          (*((volatile u32_t *) 0xE003402C))

/* A/D Converter 1 (AD1) */
#define AD1CR           (*((volatile u32_t *) 0xE0060000))
#define AD1GDR          (*((volatile u32_t *) 0xE0060004))
#define AD1STAT         (*((volatile u32_t *) 0xE0060030))
#define AD1INTEN        (*((volatile u32_t *) 0xE006000C))
#define AD1DR0          (*((volatile u32_t *) 0xE0060010))
#define AD1DR1          (*((volatile u32_t *) 0xE0060014))
#define AD1DR2          (*((volatile u32_t *) 0xE0060018))
#define AD1DR3          (*((volatile u32_t *) 0xE006001C))
#define AD1DR4          (*((volatile u32_t *) 0xE0060020))
#define AD1DR5          (*((volatile u32_t *) 0xE0060024))
#define AD1DR6          (*((volatile u32_t *) 0xE0060028))
#define AD1DR7          (*((volatile u32_t *) 0xE006002C))

/* A/D Converter Global */
#define ADGSR           (*((volatile u32_t *) 0xE0034008))

/* D/A Converter */
#define DACR            (*((volatile u32_t *) 0xE006C000))

/* Watchdog */
#define WDMOD           (*((volatile u8_t *) 0xE0000000))
#define WDTC            (*((volatile u32_t *) 0xE0000004))
#define WDFEED          (*((volatile u8_t *) 0xE0000008))
#define WDTV            (*((volatile u32_t *) 0xE000000C))

/* USB Controller */
#define USBIntSt        (*((volatile u32_t *) 0xE01FC1C0))
#define USBDevIntSt     (*((volatile u32_t *) 0xE0090000))
#define USBDevIntEn     (*((volatile u32_t *) 0xE0090004))
#define USBDevIntClr    (*((volatile u32_t *) 0xE0090008))
#define USBDevIntSet    (*((volatile u32_t *) 0xE009000C))
#define USBDevIntPri    (*((volatile u8_t *) 0xE009002C))
#define USBEpIntSt      (*((volatile u32_t *) 0xE0090030))
#define USBEpIntEn      (*((volatile u32_t *) 0xE0090034))
#define USBEpIntClr     (*((volatile u32_t *) 0xE0090038))
#define USBEpIntSet     (*((volatile u32_t *) 0xE009003C))
#define USBEpIntPri     (*((volatile u32_t *) 0xE0090040))
#define USBReEp         (*((volatile u32_t *) 0xE0090044))
#define USBEpInd        (*((volatile u32_t *) 0xE0090048))
#define USBMaxPSize     (*((volatile u32_t *) 0xE009004C))
#define USBRxData       (*((volatile u32_t *) 0xE0090018))
#define USBRxPLen       (*((volatile u32_t *) 0xE0090020))
#define USBTxData       (*((volatile u32_t *) 0xE009001C))
#define USBTxPLen       (*((volatile u32_t *) 0xE0090024))
#define USBCtrl         (*((volatile u32_t *) 0xE0090028))
#define USBCmdCode      (*((volatile u32_t *) 0xE0090010))
#define USBCmdData      (*((volatile u32_t *) 0xE0090014))
#define USBDMARSt       (*((volatile u32_t *) 0xE0090050))
#define USBDMARClr      (*((volatile u32_t *) 0xE0090054))
#define USBDMARSet      (*((volatile u32_t *) 0xE0090058))
#define USBUDCAH        (*((volatile u32_t *) 0xE0090080))
#define USBEpDMASt      (*((volatile u32_t *) 0xE0090084))
#define USBEpDMAEn      (*((volatile u32_t *) 0xE0090088))
#define USBEpDMADis     (*((volatile u32_t *) 0xE009008C))
#define USBDMAIntSt     (*((volatile u32_t *) 0xE0090090))
#define USBDMAIntEn     (*((volatile u32_t *) 0xE0090094))
#define USBEoTIntSt     (*((volatile u32_t *) 0xE00900A0))
#define USBEoTIntClr    (*((volatile u32_t *) 0xE00900A4))
#define USBEoTIntSet    (*((volatile u32_t *) 0xE00900A8))
#define USBNDDRIntSt    (*((volatile u32_t *) 0xE00900AC))
#define USBNDDRIntClr   (*((volatile u32_t *) 0xE00900B0))
#define USBNDDRIntSet   (*((volatile u32_t *) 0xE00900B4))
#define USBSysErrIntSt  (*((volatile u32_t *) 0xE00900B8))
#define USBSysErrIntClr (*((volatile u32_t *) 0xE00900BC))
#define USBSysErrIntSet (*((volatile u32_t *) 0xE00900C0))

#endif  // __LPC214x_H
