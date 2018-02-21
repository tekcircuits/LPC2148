#include <app.h>

char sums_buffer[160];
/* UART1 Core Device Driver Functions */

__inline static void Config_UART1_Pins(void)
{
	PINSEL0.P0_8 = P0_8_TXD1; 
	PINSEL0.P0_9 = P0_9_RXD1;
}

__inline static void Set_UART1_Data_Frame(void)
{
	// Configure U0LCR Register Bits: 8-Bit Data, No Parity and 1 Stop Bit
	U1LCR |= (1<<BIT1) | (1<<BIT0); // U0LCR = 0x03
}
__inline static void Set_UART1_Baud_9600(void)
{
	/* Please check LPC2148 User Manual Page No:150 for Baudrate Calculation */ 
	
	// To update Baud, DLAB(BIT7)of U1LCR Register = 1 
	Set_Bit(U1LCR,BIT7);
	
	// Update BIT7 to BIT0 of U1DLL   
	U1DLL = 0x17;	
	
	// Update BIT7 to BIT0 of U1DLM           
	U1DLM = 0x01;	
 	
	// Update DIVADVAL(BIT0 to BIT3) & MULVAL(BIT4 to BIT7) bits of U1FDR Register
	U1FDR = 0x52;
	
	// After Baud update, DLAB(BIT7)of U1LCR Register = 0 
	Clr_Bit(U1LCR,BIT7);
}
__irq void UART1ISR(void)
{
				//Write back to IR to clear Interrupt Flag
  
        VICVectAddr = 0x0; //This is t0o signal end of interrupt execution
}

void UART1_RX_Interrupt_init(void)
{
	
	VICVectAddr5 = (unsigned)UART1ISR;	//Pointer Interrupt Function (ISR)
  VICVectCntl5 = 0x20 | 7;	   //0x20 (i.e bit5 = 1) -> to enable Vectored IRQ slot
                               //0x7 (bit[4:0]) -> this the source number - here its UART which has VIC channel mask # as 7
                               //You can get the VIC Channel number from Lpc214x manual R2 - pg 58 / sec 5.5
  VICIntEnable |= 1<<7;		   //Enable UART int
	U1IER = 1;
} 

void Init_UART1(void){
	
	Config_UART1_Pins();
	Power_On_UART1();
	Set_UART1_Data_Frame();
	Set_UART1_Baud_9600();
	//UART1_RX_Interrupt_init();
}

void Set_UART1_Data(u8_t uart_data){
	// Check for Transmit Buffer Status: THRE(BIT5) of U0LSR
	while((Is_Bit_Clr(U1LSR,BIT5))); // Wait if it is Busy
	
	// Update Transmit Holding Register to send 8-bit data:U0THR	
	U1THR = uart_data;
}

u8_t Get_UART1_Data(void)
{
	u8_t rdata = 0;
	
	// Check for Received Data Status: RDR(BIT0) of U0LSR
	if(Is_Bit_Set(U1LSR,BIT0))
	{
	// Read 8-bit data from Receive Buffer Register:U0RBR
		rdata = U1RBR;
	}
	// Return received data or NULL 
	return rdata;
}

/* UART Device Driver to send 3-digit number,000 to 999 */
void Set_UART1_Num(u16_t num)
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

	Set_UART1_Data(n1);
	Set_UART1_Data(n2);
	Set_UART1_Data(n3);

}

/* UART Device Driver to send a string */
void Set_UART1_String(char * str)
{
	while(*str!= '\0')
	{
		Set_UART1_Data(*str);
		str++;
	}
}







