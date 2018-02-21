

#include <global.h>
#include <lpc2148.h>
#include <pcb.h>
#include <delay.h>
#include <lcd4bit.h>

/* 		LCD_SIGNAL			GPIO		
		 ----------  		------		
		 LCD_RS 		 	P1.16	
		 LCD_EN 		 	P1.17		 

		 LCD_D0 			P1.18
		 LCD_D1 		 	P1.19		
		 LCD_D2			 	P1.20		
		 LCD_D3		  	P1.21
		 LCD_D4		  	P1.22
		 LCD_D5		  	P1.23
		 LCD_D6		  	P1.24
		 LCD_D7		  	P1.25
		 
	
*/

#define LCD_DATA_MASK 	(1<<BIT25) | (1<<BIT24) | (1<<BIT23) | (1<<BIT22)
#define LCD_CTRL_MASK 	(1<<BIT17) | (1<<BIT16)

#define	Set_LCD_Command_Mode()	Set_Bit(IO1CLR,BIT16) // LCD_RS = 0
#define	Set_LCD_Data_Mode()		Set_Bit(IO1SET,BIT16) // LCD_RS = 1


#define	Set_LCD_Write_Mode()	Set_Bit(IO1CLR,BIT16); \
															Set_Bit(IO1DIR,BIT21)    
    

#define	Set_LCD_Enable_HIGH()	Set_Bit(IO1SET,BIT17)    // LCD_EN = 1
#define	Set_LCD_Enable_LOW()	Set_Bit(IO1CLR,BIT17)    // LCD_EN = 0


__inline static void Config_LCD_Pins(void)
{
	// Configure P0.15 to P0.21 as GPIO Pins
	PINSEL2.P1_25_16 = P1_25_16_GPIO;
	
	
	// Configure P1.16 to P1.26 as Outputs	IO1DIR |= LCD_DATA_MASK;
	IO1DIR |= 0xFFFF0000;

	// Set LCD Control Signals to LOW
	IO1CLR |= LCD_CTRL_MASK;
	IO1CLR |= LCD_DATA_MASK;
}

__inline static void Write_LCD_Port(u32_t lcd_data)
{
	IO1CLR = LCD_DATA_MASK;
	IO1SET = (lcd_data << 22)&(LCD_DATA_MASK);
}


//__inline static void Get_LCD_Status(void)
//{
//	Set_LCD_Command_Mode();  // LCD_RS=0 
//	Set_LCD_Read_Mode();     // LCD_RW=1
// 	Set_LCD_Enable_HIGH();   // LCD_EN=1
//  
//	while(Is_Bit_Set(IO0PIN,BIT21));		/* wait for busy flag(LCD_D7) to become low */
//  
//	Set_LCD_Enable_LOW();   // LCD_EN=0
//	Set_LCD_Write_Mode();   // LCD_RW=0
//  
//	Delay(100);  
//}

/* LCD Device Driver to Give LCD Commands */

void Set_LCD_Command(u8_t lcd_cmd)
{

	Set_LCD_Command_Mode();
	Write_LCD_Port(lcd_cmd >> 4);
	
 	Set_LCD_Enable_HIGH();   
	Delay(2000);
	Set_LCD_Enable_LOW(); 
	
	Set_LCD_Command_Mode();
	Write_LCD_Port(lcd_cmd);
	
 	Set_LCD_Enable_HIGH();   
	Delay(2000);
	Set_LCD_Enable_LOW(); 
}

/* LCD Device Driver to Display Alpha-Numeric Characters */

void Set_LCD_Char(u8_t lcd_data)
{

	Set_LCD_Data_Mode();
	Write_LCD_Port(lcd_data >> 4);
 	
	Set_LCD_Enable_HIGH();   
	Delay(2000);
	Set_LCD_Enable_LOW(); 
		
	Set_LCD_Data_Mode();
	Write_LCD_Port(lcd_data);
 	
	Set_LCD_Enable_HIGH();   
	Delay(2000);
	Set_LCD_Enable_LOW();   
}
void set_LCD_Num_2_Digit(u16_t num)
{
	u16_t n1,n2;
	n1=num/10+48;
	n2=num%10+48;
	Set_LCD_Char(n1);
	Set_LCD_Char(n2);
}

/* LCD Device Driver to display 3-digit number,000 to 999 */
void Set_LCD_Num_3_Digit(u32_t num)
{
	u16_t n1=0,n2=0,n3=0; 
	
	n1 = num/100;
	n1 = n1+48; 

	n2 = num%100; 
	
	n2 = n2/10;   
	n2 = n2+48; 

	n3 = num%100;  
	n3 = n3%10;    
	n3 = n3+48;   

	Set_LCD_Char(n1);
	Set_LCD_Char(n2);
	Set_LCD_Char(n3);
}

void Set_LCD_Num_4_Digit(u32_t num)
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

	Set_LCD_Char(n1);
	Set_LCD_Char(n2);
	Set_LCD_Char(n3);
	Set_LCD_Char(n4);
}
/* LCD Device Driver to display a string up to 16 characters */
void Set_LCD_String(char * str)
{
	while(*str!= '\0')
	{
		Set_LCD_Char(*str);
		str++;
	}
}


/* LCD Initialization Device Driver */
void Init_LCD(void)
{
	// LCD Initialization Sequence
	Config_LCD_Pins();
	Delay(2000);

	Set_LCD_Command(LCD_4BIT);   // 4-bit interface, two line, 5X7 dots.        
	Set_LCD_Command(0x02);   // cursor home                                 
	Set_LCD_Command(0x06);   // Entry mode 
	Set_LCD_Command(0x0C);   // Display on cursor off
	Set_LCD_Command(0x80);   // Move cursor right by 1 char
	Set_LCD_Command(LCD_CLR);   // Clear display
}

void gotoxy_lcd(unsigned char col,unsigned char line)
{
	if (line == 1){
		//write_lcd(0x7f+col);
	}
	if (line == 2){
		//write_lcd(0xbf+col);
	}
}


