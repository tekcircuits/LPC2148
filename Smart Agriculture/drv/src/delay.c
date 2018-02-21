#include <global.h>
#include <delay.h>

/**************************************************************************
  Function Name : Delay()

  Description :This function suspends the tasks for specified ticks.	

  Input :  ticks:no of ticks in multiple of 1 usec
            task: task to be suspended

  Output : void

*******************************************************************************/

void Delay(u32_t ticks)
{
  u32_t outer_ctr=0,inner_ctr=0;

  for(outer_ctr=0;outer_ctr<ticks;outer_ctr++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 1 us */
    for(inner_ctr=0;inner_ctr<35;inner_ctr++);
  }
}

void delay_ms(unsigned int ticks)
{
	 u32_t outer_ctr=0,inner_ctr=0;

  for(outer_ctr=0;outer_ctr<ticks;outer_ctr++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 1 us */
    for(inner_ctr=0;inner_ctr<1035;inner_ctr++);
  }
}





