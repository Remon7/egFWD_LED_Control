 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_PBcfg.c
 *
 * Description: source file for TM4C123GH6PM Microcontroller - IntCtrl Driver post build Configuration
 *
 * Author: Remon Gerges Hakim
 ******************************************************************************/

#include "IntCtrl_Types.h"

/* post build structure that will be used in the IntCtrl function */
const IntCtrl_ConfigType IntCtrl_Config = {
		INTCTRL_CONF_CHANNEL_TYPE ,INTCTRL_CONF_GROUP_PRI ,INTCTRL_CONF_SUB_GROUP_PRI
};
