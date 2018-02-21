#ifndef _TRI_COLOUR_LED_H_
#define _TRI_COLOUR_LED_H_

typedef enum
{
	GREEN_LED,
	RED_LED,
	AMBER_LED,
	TRI_LED_OFF
}t_led_option_t;

/* Function Prototypes */
void Init_TRI_LED_IO(void);
void Set_Tri_LED(t_led_option_t led_option);

#endif
