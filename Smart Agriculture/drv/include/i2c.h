#ifndef __I2C_H_
#define __I2C_H_

void Init_I2C(void);
s32_t Set_I2C_Start(u32_t addr);
s32_t Set_I2C_Write_Byte(u8_t i2c_data_byte);
s32_t Set_I2C_Write_Bytes(u8_t *buf, u16_t i2c_Byte_ctr);
s32_t Get_I2C_Read_Byte(void);
s32_t Get_I2C_Read_Byte_Last(void);
void Set_I2C_Stop(void);

#endif

