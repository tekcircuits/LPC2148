#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <pconp.h>
#include <adc.h>


/* 	ANALOG SOURCE		ADC INPUT 	  */
/* 	------------   		--------- 	*/
/* 	0 to 3.3V POT		AD01    	    */
/* 	LM35 tSENSOR		AD02    	    */

// ADC Counts every 3.25mV

#define ADC_DATA_MASK	(1<<BIT15)| (1<<BIT14) | (1<<BIT13)| (1<<BIT12)| (1<<BIT11)| (1<<BIT10)| (1<<BIT9)| (1<<BIT8)| (1<<BIT7)| (1<<BIT6)

#define Select_AD01()	Set_Bit(AD0CR,BIT1)
#define Select_AD02()	Set_Bit(AD0CR,BIT2)
#define Select_AD03()	Set_Bit(AD0CR,BIT3)
#define Select_AD04()	Set_Bit(AD0CR,BIT4)


#define Start_ADC0()	Set_Bit(AD0CR,BIT24) 
#define Stop_ADC0()		Clr_Bit(AD0CR,BIT24)

#define Start_ADC0_Burst_Mode()		Set_Bit(AD0CR,BIT16)
#define Stop_ADC0_Burst_Mode()		Clr_Bit(AD0CR,BIT16)

/*
#define Wait_AD01()		while(Is_Bit_Clr(AD0DR1,BIT31)) 
#define Wait_AD02()		while(Is_Bit_Clr(AD0DR2,BIT31))
*/

// To avoid Compiler Warning
#define Wait_AD01()		while(!(AD0DR1 & 0x80000000)) 
#define Wait_AD02()		while(!(AD0DR2 & 0x80000000)) 
#define Wait_AD03()		while(!(AD0DR3 & 0x80000000)) 

#define Enable_ADC0_Power_Down()	Clr_Bit(AD0CR,BIT21)
#define Disable_ADC0_Power_Down()	Set_Bit(AD0CR,BIT21)

u16_t adc_0[5];

__inline static void De_Select_ADC0_Inputs(void) 
{
	Clr_Bit(AD0CR,BIT0);
	Clr_Bit(AD0CR,BIT1);
	Clr_Bit(AD0CR,BIT2);
	Clr_Bit(AD0CR,BIT3);
	Clr_Bit(AD0CR,BIT4);
	Clr_Bit(AD0CR,BIT5);
	Clr_Bit(AD0CR,BIT6);
	Clr_Bit(AD0CR,BIT7);
}


__inline static void Set_ADC0_Clock(void)
{
	AD0CR |= (1<<BIT13) | (1<<BIT10); // DIV = 39
	// ADC_CLOCK = PCLK/(DIV + 1)
	//           = (60/40)MHz
	//			     = 1.5MHz
}

__inline static u32_t Read_AD01(void)
{
	u32_t adc_count=0;
	
	adc_count = AD0DR1;
	
	adc_count &= ADC_DATA_MASK; // Make all other bits 0's expect BIT15 to BIT6
	
	adc_count >>= 6; // 10-bit adc count is in BIT9 to BIT0
	
	return adc_count;
}

__inline static u32_t Read_AD02(void)
{
	u32_t adc_count=0;
	
	adc_count = AD0DR2;
	
	adc_count >>= 6;
	
	adc_count &= ADC_DATA_MASK;
	
	return adc_count;
}

__inline static u32_t Read_AD03(void)
{
	u32_t adc_count=0;
	
	adc_count = AD0DR3;
	
	adc_count >>= 6;
	
	adc_count &= ADC_DATA_MASK;
	
	return adc_count;
}




void Init_ADC0(void) 
{
	PINSEL1.P0_28 = P0_28_AD01;
	PINSEL1.P0_29 = P0_29_AD02;
	PINSEL1.P0_30 = P0_30_AD03;
	
	Power_On_ADC0();
	Disable_ADC0_Power_Down();	
	De_Select_ADC0_Inputs();
	Stop_ADC0();
	Select_AD01();
	Select_AD02();
	Select_AD03();
	
	//Start_ADC0();
	Start_ADC0_Burst_Mode();
	//ADGSR |= 0x01000000;
}


void update_ADC_Channels(void){
	
	
	//Stop_ADC0_Burst_Mode();
	//Start_ADC0();
		
	//Wait_AD01();
	//Wait_AD02();
	//Wait_AD03();	
	
	adc_0[0] = Read_AD01();	
	adc_0[1] = Read_AD02();
	adc_0[2] = Read_AD03();
	
	//Start_ADC0_Burst_Mode();
	
	//De_Select_ADC0_Inputs();
	//Stop_ADC0();
	
}
u16_t Get_AD01(void)  
{
	return adc_0[0];
}

u16_t Get_AD02(void)
{
	return adc_0[1];
}

u16_t Get_AD03(void) 
{
	u32_t ad03_count=0;
	
	//De_Select_ADC0_Inputs();
	//Stop_ADC0();
	Select_AD03();
	
	//Start_ADC0();
	
	Wait_AD03();
	ad03_count = Read_AD03();

	return ad03_count;
}









