/*
 * adc.c
 *
 *  Created on: Apr 23, 2023
 *      Author: xowls
 */


#include "adc.h"

extern ADC_HandleTypeDef hadc1;



uint16_t adc_data[3];
//uint32_t adc_time;


/*****************************************************************************
* Function Name : adcInit
* Brief         : ADC initialization.
* Inputs        : void
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool adcInit(void)
{
  HAL_ADCEx_Calibration_Start(&hadc1);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_data, 3);
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

  ret = adc_data[ch];

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





/*
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  static uint32_t adc_cnt = 0;
  static uint32_t pre_time;

  adc_cnt++;

  if (millis() - pre_time >= 1000)
  {
    pre_time = millis();

    adc_time = adc_cnt;
    adc_cnt = 0;
  }
}
*/
