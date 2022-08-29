#include "Led.h"
#include "Gpt.h"
#include "Dio.h"
#include "Port.h"
#include "IntCtrl.h"

/* Global variable to indicate the timer tick */
static uint8 g_Time_Tick_Flag = 0;

void TimerTick(void)
{
    /* Set the flag to 1 to indicate a new tick */
    g_Time_Tick_Flag = 1;
}

/*********************************************************************************************/

int main(void)
{
	
	/* Initialize Dio Driver */
    Dio_Init(&Dio_Configuration);

    /* Initialize Port Driver */
    Port_Init(&Port_PinConfig);
	
		/* Initialize IntCtrl Driver */
		IntCtrl_init(&IntCtrl_Config);
	
		/* 
     * Set the Call Back function to call TimerTick to be called every new Tick
     */
    SysTick_SetCallBack(TimerTick);

    /* Start SysTickTimer to generate interrupt every 1s */
    SysTick_Start(1000);
	
	while(1)
	{
		if(g_Time_Tick_Flag == 1)
		{
			LED_toggle();
			g_Time_Tick_Flag = 0;
		}
	}
}