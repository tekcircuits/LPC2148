#include <app.h>

char moisture, temperature, humidity, rain, water_level, motor_status, motor_control, switch_status, sms, switch_status; 

u32_t task_counter = 0, water_update, rain_update;
int main(void)
{
	char cnt = 0, status = 0;
	
	init_App();

	while(1)
	{
		

		moisture = get_SoilMoisture();
		temperature = get_Temperature();
		water_level = get_WaterLevel();
		rain = get_RainStatus();
		humidity = get_Humidity();
		motor_status = get_MotorStatus();
		motor_control = get_MotorControlStatus();
		
	if(task_counter > 50000){
			
		if(cnt == 0){
			
			Set_LCD_Command(0X01);
			Set_LCD_Command(0X80);
			Set_LCD_String("SMoist Temp WLvl");
			cnt = 1;	
		}

		Set_LCD_Command(0XC0);
		if(moisture == 1) Set_LCD_String("Wet ");
		else Set_LCD_String("Noml");
		
		Set_LCD_String("   ");Set_LCD_Num_3_Digit(temperature);Set_LCD_String("C  ");
		set_LCD_Num_2_Digit(water_level);
		
		update_ADC_Channels();
		rain_update ++;
		water_update ++;
			
		if(sms == 1)
			{
				sms = 0;cnt = 0;
				send_SmartAgriSMS(1, moisture, temperature, humidity, rain, water_level, motor_status);
				
			}
		else if(sms == 2){
			
			sms = 1;
			send_SmartAgriSMS(2, moisture, temperature, humidity, rain, water_level, motor_status);
				
			}
			else if(sms == 3){
				
				sms = 1;
				send_SmartAgriSMS(3, moisture, temperature, humidity, rain, water_level, motor_status);
			}	
			else if(sms == 4){
				
				sms = 1;
				send_SmartAgriSMS(4, moisture, temperature, humidity, rain, water_level, motor_status);
			}	
			else if(sms == 5){
				
				sms = 1;
				send_SmartAgriSMS(5, moisture, temperature, humidity, rain, water_level, motor_status);
			}	
			
		
		if(cnt == 1)
		{
			if( temperature > 0 && temperature <= 18)
			{
		
			}
			else if( temperature > 18 && temperature < 25)
			{
				
			}
		
			if( moisture < 100)
			{
				
			}
			
			
			if(water_level == 2 && motor_status == 1)
			{
				set_MotorOFF(MOTOR_OFF_WATERFULL);
				sms = 1;
				
			}
			else if(water_level == 2 && motor_control == 2){
				
					motor_control = 0;
					sms = 2;	
			}
		/*	else if(water_level == 2 && water_update > 2000){
				
				sms = 5;
				motor_control = 0;	
			}
			else if(water_level == 2) water_update++;
			else water_update = 0;*/
			
			if(rain == 1 && motor_status == 1)
			{
				set_MotorOFF(MOTOR_OFF_RAIN);
				sms = 1;
				motor_control = 0;
			}
			else if(rain == 1 && motor_control == 2)
			{
				sms = 3;
				motor_control = 0;
			}
			/*else if(rain == 1 && rain_update > 2000){
				
				sms = 4;
				motor_control = 0;
			}
			else if(rain == 1) rain_update++;
			else rain_update = 0;*/
			
			if(motor_control == 1 && motor_status == 0)
			{
				set_MotorON(MOTOR_ON_BYSWITCH);
				
				sms = 1;
			}
			else if(motor_control == 2 && motor_status == 0)
			{
				set_MotorON(MOTOR_ON_SMS);
				sms = 1;
			}
			else if(motor_control == 3 && motor_status == 1)
			{
				
				set_MotorOFF(MOTOR_OFF_SMS);
				sms = 1;
			}
			else if(motor_control == 1 && motor_status == 1)
			{
				set_MotorOFF(MOTOR_OFF_BYSWITCH);
				sms = 1;
			}
	
		}
		task_counter = 0;
	}task_counter++;
}
}
				
			
			
			
				
				
