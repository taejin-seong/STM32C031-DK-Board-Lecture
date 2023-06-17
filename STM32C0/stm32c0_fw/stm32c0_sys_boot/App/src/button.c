/*
 * button.c
 *
 *  Created on: 2023. 5. 1.
 *      Author: xowls
 */


#include "button.h"
#include "adc.h"




/*****************************************************************************
* Function Name : buttonInit
* Brief         : Button initialization.
* Inputs        : void
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool buttonInit(void)
{
  return true;
}

/*****************************************************************************
* Function Name : buttonGetPressed
* Brief         : Detects if the button is pressed.
* Inputs        : uint8_t
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool buttonGetPressed(uint8_t ch)
{
  bool ret = false;


  if (ch >= BUTTON_MAX_CH)
  {
    return false;
  }

  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_RESET)
  {
  	ret = true;
  }

  return ret;
}

/*****************************************************************************
* Function Name : buttonGetData
* Brief         : Gets the ADC value when the button is pressed.
* Inputs        : uint8_t
* Outputs       : data
* Return        : uint32_t
*****************************************************************************/
uint32_t buttonGetData(uint8_t ch)
{
  uint32_t ret = 0;

  for (int i = 0; i < BUTTON_MAX_CH; i++)
  {
    ret |= (buttonGetPressed(i) << i);
  }


  return ret;
}
