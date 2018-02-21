#ifndef __SPI_H
#define __SPI_H



#define SPI_SSEL0_BIT	(1<<BIT7) 

#define SPI0_Select_Slave()   IO0CLR = SPI_SSEL0_BIT;
#define SPI0_Deselect_Slave() IO0SET = SPI_SSEL0_BIT;

void Init_SPI0( void );
u8_t SPI_Transfer_Data(u8_t spi_data);

#endif

