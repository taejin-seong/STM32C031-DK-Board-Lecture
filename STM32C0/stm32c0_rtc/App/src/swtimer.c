/*
 * swtimer.c
 *
 *  Created on: Jun 5, 2023
 *      Author: xowls
 */


#include "swtimer.h"

#define SWTIMER_MAX_CH       8


typedef struct
{
	bool enable;
	SwtimerMode_t mode;
	uint32_t counter;
	uint32_t reload;
	void (*func)(void *argc);
	void *func_arg;

}swtimer_t;


static uint8_t swtimer_count = 0;
static swtimer_t swtimer_tbl[SWTIMER_MAX_CH];


extern TIM_HandleTypeDef htim14;


/*****************************************************************************
* Function Name : swtimerInit
* Brief         : Swtimer initialization.
* Inputs        : void
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool swtimerInit(void)
{
	for (int i = 0; i < SWTIMER_MAX_CH; i++)
	{
		swtimer_tbl[i].enable = false;
		swtimer_tbl[i].counter = 0;
		swtimer_tbl[i].func = NULL;
		swtimer_tbl[i].func_arg = NULL;
	}

	HAL_TIM_Base_Start_IT(&htim14);
	return true;
}

/*****************************************************************************
* Function Name : swtimerGetCh
* Brief         : Swtimer CH Setting.
* Inputs        : uint8_t ptr
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool swtimerGetCh(uint8_t *p_ch)
{
	if (swtimer_count >= SWTIMER_MAX_CH)
	{
		return false;
	}

	*p_ch = swtimer_count;

	swtimer_count++;

	return true;
}

/*****************************************************************************
* Function Name : swtimerSet
* Brief         : Swtimer parameter setting.
* Inputs        : uint8_t, function ptr, void ptr, SwtimerMode_t, uint32_t
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool swtimerSet(uint8_t ch,  void (*func)(void *arg), void *func_arg, SwtimerMode_t mode,
								uint32_t time_ms)
{
	if (ch >= SWTIMER_MAX_CH)
	{
		return false;
	}

	swtimer_tbl[ch].func = func;
	swtimer_tbl[ch].func_arg = func_arg;
	swtimer_tbl[ch].mode = mode;
	swtimer_tbl[ch].counter = 0;
	swtimer_tbl[ch].reload = time_ms;
	swtimer_tbl[ch].enable = false;

	return true;
}

/*****************************************************************************
* Function Name : swtimerStart
* Brief         : swtimer start.
* Inputs        : uint8_t
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool swtimerStart(uint8_t ch)
{
	if (ch >= SWTIMER_MAX_CH)
	{
		return false;
	}

	swtimer_tbl[ch].counter = 0;
	swtimer_tbl[ch].enable = true;

	return true;
}

/*****************************************************************************
* Function Name : swtimerStop
* Brief         : Swtimer stop.
* Inputs        : uint8_t
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool swtimerStop(uint8_t ch)
{
	if (ch >= SWTIMER_MAX_CH)
	{
		return false;
	}

	swtimer_tbl[ch].enable = false;

	return true;
}

/*****************************************************************************
* Function Name : swtimerISR
* Brief         : Process swtimer interrupt.
* Inputs        : void
* Outputs       :
* Return        : void
*****************************************************************************/
void swtimerISR(void)
{
	//While checking the number of swtimers set,
	for (int i = 0; i <swtimer_count; i++)
	{
		//if there is an active swtimer, the count value is increased.
		if (swtimer_tbl[i].enable == true)
		{
			swtimer_tbl[i].counter++;

			//When the timer counter becomes equal to the periodic value and..
			if (swtimer_tbl[i].counter >= swtimer_tbl[i].reload)
			{
				//there is a defined function pointer,
				if (swtimer_tbl[i].func != NULL)
				{
					//the function of the defined function pointer is called.
					swtimer_tbl[i].func(swtimer_tbl[i].func_arg);
				}

				//Reset the counter value to 0.
				swtimer_tbl[i].counter = 0;

				//If SWTIMER_ONETIME mode, enable is turned off.
				//cf) If SWTIMER_LOOP mode, repeat the above procedure.
				if (swtimer_tbl[i].mode == SWTIMER_ONETIME)
				{
					swtimer_tbl[i].enable = false;
				}
			}
		}
	}
}





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim14)
	{
		swtimerISR();
	}
}
