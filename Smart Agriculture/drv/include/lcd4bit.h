
#include<global.h>
#ifndef _LCD4BIT_H
#define _LCD4BIT_H

/* Few of the LCD Pre-defined Commands */
#define LCD_8BIT	0x38
#define LCD_4BIT	0x28
#define LCD_CLR		0x01
#define LCD_ON		0x0C
#define LCD_ROW1	0x80
#define LCD_ROW2	0xC0

/* LCD Core Device Driver Function Prototypes */
void Init_LCD(void);
void Set_LCD_Command(u8_t);
void Set_LCD_Char(u8_t);
void Set_LCD_String(char *);
void set_LCD_Num_2_Digit(u16_t num); // This functions displays 000 to 999
void Set_LCD_Num_3_Digit(u32_t num);
void Set_LCD_Num_4_Digit(u32_t num);

#endif

