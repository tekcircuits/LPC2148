#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <pconp.h>
#include <uart0.h>

/* UART0 Core Device Driver Functions */

__inline static void Config_UART0_Pins(void)
{
	PINSEL0.P0_0 = P0_0_TXD0; 
	PINSEL0.P0_1 = P0_1_RXD0;
}

__inline static void Set_UART0_Data_Frame(void)
{
	// Configure U0LCR Register Bits: 8-Bit Data, No Parity and 1 Stop Bit
	U0LCR |= (1<<BIT1) | (1<<BIT0); // U0LCR = 0x03
}

__inline static void Set_UART0_Baud_9600(void)
{
	/* Please check LPC2148 User Manual Page No:150 for Baudrate Calculation */ 
	
	// To update Baud, DLAB(BIT7)of U0LCR Register = 1 
	Set_Bit(U0LCR,BIT7);
	
	// Update BIT7 to BIT0 of U0DLL   
	U0DLL = 0x17;	
	
	// Update BIT7 to BIT0 of U0DLM           
	U0DLM = 0x01;	
 	
	// Update DIVADVAL(BIT0 to BIT3) & MULVAL(BIT4 to BIT7) bits of U0FDR Register
	U0FDR = 0x52;
	
	// After Baud update, DLAB(BIT7)of U0LCR Register = 0 
	Clr_Bit(U0LCR,BIT7);
}

void Init_UART0(void)
{
	Config_UART0_Pins();
	Power_On_UART0();
	Set_UART0_Data_Frame();
	Set_UART0_Baud_9600();
}

void Set_UART0_Data(u8_t uart_data)
{
	// Check for Transmit Buffer Status: THRE(BIT5) of U0LSR
	while((Is_Bit_Clr(U0LSR,BIT5))); // Wait if it is Busy
	
	// Update Transmit Holding Register to send 8-bit data:U0THR	
	U0THR = uart_data;
}

u8_t Get_UART0_Data(void)
{
	u8_t rdata = 0;
	
	// Check for Received Data Status: RDR(BIT0) of U0LSR
	if(Is_Bit_Set(U0LSR,BIT0))
	{
	// Read 8-bit data from Receive Buffer Register:U0RBR
		rdata = U0RBR;
	}
	// Return received data or NULL 
	return rdata;
}

void set_UART0_2_Num(u16_t num)
{
	u16_t n1,n2;
	n1=num/10+48;
	n2=num%10+48;
	Set_UART0_Data(n1);
	Set_UART0_Data(n2);
}


/* UART Device Driver to send 3-digit number,000 to 999 */
void Set_UART0_3_Num(u16_t num)
{
	u16_t n1,n2,n3; 
	
	n1 = num/100;
	n1 = n1+48; 

	n2 = num%100; 
	
	n2 = n2/10;   
	n2 = n2+48; 

	n3 = num%100;  
	n3 = n3%10;    
	n3 = n3+48;   

	Set_UART0_Data(n1);
	Set_UART0_Data(n2);
	Set_UART0_Data(n3);

}
void Set_UART0_4_Num(u32_t num)
{
	u16_t n1=0,n2=0,n3=0,n4=0; 
	
	n1 = num/1000;
	n1 = n1+48; 

	n2 = num%1000; 
	n2 = n2/100;   
	n2 = n2+48; 

	n3 = num%1000;  
	n3 = n3%100;
	n3 = n3/10;  
	n3 = n3+48;   
	
	n4 = num%1000;  
	n4 = n4%100;
	n4 = n4%10;  
	n4 = n4+48; 

	Set_UART0_Data(n1);
	Set_UART0_Data(n2);
	Set_UART0_Data(n3);
	Set_UART0_Data(n4);
}

/* UART Device Driver to send a string */
void Set_UART0_String(char * str)
{
	while(*str!= '\0')
	{
		Set_UART0_Data(*str);
		str++;
	}
}
