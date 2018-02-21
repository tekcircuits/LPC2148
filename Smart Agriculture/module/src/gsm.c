#include<app.h>


char gsm_data, sms_read = 0, gsm_status = 0, gsm_control;

char Init_GSM(void)
{	
	Set_UART1_String("AT\r\n");Delay(500);
	
	while(Rxd_GSM()!='O');
	while(Rxd_GSM()!='K');
	Set_UART0_String("AT is OK \r\n");
	Set_UART1_String("ATE0\r\n\r\n");Delay(500);
	
	while(Rxd_GSM()!='O');
	while(Rxd_GSM()!='K');
	Set_UART0_String("ATE0 is OK \r\n");
	
	Set_UART1_String("AT+CPIN?\r\n\r\n");Delay(500);
	
	while(Rxd_GSM()!='R');
	while(Rxd_GSM()!='E');
	while(Rxd_GSM()!='A');
	while(Rxd_GSM()!='D');
	while(Rxd_GSM()!='Y');
	
	Set_UART0_String("AT+CPIN? is OK \r\n");
	
	Set_UART1_String("AT+CMGF=1\r\n\r\n");Delay(500);
	
	while(Rxd_GSM()!='O');
	while(Rxd_GSM()!='K');
	
	Set_UART0_String("AT+CMGF=1 is Ok\r\n");
	
	Set_UART1_String("AT+CMGD=1\r\n");
	while(Rxd_GSM()!='O');
	while(Rxd_GSM()!='K');
	
	Set_UART0_String("AT+CMGD=1 is Ok\r\n");

	
	Delay(20000); // Checking delay for 2 sec
	return 1;
}

char GSM_SMSCheck(void){
	
	char i = 0;
	if(Rxd_GSM() == '+'){
		Set_UART0_String("New SMS Received\t");
		
		while(i < 100){
				Rxd_GSM(); i++; // to clear GSM Buffer
		}
		
		return 1;
	}

	return 0;

}
char get_GSMMotorControlStatus(void){
	char sms_data[160] = {'\0'};
	char i=0, var = '\0';  
	u32_t gsm_timeout = 0, gsm_timeout1 = 0;
	
	if(sms_read == 0){
		
		if(GSM_SMSCheck()){
			sms_read = 1; Delay(100);
		}
	}
		if(sms_read == 1){
			
			Set_UART1_String("AT+CMGR=1\r\n");
			
			var = Rxd_GSM(); 
			gsm_status = 1;
			while(var != '$')
			{
				var = Rxd_GSM();
				
				
				if(var != '\0'){
					sms_data[i] = var;
					i++;
				}
				
				gsm_timeout++;
				
				if(gsm_timeout > 250000){
					gsm_status = 0;
					break;
					
				}
			}
			
			if(gsm_status == 1){
				
			Set_UART0_String(sms_data);	
			
			sms_read =  0;
			gsm_control = 	sms_data[i-2];
			Set_UART0_Data(gsm_control);
			
			Set_UART1_String("AT+CMGD=1\r");
			while(Rxd_GSM()!='O');
			while(Rxd_GSM()!='K');
			}
			else{
				Set_UART0_String("\r GSM Time out");
				
				gsm_timeout1++;

				if(gsm_timeout1 > 100){
					sms_read = 0;
					Set_LCD_Command(0x01);
					Set_LCD_Command(0x80);
					Set_LCD_String("SMS-R TIME OUT");
				}
				return 0;
			}				
			
			
		}
		
		if(gsm_control == '1') return 1;
		else if(gsm_control == '2') return 2;
		else return 3;
			
		
	}

	void GSM_ClearControlFlag(void){
		
		gsm_control = 0;
	
	}
	
	//Set_UART1_String("AT+CMGR=1\r");
	//Set_UART1_Data(0x0D);
			
		//gsm_data = Rxd_GSM();
		//sms_data[i] = var; i++;
		//if(i==99)break; if(var == '\r' || var == '\n') break;

	//	Set_UART0_String(sms_data);
		//if(sms_data[i-2] == '*' && sms_data[1] == '1') return 1;
		//else if(sms_data[0] == '*' && sms_data[1] == '2') return 2;
		//else return 0;
	
	//Set_UART1_String("AT+CMGD=1\r");
	//while(Rxd_GSM()!='O');
	//while(Rxd_GSM()!='K');

		

void SMS_Send(char* sms_to, char *gsm_message)
{

	char sms_cmd[50] = {'\0'};
	
	
	strcat(sms_cmd, "AT+CMGS=\"");
	strcat(sms_cmd, sms_to);
	strcat(sms_cmd, "\"");
	
	Set_UART0_String(sms_cmd);
	Set_UART0_String(gsm_message);
	
	Set_UART1_String(sms_cmd);
	
	Delay(500);
	
	Set_UART1_Data(0x0D);
	while(Rxd_GSM()!='>');
	Set_UART1_String(gsm_message);
	Set_UART1_Data(0x0D);
	Set_UART1_Data(0x1A);Delay(2000);
	while(Rxd_GSM()!='O');
	while(Rxd_GSM()!='K');
	Set_LCD_Command(0x01);
	Set_LCD_Command(0x80);
	
	Set_LCD_String("SMS Alert Sent");
}

char GSM_Command(char *command){
	
	Set_UART1_String(command);
	Set_UART1_Data(0x0D);
	
	
}


char Rxd_GSM(void){
		
	if(U1LSR & (1<<0))
		return Get_UART1_Data();
		
	return '\0'; 
	
}



