#include<global.h>
#include<lpc2148.h>
#include<pcb.h>
#include<pconp.h>
#include<Timer0_1.h>


u32_t ctr_10ms=0;
u32_t ctr_3s=0;

#define MR0I (1<<0) //Interrupt When TC matches MR0
#define MR0R (1<<1) //Reset TC when TC matches MR0


__irq void T0ISR(void)
{
        Set_Bit( T0IR,BIT0);	//Write back to IR to clear Interrupt Flag

        ctr_10ms++;
    
        VICVectAddr = 0x0; //This is t0o signal end of interrupt execution
}

void Enable_Timer0(void)
	{
		Set_Bit(T0TCR,BIT0);
    return;
	}
	
	void Disable_Timer0(void )
{
 	Clr_Bit(T0TCR,BIT0);
    return;
}
void initTimer0(void)
{
   Power_On_Timer0();
    T0CTCR = 0x0;
    T0PR = 59;    
    T0MR0 = 9999;           /* 10mSec = 10000 -1 counts */
	
		//T0MR0 = 299999;           /* 3Sec = 3000000 -1 counts */
	
    T0MCR = MR0I | MR0R;   //Set bit0 & bit1 to High which is to : Interrupt & Reset TC on MR0  

 //----------Setup Timer0 Interrupt-------------

  VICVectAddr4 = (unsigned )T0ISR;	//Pointer Interrupt Function (ISR)

  VICVectCntl4 = 0x20 | 4;	   //0x20 (i.e bit5 = 1) -> to enable Vectored IRQ slot
                               //0x4 (bit[4:0]) -> this the source number - here its timer0 which has VIC channel mask # as 4
                               //You can get the VIC Channel number from Lpc214x manual R2 - pg 58 / sec 5.5

  VICIntEnable = 0x10;		   //Enable timer0 int
  //T0TCR = 0x02;
} 
