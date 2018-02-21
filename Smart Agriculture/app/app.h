#ifndef _APP_H
#define _APP_H

#include <stdio.h>
#include<global.h>
#include<lpc2148.h>
#include<pll0.h>
#include<pcb.h>
#include<pconp.h>
#include<adc.h>
#include<lcd.h>
#include<buz.h>
#include<delay.h>
#include<gsm.h>
#include<gps.h>
#include<app.h>
#include<string.h>
#include<uart0.h>
#include<string.h>
#include <uart1.h>

#define LPC21xx_RELAY_CONTROL_PIN 2

#define LPC21xx_TEMPERATURE_SENSOR_PIN 2
#define LPC21xx_MOISTIURE_SENSOR_PIN 2

#define LPC21xx_RAIN_SENSOR_PIN 2
#define LPC21xx_WATER_SENSOR_PIN1 2
#define LPC21xx_WATER_SENSOR_PIN2 2

#define MOTOR_ON_SMS 1
#define MOTOR_ON_BYSWITCH 2

#define MOTOR_OFF_SMS 1
#define MOTOR_OFF_RAIN 2
#define MOTOR_OFF_WATERFULL 3
#define MOTOR_OFF_BYSWITCH 4


void init_App(void);
void init_Relays(void);
u16_t get_SoilMoisture(void);
u16_t get_Humidity(void);
u16_t get_RainStatus(void);
u16_t get_Temperature(void);
u16_t get_WaterLevel(void);
u16_t get_MotorStatus(void);
void set_MotorON(s8_t res);
void set_MotorOFF(s8_t res);
void set_BuzzerON(void);
void set_BuzzerOFF(void);
u16_t get_SwitchStatus(void);
u16_t get_MotorControlStatus(void);
void send_SmartAgriSMS(u8_t sms_code, u16_t moisture, u16_t temperature,u16_t humidity, u16_t rain, u16_t water_level, u16_t motor_status);

#endif










