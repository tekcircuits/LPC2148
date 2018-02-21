/*****************************************************************************
 *   irq.c: Interrupt handler C file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2006, MICROBIT Embedded Solutions
 *   All rights reserved.
 *
 *   History
 *   20012.12.09  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#include <global.h>
#include <LPC2148.h>		/* LPC21XX Peripheral Registers	*/
#include <vic.h>

#define VIC_BASE_ADDR	0xFFFFF000

/******************************************************************************
** Function name:		DefaultVICHandler
**
** Descriptions:		Default VIC interrupt handler.
**				This handler is set to deal with spurious 
**				interrupt.
**				If the IRQ service routine reads the VIC
**				address register, and no IRQ slot responses
**				as described above, this address is returned.
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void DefaultVICHandler (void) __irq
{
    /* if the IRQ is not installed into the VIC, and interrupt occurs, the
    default interrupt VIC address will be used. This could happen in a race 
    condition. For debugging, use this endless loop to trace back. */
    /* For more details, see Philips appnote AN10414 */
    VICVectAddr = 0;		/* Acknowledge Interrupt */ 
    while ( 1 );
}

/* Initialize the interrupt controller */
/******************************************************************************
** Function name:		Init_VIC
**
** Descriptions:		Initialize VIC interrupt controller.
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void Init_VIC(void) 
{
    u32_t vic_index = 0;
    u32_t *vect_addr, *vect_cntl;
   	
    /* initialize VIC*/
    VICIntEnClr = 0xffffffff;
    VICVectAddr = 0;
    VICIntSelect = 0;

    /* set all the vector and vector control register to 0 */
    for ( vic_index = 0; vic_index < VIC_SIZE; vic_index++ )
    {
	vect_addr = (u32_t *)(VIC_BASE_ADDR + VECT_ADDR_INDEX + vic_index*4);
	vect_cntl = (u32_t *)(VIC_BASE_ADDR + VECT_CNTL_INDEX + vic_index*4);
	*vect_addr = 0;	
	*vect_cntl = 0;
    }

    /* Install the default VIC handler here */
    VICDefVectAddr = (u32_t)DefaultVICHandler;   
    return;
}

/******************************************************************************
** Function name:		Install_IRQ
**
** Descriptions:		Install interrupt handler
**				The max VIC size is 16, but, there are 32 interrupt
**				request inputs. Not all of them can be installed into
**				VIC table at the same time.
**				The order of the interrupt request installation is
**				first come first serve.
** parameters:			Interrupt number and interrupt handler address
** Returned value:		true or false, when the table is full, return false
** 
******************************************************************************/
bool_t Install_IRQ( u32_t int_num, void *ISR_addr )
{
    u32_t vic_index = 0;
    u32_t *vect_addr, *vect_cntl;
      
    VICIntEnClr = 1 << int_num;	/* Disable Interrupt */
    
    for ( vic_index = 0; vic_index < VIC_SIZE; vic_index++ )
    {
	/* find first un-assigned VIC address for the handler */

	vect_addr = (u32_t *)(VIC_BASE_ADDR + VECT_ADDR_INDEX + vic_index*4);
	vect_cntl = (u32_t *)(VIC_BASE_ADDR + VECT_CNTL_INDEX + vic_index*4);
	if ( *vect_addr == (u32_t)NULL )
	{
	    *vect_addr = (u32_t)ISR_addr;	/* set interrupt vector */
	    *vect_cntl = (u32_t)(IRQ_SLOT_EN | int_num);
	    break;
	}
    }
    if ( vic_index == VIC_SIZE )
    {
	return( FALSE );		/* fatal error, can't find empty vector slot */
    }
    VICIntEnable = 1 << int_num;	/* Enable Interrupt */
    return( TRUE );
}

/******************************************************************************
** Function name:		Uninstall_IRQ
**
** Descriptions:		Uninstall interrupt handler
**				Find the interrupt handler installed in the VIC
**				based on the interrupt number, set the location
**				back to NULL to uninstall it.
** parameters:			Interrupt number
** Returned value:		true or false, when the interrupt number is not found, 
**				return false
** 
******************************************************************************/
bool_t Uninstall_IRQ( u32_t int_num )
{
    u32_t vic_index = 0;
    u32_t *vect_addr, *vect_cntl;
      
    VICIntEnClr = 1 << int_num;	/* Disable Interrupt */
    
    for ( vic_index = 0; vic_index < VIC_SIZE; vic_index++ )
    {
	/* find first un-assigned VIC address for the handler */
	vect_addr = (u32_t *)(VIC_BASE_ADDR + VECT_ADDR_INDEX + vic_index*4);
	vect_cntl = (u32_t *)(VIC_BASE_ADDR + VECT_CNTL_INDEX + vic_index*4);
	if ( (*vect_cntl & ~IRQ_SLOT_EN ) == int_num )
	{
	    *vect_addr = (u32_t)NULL;	/* clear the VIC entry in the VIC table */
	    *vect_cntl &= ~IRQ_SLOT_EN;	/* disable SLOT_EN bit */	
	    break;
	}
    }
    if ( vic_index == VIC_SIZE )
    {
	return( FALSE );		/* fatal error, can't find interrupt number 
					in vector slot */
    }
    VICIntEnable = 1 << int_num;	/* Enable Interrupt */
    return( TRUE );
}

/******************************************************************************
**                            End Of File
******************************************************************************/
