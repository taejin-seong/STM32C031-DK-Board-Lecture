/*
 * ap.c
 *
 *  Created on: Apr 9, 2023
 *      Author: xowls
 */


#include "ap.h"


/*****************************************************************************
* Function Name : apInit
* Brief         : Application initialization.
* Inputs        : void
* Outputs       :
* Return        : void
*****************************************************************************/
void apInit(void)
{
  ledInit();
}

/*****************************************************************************
* Function Name : apMain
* Brief         : Application operation.
* Inputs        : void
* Outputs       :
* Return        : void
*****************************************************************************/
void apMain(void)
{
  uint32_t pre_time;

  while(1)
  {
    //Blocking Code
    /*
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    HAL_Delay(500);
    */

    //Non-Blocking Code
    /*
    if (HAL_GetTick() - pre_time >= 500)
    {
      pre_time = HAL_GetTick();
      HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    }
    */

    //Non-Blocking & Encapsulation & Modularization
    if (mills() - pre_time >= 500)
    {
      pre_time = mills();
      ledToggle(_DEF_CH1);
    }

  }
}
