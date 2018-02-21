#ifndef __I2C0_H__
#define __I2C0_H__

void Init_I2C0(void);
u8_t Start_I2C0(u8_t slave_addr);
u8_t Set_I2C0_DATA(u8_t DAT);
void Set_I2C0_string(u8_t *ptr);
void STOP_I2C0(void);
u8_t Get_I2C0_DATA(void);
u8_t Get_I2C0_DATA_Last(void);
void Set_I2C0_Num_4_Digit(u16_t num);
void set_I2C0_Num_2_Digit(u16_t num);
void Set_I2C0_Num_3_Digit(u16_t num);

#endif
