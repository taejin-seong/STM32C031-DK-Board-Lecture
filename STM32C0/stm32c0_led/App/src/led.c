/*
 * led.c
 *
 *  Created on: Apr 9, 2023
 *      Author: xowls
 */


#include "led.h"



/*****************************************************************************
* Function Name : ledInit
* Brief         : LED initialization.
* Inputs        : void
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool ledInit(void)
{
  return true;
}

/*****************************************************************************
* Function Name : ledOn
* Brief         : LED On.
* Inputs        : ch
* Outputs       :
* Return        : void
*****************************************************************************/
void ledOn(uint8_t ch)
{
  switch(ch)
  {
    case _DEF_CH1:
      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
      break;
  }
}

/*****************************************************************************
* Function Name : ledOff
* Brief         : LED Off.
* Inputs        : ch
* Outputs       :
* Return        : void
*****************************************************************************/
void ledOff(uint8_t ch)
{
  switch(ch)
  {
    case _DEF_CH1:
      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
      break;
  }
}

/*****************************************************************************
* Function Name : ledToggle
* Brief         : LED Toggle.
* Inputs        : ch
* Outputs       :
* Return        : void
*****************************************************************************/
void ledToggle(uint8_t ch)
{
  switch(ch)
  {
    case _DEF_CH1:
      HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
      break;
  }
}

