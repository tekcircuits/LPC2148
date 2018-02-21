

/* ********        Program for KEYPAD      ******** */
#include<global.h>
#include<lpc2148.h>
#include<pcb.h>
#include<delay.h>
#include<keypad.h>



#define R1 (1<<23)
#define R2 (1<<22)
#define R3 (1<<21)
#define R4 (1<<20)


#define C1 Is_Bit_Clr(IO0PIN,BIT19)
#define C2 Is_Bit_Clr(IO0PIN,BIT18)
#define C3 Is_Bit_Clr(IO0PIN,BIT17)

#define GATE = P0^7;

#define Set_R1() IO0CLR |= R1
#define Set_R2() IO0CLR |= R2
#define Set_R3() IO0CLR |= R3 
#define Set_R4() IO0CLR |= R4 

#define Set_All_Zero() IO0SET |= (R1 | R2 | R3 | R4 )

void Init_KEYPAD(void)
{
	
	IO0DIR |= (R1 | R2 | R3 | R4 );
	IO0DIR &= ~((1<<19) | (1<<18) | (1<<17));
}

unsigned char Get_keypad_Value(void)
{
	char i=0;
	if(i==0)
	{
		Set_All_Zero();
		Set_R1();
		if(C1)
			{
					while(C1);
					i='1';
			}
		else if(C2)
			{
				while(C2);
				i='2';
			}
		else if(C3)
			{
				while(C3);
				i='3';
			}

		Set_All_Zero();
		Set_R2();
		if(C1)
			{
				while(C1);
				i='4';
			}
		else if(C2)
		{
			while(C2);
			i='5';
		}
		else if(C3)
		{
			while(C3);
			i='6';
		}
	
		Set_All_Zero();
		Set_R3();
		if(C1)
	{
		while(C1);
		i='7';
	}
	else if(C2)
	{
		while(C2);
		i='8';
	}
		else if(C3)
	{
		while(C3);
		i='9';
	}
	
	Set_All_Zero();
	Set_R4();
		if(C1)
	{
		while(C1);
		i='*';
	}
	else if(C2)
	{
		while(C2);
		i='0';
	}
		else if(C3)
	{
		while(C3);
		i='#';
	}
	
	}
	return i;
}

unsigned char compare_pass(char pswd[])
{
	char pass[4] = "1234";


	unsigned char a=0, status = 0;
	for(a=0; a<=4; a++)
	{
		if(pass[a] != pswd[a])
			{
				status = 1;
			}
	}

	return(status);
}





