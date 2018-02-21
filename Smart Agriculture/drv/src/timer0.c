/*****************************************************************************
 *   timer0.c:  Timer C file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2012, MICROBIT Embedded Solutions
 *   All rights reserved.
 *
 *   History
 *   2012.12.07  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#include <global.h>
#include <LPC2148.h>		/* LPC21XX Peripheral Registers	*/
#include <pconp.h>
#include <vic.h>
#include <timer0.h>

u32_t ctr_10ms = 0;

/******************************************************************************
** Function name:		Timer0Handler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**				executes each 10ms @ 60 MHz CPU Clock
**
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void ISR_TIMER0(void) __irq 
{  
	Set_Bit(T0IR,BIT0);			/* clear interrupt flag */
    
	ctr_10ms++;
    
	VICVectAddr = 0;	/* Acknowledge Interrupt */
}

/******************************************************************************
** Function name:		enable_timer
**
** Descriptions:		Enable timer
**
** Returned value:		None
** 
******************************************************************************/

void Enable_Timer0(void )
{
 	Set_Bit(T0TCR,BIT0);
    return;
}

/******************************************************************************
** Function name:		disable_timer
**
** Descriptions:		Disable timer
**
** Returned value:		None
** 
******************************************************************************/
void Disable_Timer0(void )
{
 	Clr_Bit(T0TCR,BIT0);
    return;
}
/******************************************************************************
** Function name:		reset_timer
**
** Descriptions:		Reset timer
**
** Returned value:		None
** 
******************************************************************************/
void Reset_Timer0(void)
{
 	Set_Bit(T0TCR,BIT1);
	return;
}

/******************************************************************************
** Function name:		init_timer
**
** Descriptions:		Initialize timer, set timer interval, reset timer,
**				install timer interrupt handler
**
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void Init_Timer0(void) 
{
	ctr_10ms = 0;
	
	Power_On_Timer0();
	
	T0TC=0;													//Timer counter should be zero
	
	T0PR   = 59;                       //To set the time clock to 1Mhz
	
	T0MR0  = INTERVAL_10MS;      	  /* 10mSec = 10000 -1 counts */
	
	T0MCR |= (1<<BIT1) | (1<<BIT0);	  /* Interrupt and Reset on MR0 */
	
	Install_IRQ( TIMER0_INT, (void *)ISR_TIMER0 );
}


void Init_Timer0_3S(void) 
{
	ctr_10ms = 0;
	
	Power_On_Timer0();
	
	T0TC=0 ;                            //Timer counter should be zero
	
	T0PR   = 59;                       //To set the time clock to 1Mhz
	
	T0MR0  = INTERVAL_3S;      	     /* 3Sec = 3000000 -1 counts */
	
	T0MCR |= (1<<BIT1) | (1<<BIT0);	  /* Interrupt and Reset on MR0 */
	
	Install_IRQ( TIMER0_INT, (void *)ISR_TIMER0 );
}

