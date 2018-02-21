/*****************************************************************************
 *   rtc.h:  Header file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2012, MICROBIT Embedded Solutions
 *   All rights reserved.
 *
 *   History
 *   2012.12.12  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __RTC_H 
#define __RTC_H

typedef struct 
{
    u32_t sec;     			/* Second value - [0,59] */
    u32_t min;     			/* Minute value - [0,59] */
    u32_t hour;    			/* Hour value - [0,23] */
    u32_t dom;    			/* Day of the month value - [1,31] */
    u32_t mon;     			/* Month value - [1,12] */
    u32_t year;   			/* Year value - [0,4095] */
    u32_t dow;    			/* Day of week value - [0,6] */
    u32_t doy;    			/* Day of year value - [1,365] */
} rtc_t;


extern rtc_t current_time;

void Init_RTC(void);
void Start_RTC(void);
void Stop_RTC(void);
void Reset_RTC(void);

void Set_RTC(rtc_t );
void Set_RTC_Alarm(rtc_t );
void Get_RTC(void);

void Set_Default_RTC(void);

#endif /* end __RTC_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
