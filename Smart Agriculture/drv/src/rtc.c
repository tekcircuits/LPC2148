/*****************************************************************************
 *   rtc.c:  Realtime clock C file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2012, MICROBIT Embedded Solutions
 *   All rights reserved.
 *
 *   History
 *   2012.12.12  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#include <global.h>
#include <lpc2148.h>                        /* LPC21xx definitions */
#include <pconp.h>
#include <rtc.h>
#include <vic.h>
#include <buz.h>


rtc_t current_time;

void Set_Default_RTC(void)
{
	SEC     =	0;     
	MIN     =   02;     
	HOUR    =   20;     
	DOM     =   16;     
	DOW     =   8;     
	DOY     =   348;     
	MONTH   =   12;     
	YEAR    =   2012;
}

void Reset_RTC(void)
{   
   // Set the BIT1 of CCR to reset the RTC Clock Counters 
   
   CCR |= (1<<BIT1);
   return;
}

static void Reset_RTC_Interrupts(void)
{   
    // Set the BIT0 of ILR to clear the Clock / Calender register increment  Interrupt
    ILR |= (1<<BIT0);


    // Set the BIT1 of ILR to clear the Alarm register match  Interrupt
    ILR |= (1<<BIT1);

    return;
}

void Init_RTC(void)
{
  /* Enable PCONP for RTC to enable PCLK Initially */
  Power_On_RTC();
	
  AMR  = 0;   
  CIIR = 0;   
  CCR  = 0;   

 /* Clear the Interrupt Location Register */
  Reset_RTC_Interrupts();

}

void Start_RTC(void) 
{
 /* Set the BIT0 of CCR to Initialize RTC Count Registers */
   CCR |= (1<<BIT0);

  /* Choose Interrupt Event*/
  AMR = 0xff; // Disable Alarm
 // Disable Interrupts

 /* Enable external 32.768kHz crystal */
  CCR |= (1<<BIT4);
	
 /* Disconnect PCLK using PCON*/
 Power_Off_RTC(); // It doesnt mean that RTC is Off

return;
}

void Stop_RTC(void)
{   
    /*--- Stop RTC counters ---*/
	Clr_Bit(CCR,BIT0);
    return;
} 


void Set_RTC(rtc_t set_clock_data)
{
  //TBD  
	return;
}

void Set_RTC_Alarm(rtc_t set_alarm_data)
{   
  //TBD  
    return;
}

rtc_t Get_RTC(void)
{
    rtc_t rtc_data;
    
  //TBD  
 
	return rtc_data;    
}



