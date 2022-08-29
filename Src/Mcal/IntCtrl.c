/******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.c
 *
 * Description: source file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Remon Gerges Hakim
 ******************************************************************************/

#include "IntCtrl.h"



/************************************************************************************
* Service Name: IntCtrl_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the IntCtrl module.
************************************************************************************/
void IntCtrl_init(const IntCtrl_ConfigType * ConfigPtr)
{

	Enable_Exceptions();
	/* a guard to reset APINT and prevent accidental writes */
	APINT = 0XFA050000;
	/*to put 0x04 in the PRIGROUP bits , 0x04 means 8 group priorities and 1 sub-group priority "0" */
	APINT = (APINT & 0XFFFFF8FF) | (0X04 << 8) ;

	uint8 id;
	for(id=0; id<INTERRUPT_CONFIGURED_CHANNEL; id++)
	{
		if(ConfigPtr->channel[id].PeripheralType == SYSTIC)
		{
			/*using priority mask and position we can set the group priority to the systic bits in nvic_sys_pri3_reg
			 * no need to enable NVIC interrupt for the systic*/
			((NVIC_SYSTEM_PRI3_REG & INTD_PRIORITY_MASK) | (ConfigPtr->channel[id].InterruptGroupPriority << INTD_PRIORITY_POSITION)) ;
		}
		else if(ConfigPtr->channel[id].PeripheralType == GPIO_PORT_A)
		{
			/*using priority mask and position we can set the priority by setting INTA bits 5-7*/
			((NVIC_PRI0_REG & INTA_PRIORITY_MASK) | (ConfigPtr->channel[id].InterruptGroupPriority << INTA_PRIORITY_POSITION)) ;
			NVIC_EN0_REG         |= 0x00000001;   /* Enable NVIC Interrupt for GPIO PORT-A by setting bit  0 in EN0 Register */
		}
		else if(ConfigPtr->channel[id].PeripheralType == GPIO_PORT_B)
		{
			/*using priority mask and position we can set the priority by setting INTB bits 13-15*/
			((NVIC_PRI0_REG & INTB_PRIORITY_MASK) | (ConfigPtr->channel[id].InterruptGroupPriority << INTB_PRIORITY_POSITION)) ;
			NVIC_EN0_REG         |= 0x00000002;   /* Enable NVIC Interrupt for GPIO PORT-B by setting bit 1 in EN0 Register */
		}
		else if(ConfigPtr->channel[id].PeripheralType == GPIO_PORT_C)
		{
			/*using priority mask and position we can set the priority by setting INTA bits 21-23*/
			((NVIC_PRI0_REG & INTC_PRIORITY_MASK) | (ConfigPtr->channel[id].InterruptGroupPriority << INTC_PRIORITY_POSITION)) ;
			NVIC_EN0_REG         |= 0x00000004;   /* Enable NVIC Interrupt for GPIO PORT-C by setting bit  2 in EN0 Register */
		}
		else if(ConfigPtr->channel[id].PeripheralType == GPIO_PORT_D)
		{
			/*using priority mask and position we can set the priority by setting INTA bits 29-31*/
			((NVIC_PRI0_REG & INTD_PRIORITY_MASK) | (ConfigPtr->channel[id].InterruptGroupPriority << INTD_PRIORITY_POSITION)) ;
			NVIC_EN0_REG         |= 0x00000008;   /* Enable NVIC Interrupt for GPIO PORT-D by setting bit  3 in EN0 Register */
		}
		else if(ConfigPtr->channel[id].PeripheralType == GPIO_PORT_E)
		{
			/*using priority mask and position we can set the priority by setting INTA bits 5-7*/
			((NVIC_PRI1_REG & INTA_PRIORITY_MASK) | (ConfigPtr->channel[id].InterruptGroupPriority << INTA_PRIORITY_POSITION)) ;
			NVIC_EN0_REG         |= 0x00000010;   /* Enable NVIC Interrupt for GPIO PORT-E by setting bit 4 in EN0 Register */
		}
		else
		{
			/* do nothing ....... */
		}
	}

}
