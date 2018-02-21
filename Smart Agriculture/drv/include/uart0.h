#ifndef _UART0_H
#define _UART0_H

void Init_UART0(void);
void Set_UART0_Data(u8_t);
u8_t Get_UART0_Data(void);
void Set_UART0_String(char *);
void set_UART0_2_Num(u16_t num);
void Set_UART0_4_Num(u32_t num);

#endif // _UART0_H
         

