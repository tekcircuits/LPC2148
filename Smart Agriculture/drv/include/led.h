#ifndef _LED_H_
#define _LED_H_

typedef enum
{
	LED_OFF,
	LED_ON,
	LED_FLASH
}led_option_t;

/* Function Prototypes */
void Config_LED_Pin(void);
void Set_LED(led_option_t led_option);

#endif
