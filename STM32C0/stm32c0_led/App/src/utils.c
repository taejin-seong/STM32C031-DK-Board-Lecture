/*
 * utils.c
 *
 *  Created on: Apr 9, 2023
 *      Author: xowls
 */


#include "utils.h"



/*****************************************************************************
* Function Name : delay
* Brief         : ms delay operation.
* Inputs        : time_ms
* Outputs       :
* Return        : void
*****************************************************************************/
void delay(uint32_t time_ms)
{
  HAL_Delay(time_ms);
}

/*****************************************************************************
* Function Name : mills
* Brief         : Increase by 1Tick every 1ms.
* Inputs        : void
* Outputs       : HAL_GetTick();
* Return        : uint32_t
*****************************************************************************/
uint32_t mills(void)
{
  return HAL_GetTick();
}
