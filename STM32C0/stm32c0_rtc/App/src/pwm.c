/*
 * pwm.c
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */


#include "pwm.h"

extern TIM_HandleTypeDef htim1;


/********************************************** *******************************
* Function Name : pwmInit
* Brief         : PWM initialization.
* Inputs        : void
* Outputs       : true
* Return        : bool
*****************************************************************************/
bool pwmInit(void)
{
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

  return true;
}

/*****************************************************************************
* Function Name : pwmWrite
* Brief         : PWM duty value write
* Inputs        : ch, duty
* Outputs       : -
* Return        : void
*****************************************************************************/
void pwmWrite(uint8_t ch, uint16_t duty)
{
  switch(ch)
  {
    case _DEF_CH1:
      htim1.Instance->CCR1 = duty;
      break;
  }
}

/*****************************************************************************
* Function Name : pwmRead
* Brief         : PWM duty value read.
* Inputs        : ch
* Outputs       : pwm_data
* Return        : uint16_t
*****************************************************************************/
uint16_t pwmRead(uint8_t ch)
{
  uint16_t pwm_data = 0;


  switch(ch)
  {
    case _DEF_CH1:
      pwm_data = htim1.Instance->CCR1;
      break;
  }

  return pwm_data;

}
