

#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef unsigned char u8_t;
typedef signed char s8_t;
typedef unsigned short int u16_t;
typedef signed short int  s16_t;
//typedef unsigned int u32_t;
typedef signed int s32_t;

#ifndef NULL
#define NULL    ((void *)0)
#endif

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (1)
#endif

/* Bit Handler Defines */
#define	BIT0	0
#define	BIT1	1
#define	BIT2	2
#define	BIT3	3
#define	BIT4	4
#define	BIT5	5
#define	BIT6	6
#define	BIT7	7

#define	BIT8	8
#define	BIT9	9
#define	BIT10	10
#define	BIT11	11
#define	BIT12	12
#define	BIT13	13
#define	BIT14	14
#define	BIT15	15

#define	BIT16	16
#define	BIT17	17
#define	BIT18	18
#define	BIT19	19
#define	BIT20	20
#define	BIT21	21
#define	BIT22	22
#define	BIT23	23

#define	BIT24	24
#define	BIT25	25
#define	BIT26	26
#define	BIT27	27
#define	BIT28	28
#define	BIT29	29
#define	BIT30	30
#define	BIT31	31

/* Generic Write Bit Macroes */
#define Set_Bit(var,bPos)		var |=  (1<<bPos)
#define Clr_Bit(var,bPos)		var &= ~(1<<bPos)
#define Toggle_Bit(var,bPos)  	var ^= (1<<bPos)

/* Generic Read Bit Macroes */
#define Is_Bit_Set(var,bPos)   (var & (1<<bPos))
#define Is_Bit_Clr(var,bPos)  !(var & (1<<bPos))

#endif  // _GLOBAL_H 
