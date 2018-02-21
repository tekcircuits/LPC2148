#include<global.h>
#include<lpc2148.h>
#include<pconp.h>
#include<pcb.h>
#include<i2c0.h>
#include<lcd.h>

#define ASSERT_ACK_BIT()      I2C0CONSET=(1<<BIT2)
#define ASSERT_NACK_BIT()     I2C0CONCLR=(1<<BIT2)

#define CLR_SI_BIT()          I2C0CONCLR=(1<<BIT3)

#define ENABLE_STOP_BIT()     I2C0CONSET=(1<<BIT4)

#define ENABLE_START_BIT()    I2C0CONSET=(1<<BIT5)|(1<<BIT3)
#define DISABLE_START_BIT()   I2C0CONCLR=(1<<BIT5)

#define ENABLE_I2C0_PIN()     I2C0CONSET=(1<<BIT6)
#define DISABLE_I2C0_PIN()    I2C0CONCLR=(1<<BIT6)


__inline static void Config_I2C0_Pins(void)
{
	PINSEL0.P0_2=P0_2_SCL0;
	PINSEL0.P0_3=P0_3_SDA0;
}

__inline static void Wait_for_Status(void)
{
	CLR_SI_BIT();
	while(!(I2C0CONSET&(1<<BIT3)));//Wait for I2C bus busy
	
}

void Init_I2C0(void)
{
	Config_I2C0_Pins();
	Power_On_I2C0();
	I2C0SCLH=I2C0SCLL=300; // to set clock into 100khz	
	ENABLE_I2C0_PIN();
	
}

u8_t Start_I2C0(u8_t slave_addr) // start with slave address
{
	ENABLE_START_BIT();
	Wait_for_Status();
	
	DISABLE_START_BIT();

	I2C0DAT=slave_addr;
	Wait_for_Status();
	
	if((I2C0STAT==0x18)|(I2C0STAT==0x40))
		return 0;
	else
		return 1;
}

u8_t Set_I2C0_DATA(u8_t DAT) //we can pass the data
{
	I2C0DAT=DAT;
	Wait_for_Status();
	if(I2C0STAT==0x28)
		return 0;
	else
		return 1;
}

void STOP_I2C0(void)
{
	CLR_SI_BIT();
	ENABLE_STOP_BIT();
}

u8_t Get_I2C0_DATA(void)   //we can receive the data
{
	u8_t raw_data=0;
	ASSERT_ACK_BIT();
	Wait_for_Status();
	
	raw_data=I2C0DAT;
	if(I2C0STAT!=0x50)
		return 1;
	else
		return raw_data;
}

u8_t Get_I2C0_DATA_Last(void)
{
	u8_t raw_data=0;
	ASSERT_NACK_BIT();
	Wait_for_Status();
	
	raw_data=I2C0DAT;
	if(I2C0STAT!=0x58)
		return 1;
	else
		return raw_data;
}

void Set_I2C0_string(u8_t *ptr)
{
	while(*ptr!='\0')
	{
		Set_I2C0_DATA(*ptr);
		ptr++;
	}
}

void Set_I2C0_Num_4_Digit(u16_t num)
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

	Set_I2C0_DATA(n1);
	Set_I2C0_DATA(n2);
	Set_I2C0_DATA(n3);
	Set_I2C0_DATA(n4);

}

void Set_I2C0_Num_3_Digit(u16_t num)
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

	Set_I2C0_DATA(n1);
	Set_I2C0_DATA(n2);
	Set_I2C0_DATA(n3);
}
void set_I2C0_Num_2_Digit(u16_t num)
{
	u16_t n1,n2;
	n1=num/10+48;
	n2=num%10+48;
	Set_I2C0_DATA(n1);
	Set_I2C0_DATA(n2);
}
