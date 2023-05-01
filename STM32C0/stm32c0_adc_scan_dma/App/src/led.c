/*
 * led.c
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */


#include "led.h"
#include "pwm.h"

static uint16_t led_duty[1] = {100};


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
      //HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
      pwmWrite(_DEF_CH1, 100 - led_duty[_DEF_CH1]);
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
      //HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
      pwmWrite(_DEF_CH1, 100);
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
      //HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
      if (pwmRead(_DEF_CH1) == 100)
      {
        ledOn(_DEF_CH1);
      }
      else
      {
        ledOff(_DEF_CH1);
      }
      break;
  }
}

/*****************************************************************************
* Function Name : ledSetPWM
* Brief         : LED set duty.
* Inputs        : ch, duty_data
* Outputs       :
* Return        : void
*****************************************************************************/
void ledSetDuty(uint8_t ch, uint16_t duty_data)
{
  switch(ch)
  {
    case _DEF_CH1:
      led_duty[ch] = duty_data;
      break;
  }

}
