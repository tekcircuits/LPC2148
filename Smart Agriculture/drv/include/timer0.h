/*****************************************************************************
 *   timer0.h:  Header file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2012, MICROBIT Embedded Solutions
 *   All rights reserved.
 *
 *   History
 *   2012.12.09  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __TIMER0_H 
#define __TIMER0_H

#define INTERVAL_10MS	9999			/* 10mSec =10000 -1 counts */
#define INTERVAL_3S	  2999999		/* 3Sec =3000000 -1 counts */
		
extern u32_t ctr_10ms;

void Init_Timer0(void);
void Enable_Timer0(void );
void Disable_Timer0(void);
void Reset_Timer0(void);
void Init_Timer0_3S(void);

#endif /* end __TIMER0_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
