#include<global.h>
#include<lpc2148.h>
#include<pll0.h>
#include<pcb.h>
#include<pconp.h>
#include<uart0.h>
#include<lcd.h>
#include<delay.h>
#include<gps.h>
#include<gsm.h>
#include<string.h>


char gps_rmc_data[50],i;
char *get_time = "Time:",*time_adj,*sms_cod;
char gps_rmc[4];

void send_GPS_Data_SMS(char *msg)
{
	strcat(msg,"\n");
	strcat(msg,"Details:\n");
	strcat(msg,get_gps_time());
	strcat(msg,"\n");
	strcat(msg,"Google Map link\n");
	strcat(msg,"click:\n");
	strcat(msg,"https://www.google.co.in/maps/@");
	strcat(msg,get_gps_codinates());
	strcat(msg,",16z?hl=en");
	SMS_Send(msg);
	Set_UART0_String(msg);
	
	
}
void Init_GPS(void)
{
	
	Init_UART0();
	Init_LCD();
	Set_LCD_String("Loading GPS Data");
	Delay(2000000);
	//Set_UART0_String("hi");
}




void GPS_App(void)
{

	
	char loc_var=0;
	if(Rxd_GPS()== '$')
	{
		for(i=0;i<=4;i++)
		{
			gps_rmc[i] = Rxd_GPS();
		}
		i=0;
		
		if((strcmp("GPRMC",gps_rmc)==0))
		{
			do
			{

				loc_var=Rxd_GPS();
				gps_rmc_data[i] = loc_var;
				 i++;
					
			}while(i<=50);
			Set_UART0_String("HELLO");
		}
	}
}

char *get_gps_time(void)
{
	unsigned char time_loop1=0;
	
	if(gps_rmc_data[13]=='A')
	{
		for(time_loop1=0;time_loop1<=5;time_loop1++)
		{
				if(time_loop1 ==2)
				{
						*time_adj=':';
							time_adj++;
				}
				else if(time_loop1 ==4)
				{
						*time_adj = ':';
						time_adj++;
				}
				
				*time_adj  = gps_rmc_data[time_loop1+1];
				time_adj++;	
		}
		strcat(get_time,time_adj);
	
	}
	return(get_time);
}

void display_gps_time(void)
{
		unsigned char time_loop=0;	
		Set_LCD_Command(0x01);
		Set_LCD_String("     GPS TIME");
	if(gps_rmc_data[13]=='A')
	{
		Set_LCD_Command(0xC4);
		for(time_loop=0;time_loop<=5;time_loop++)
	{
		
			if(time_loop ==2)
				Set_LCD_Char(':');
		else if(time_loop ==4)
				Set_LCD_Char(':');
		
		Set_LCD_Char(gps_rmc_data[time_loop+1]);
	
	}
	}
	
}

char *get_gps_codinates(void)
{
	unsigned char cod_loop1=0;
	
		if(gps_rmc_data[13]=='A')
		{
			for(cod_loop1=0;cod_loop1<=21;cod_loop1++)
			{
				if(cod_loop1 != 4 && cod_loop1 != 10 && cod_loop1 != 11 && cod_loop1 != 18)
				{
					if(cod_loop1 ==2)
					{
								*sms_cod = '.';
								 sms_cod++;
					}
					else if(cod_loop1 ==15)
					{
							*sms_cod = '.';
							 sms_cod++;
					}
					*sms_cod = gps_rmc_data[cod_loop1+15];
					 sms_cod++;						
			}
		}
		
	}
		return(sms_cod);
}


void display_gps_codinates(void)
{
	unsigned char cod_loop=0;	
		Set_LCD_Command(0x01);
		Set_LCD_String("GPS Codinates");
	if(gps_rmc_data[13]=='A')
	{
		Set_LCD_Command(0xC0);
		for(cod_loop=0;cod_loop<=24;cod_loop++)
	{
		if(cod_loop != 5 && cod_loop != 18)
		{
			Set_LCD_Char(gps_rmc_data[cod_loop+15]);
				if(cod_loop ==2)
						Set_LCD_Char(',');
				else if(cod_loop ==14)
						Set_LCD_Char(',');
		}
	}
	}
	
}





char Rxd_GPS(void)
{
	char GPS_Data;
	while(!(U0LSR & (1<<0)));
	GPS_Data = Get_UART0_Data();
	return(GPS_Data); 
	
}



