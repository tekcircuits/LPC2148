#include <app.h>

//char sms_buffer[160];

void init_App(void){
	u8_t cnt = 0;
	
	Power_Off_Peripherals();Init_PLL0();
		
	Init_LCD();
	Init_ADC0();
	init_Relays();
	Init_UART1();
	Init_UART0();
	/* GPIO Input device */
	Set_UART0_String("Welcome to Smart Agriculture\r\n");
	/* Motor Switch input */
	PINSEL0.P0_13 = P0_13_GPIO;
	Clr_Bit(IO0DIR,BIT13); // P0.14 configured as Input
	
	/*GPIO Input Water Level sensor pins init*/
	PINSEL0.P0_2 = P0_2_GPIO; // pin mode
	PINSEL0.P0_3 = P0_3_GPIO; // pin mode
	
	
	Clr_Bit(IO0DIR,BIT2); 		// Input Direction 
	Clr_Bit(IO0DIR,BIT3); 		// input Direction 
	
	/*Rain Sensor Digital input*/
	PINSEL0.P0_4 = P0_4_GPIO; // pin mode
	Clr_Bit(IO0DIR,BIT4); 		// Input Direction 
	
	/*Moisture Sensor Digital input*/
	PINSEL0.P0_5 = P0_5_GPIO; // pin mode
	Clr_Bit(IO0DIR,BIT5); 		// Input Direction 
	
	Set_LCD_String("    SMART ");
	Set_LCD_Command(0XC0);
	Set_LCD_String("  AGRICULTURE");
	Delay(200000);
	
	Set_LCD_Command(0X01);
	Set_LCD_Command(0X80);
	Set_LCD_String("Initializing GSM");
	Set_LCD_Command(0xC0);
	Set_LCD_String(".....");
	delay_ms(2000);
	
	while(!Init_GSM()){
		if(cnt < 6){
			Set_LCD_String(".");
		}
		else{
			Set_LCD_Command(0xC0);
			Set_LCD_String("       ");
			Set_LCD_Command(0xC0);
			cnt = 0;
		}
		cnt++;
	}

	Set_LCD_Command(0x01);
	Set_LCD_Command(0x80);
	Set_LCD_String("SIM Registered");
	
	
		/*9652896509-sushitha
		7013644144-hod
		8639317329-meghana
		7036103903-shruthi
		8331867491- rambabu*/
	
	SMS_Send("+919108456695","Welcome to Smart Agriculture"); // Cloudchip
	//SMS_Send("+919652896509","Welcome to Smart Agriculture"); // HOD
	SMS_Send("+917013644144","Welcome to Smart Agriculture"); // Meghana
	//SMS_Send("+917036103903","Welcome to Smart Agriculture"); // Sruthi
	//SMS_Send("+918331867491","Welcome to Smart Agriculture"); // Rambabu
}

void init_Relays(void){
	
	
	/*GPIO Output device*/
	PINSEL1.P0_16= P0_16_GPIO; // pin mode
	Set_Bit(IO0DIR,BIT16); 		// Output Direction 
	
	//Set_Bit(IO0CLR,BIT16);
	Set_Bit(IO0CLR,BIT16); Delay(200);
	
}


u16_t get_SoilMoisture(void){

	if(Is_Bit_Clr(IO0PIN, BIT5)) return 1;
	else return 0;
}

u16_t get_Humidity(void){

		return 0;
}

u16_t get_Temperature(void){

	return Get_AD01() * 0.322265625;
}

u16_t get_RainStatus(void){

	if(Is_Bit_Clr(IO0PIN, BIT4)) return 1;
	else return 0;
}

u16_t get_WaterLevel(void){

	if(Is_Bit_Clr(IO0PIN, BIT3)) return 2;
	else if(Is_Bit_Clr(IO0PIN, BIT2)) return 1;
	else return 0;
}

u16_t get_MotorStatus(void){

	if(Is_Bit_Set(IO0PIN, BIT16)) return 1;

	else return 0;
}
u16_t get_SwitchStatus(void){

	if(Is_Bit_Clr(IO0PIN, BIT13)) return 1;
	else return 0;
}

u16_t get_MotorControlStatus(void){

	if(get_SwitchStatus())return 1;
	else if(get_GSMMotorControlStatus() == 1) return 2;
	else if(get_GSMMotorControlStatus() == 2) return 3;
	else return 0;
	
}

