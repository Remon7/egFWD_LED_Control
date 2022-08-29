 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Remon Gerges Hakim
 ******************************************************************************/

#ifndef INTCTRL_H
#define INTCTRL_H

/* Enable IRQ interrupts by clearing I-bit in PRIMASK register using assembly. */
#define Enable_Exceptions()	__asm("CPSIE I")

/* Disable IRQ interrupts by seting I-bit in PRIMASK register using assembly. */
#define Disable_Exceptions()	__asm("CPSID I")

#define INTA_PRIORITY_MASK		0XFFFFFF1F /* 5-7 Bits */
#define INTB_PRIORITY_MASK		0XFFFF1FFF /* 13-15 Bits */
#define INTC_PRIORITY_MASK		0XFF1FFFFF /* 21-23 Bits */
#define INTD_PRIORITY_MASK		0X1FFFFFFF /* 29-31 Bits */

#define INTA_PRIORITY_POSITION		5
#define INTB_PRIORITY_POSITION		13
#define INTC_PRIORITY_POSITION		21
#define INTD_PRIORITY_POSITION		29

#include "IntCtrl_Types.h"
#include "IntCtrl_Reg.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


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
void IntCtrl_init(const IntCtrl_ConfigType * ConfigPtr);



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Post build structure used with Port_Init API */
extern const IntCtrl_ConfigType IntCtrl_Config;

#endif
