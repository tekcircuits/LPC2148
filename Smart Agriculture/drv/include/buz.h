#ifndef _BUZ_H_
#define _BUZ_H_

typedef enum
{
	BUZ_OFF,
	BUZ_ON,
	BUZ_FLASH,
}buz_option_t;

/* Function Prototypes */
void Init_Buz_IO(void);
void Set_Buz(buz_option_t buz_option);

#endif