void set_MotorON(s8_t res){
	
	Set_Bit(IO0SET ,BIT16);
	
	switch(res){
		case 1: Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is ON");
						Set_LCD_Command(0xC0);
						Set_LCD_String(" By SMS");
						break;
		case 2: Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is ON");
						Set_LCD_Command(0xC0);
						Set_LCD_String(" By Switch");
						break;
		default:
						Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is ON");
	}
	//delay_ms(20000);
}

void set_MotorOFF(s8_t res){

	Set_Bit(IO0CLR,BIT16);
	switch(res){
		case 1: Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is OFF");
						Set_LCD_Command(0xC0);
						Set_LCD_String(" By SMS");
						GSM_ClearControlFlag();
						break;
		case 2: Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is OFF");
						Set_LCD_Command(0xC0);
						Set_LCD_String("Due to Rain");
						GSM_ClearControlFlag();
						break;
		case 3: Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is OFF");
						Set_LCD_Command(0xC0);
						Set_LCD_String("Water Lvl Full");
						GSM_ClearControlFlag();
						break;
		case 4: Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is OFF");
						Set_LCD_Command(0xC0);
						Set_LCD_String("By Switch");
						GSM_ClearControlFlag();
						break;
		default:
						Set_LCD_Command(0X01);
						Set_LCD_Command(0X80);
						Set_LCD_String("Motor is OFF");
						GSM_ClearControlFlag();
	}
	//delay_ms(20000);
	
}

void set_BuzzerON(void){

}

void set_BuzzerOFF(void){


}

void send_SmartAgriSMS(u8_t sms_code, u16_t moisture, u16_t temperature,u16_t humidity, u16_t rain, u16_t water_level, u16_t motor_status){
	
			char sms_buffer[160], sms_buffer4[20];
			char *title = "SMART AGRICULTURE\n";
			char *sms_buffer2 = "Motor Cannot able to start due to Water is Full\n";
			char *sms_buffer3 = "Motor Cannot able to start due to rain\n";
			char *sms_buffer5 = "Rain Detected\n";
			char *sms_buffer6 = "Water Level is Full\n";
	
			strcpy(sms_buffer, title);
			
			Set_LCD_Command(0X01);
			Set_LCD_Command(0X80);
			Set_LCD_String("Sending SMS...");
			//delay_ms(20000);
			
			if(sms_code == 1){
				
				strcat(sms_buffer, "Motor Status: ");
				if(motor_status == 1) strcat(sms_buffer, "ON");
				else strcat(sms_buffer, "OFF");
				strcat(sms_buffer, "\n");
				
				strcat(sms_buffer, "Soil Moisture : ");
				if(moisture == 0) strcat(sms_buffer, "Dry");
				else strcat(sms_buffer, "Wet");
				strcat(sms_buffer, "\n");
				
				strcat(sms_buffer, "Water Level : ");
				if(water_level == 2) strcat(sms_buffer, "Full");
				else if(water_level == 1) strcat(sms_buffer, "Low");
				else strcat(sms_buffer, "No Water");
				strcat(sms_buffer, "\n");
				
				sprintf(sms_buffer4, "%d", rain);
				
				strcat(sms_buffer, "rain: ");
				strcat(sms_buffer, sms_buffer4);
				strcat(sms_buffer, "\n");
				
				sprintf(sms_buffer4, "%d", temperature);
				
				strcat(sms_buffer, "Temperature: ");
				strcat(sms_buffer, sms_buffer4);
				strcat(sms_buffer, "C");
				strcat(sms_buffer, "\n");
				
				strcat(sms_buffer, "Humidity: ");
				if(motor_status == 1) strcat(sms_buffer, "NA");
				else strcat(sms_buffer, "NA");
				strcat(sms_buffer, "\n");
				//GSM_ClearControlFlag();
			}
			else if(sms_code == 2){
				strcat(sms_buffer, sms_buffer2);
				GSM_ClearControlFlag();
				
			}
			else if(sms_code == 3){
				strcat(sms_buffer, sms_buffer3);
				GSM_ClearControlFlag();	
			}
			else if(sms_code == 4){
				strcat(sms_buffer, sms_buffer5);
				GSM_ClearControlFlag();
			}
				else if(sms_code == 5){
				strcat(sms_buffer, sms_buffer5);
				GSM_ClearControlFlag();	
			}
				
				SMS_Send("+919108456695",sms_buffer); // Cloudchip
				SMS_Send("+919652896509",sms_buffer); // HOD
				SMS_Send("+917013644144",sms_buffer); // Meghana
				SMS_Send("+917036103903",sms_buffer); // Sruthi
				SMS_Send("+918331867491",sms_buffer); // Rambabu
			//delay_ms(20000);
}

