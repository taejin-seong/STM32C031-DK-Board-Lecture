/*
 * adc.c
 *
 *  Created on: Apr 23, 2023
 *      Author: xowls
 */


#include "adc.h"

extern ADC_HandleTypeDef hadc1;


/*****************************************************************************
* Function Name : adcInit
* Brief         : ADC initialization.
* Inputs        : void
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool adcInit(void)
{
  return true;
}

/*****************************************************************************
* Function Name : adcRead
* Brief         : ADC Digit value read.
* Inputs        : uint8_t
* Outputs       :
* Return        : uint16_t
*****************************************************************************/
uint16_t adcRead(uint8_t ch)
{
  uint16_t ret = 0;
  switch (ch)
  {
    case _DEF_CH1:
      HAL_ADC_Start(&hadc1);
      HAL_ADC_PollForConversion(&hadc1, 10);
      ret = HAL_ADC_GetValue(&hadc1);
      //HAL_ADC_Stop(&hadc1);
      break;
  }

  return ret;
}

/*****************************************************************************
* Function Name : adcReadVoltage
* Brief         : ADC voltage value read.
* Inputs        : uint8_t
* Outputs       :
* Return        : uint32_t
*****************************************************************************/
uint32_t adcReadVoltage(uint8_t ch)
{
  uint32_t ret;
  uint32_t adc_data;

  adc_data = adcRead(ch);
  ret = (330 * adc_data) / 4096;

  return ret;
}
