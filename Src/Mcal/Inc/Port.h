/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Remon Gerges
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Standard types */
#include "Std_Types.h"


/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

#include "Common_Macros.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Description: Data type for the symbolic name of a port pin */
typedef uint8 Port_PinType;

/* Description: Data type for the symbolic name of a port pin */
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Port Pin Level value from Port pin list */
typedef enum
{
	PORT_PIN_LEVEL_LOW,
	PORT_PIN_LEVEL_HIGH
}Port_PinLevelValue;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
	OFF,PULL_UP,PULL_DOWN
}Port_InternalAttach;

/* Description: Enum to hold PIN mode */
typedef enum
{
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_ALT1,
	PORT_PIN_MODE_ALT2,
	PORT_PIN_MODE_ALT3,
	PORT_PIN_MODE_ALT4,
	PORT_PIN_MODE_ALT5,
	PORT_PIN_MODE_ALT6,
	PORT_PIN_MODE_ALT7,
	PORT_PIN_MODE_ALT8,
	PORT_PIN_MODE_ALT9,
	PORT_PIN_MODE_DIO,
}Port_PinInitialMode;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *  3. the direction of pin --> INPUT or OUTPUT
 *  4. the internal resistor --> Disable, Pull up or Pull down
 *  5. initial port pin value (high, low)
 *  6. initial port pin mode  (ADC, DIO, ..)
 *  7. pin direction changeable (true, false)
 *  8. pin mode changeable (true, false)
 */
typedef struct 
{
	uint8 port_num;
	uint8 pin_num;
	Port_PinDirectionType direction;
	Port_InternalAttach resistor;
	uint8 initial_value;
	Port_PinInitialMode initial_mode;
	uint8 pin_dir_changeable;
	uint8 pin_mode_changeable;
}Port_ConfigPin;

typedef struct
{
	Port_ConfigPin Pin[PORT_CONFIGURED_PINS];    /*array of Port_ConfigPin*/
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the Port Driver module.
 ************************************************************************************/

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Post build structure used with Port_Init API */
extern const Port_ConfigType Port_PinConfig;


#endif /* PORT_H */
