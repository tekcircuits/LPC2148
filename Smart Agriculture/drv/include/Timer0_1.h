#ifndef _TIMER0_H
#define _TIMER0_H

extern u32_t ctr_10ms;

 __irq void T0ISR(void);
 void Enable_Timer0(void);
void Disable_Timer0(void );
void initTimer0(void);


#endif


