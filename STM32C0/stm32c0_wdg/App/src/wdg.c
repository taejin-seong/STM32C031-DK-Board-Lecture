/*
 * wdg.c
 *
 *  Created on: Jun 11, 2023
 *      Author: xowls
 */


#include "wdg.h"



static IWDG_HandleTypeDef hiwdg;

/*****************************************************************************
* Function Name : wdgInit
* Brief         : Watchdog initialization.
* Inputs        : void
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool wdgInit(void)
{
	return true;
}

/*****************************************************************************
* Function Name : wdgBegin
* Brief         : Watchdog start.
* Inputs        : uint32_t
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool wdgBegin(uint32_t time_ms)
{
	if (time_ms >= 4095)
	{
		return false;
	}

  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
  hiwdg.Init.Window = 4095;
  hiwdg.Init.Reload = 4095;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
  	return false;
  }

	return true;
}

/*****************************************************************************
* Function Name : wdgRefresh
* Brief         : Watchdog refresh.
* Inputs        : void
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool wdgRefresh(void)
{
	HAL_IWDG_Refresh(&hiwdg);
	return true;
}

