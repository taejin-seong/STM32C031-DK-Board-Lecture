/*
 * ap.c
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */


#include "ap.h"



float adc_vol  = 0;

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
  pwmInit();
  adcInit();

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

  ledSetDuty(_DEF_CH1, 100);

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
    if (millis() - pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_CH1);

    }

    adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.0f;

  }
}
