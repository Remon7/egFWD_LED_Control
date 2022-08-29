 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_Types.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver Types
 *
 * Author: Remon Gerges Hakim
 ******************************************************************************/

#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

#include "Std_Types.h"
#include "Common_Macros.h"

/* IntCtrl Pre-Compile Configuration Header file */
#include "IntCtrl_Cfg.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Type definition for interrupt types used */
typedef enum
{
	SYSTIC =15, GPIO_PORT_A, GPIO_PORT_B, GPIO_PORT_C, GPIO_PORT_D, GPIO_PORT_E /*and all the possible interrupts */
}IntCtrl_InterruptType;

typedef struct
{
	/*variable of type IntCtrl_InterruptType contains the type of the interrupt */
	IntCtrl_InterruptType PeripheralType;
	/*variable contains priority of the group */
	uint8 InterruptGroupPriority;
	/*variable contains priority of the Sub-group */
	uint8 InterruptSubGroupPriority;
}IntCtrl_ConfigChnannel;

typedef struct
{
	IntCtrl_ConfigChnannel channel[INTERRUPT_CONFIGURED_CHANNEL];  /* array of IntCtrl_ConfigChnannel structures */
}IntCtrl_ConfigType;



#endif
