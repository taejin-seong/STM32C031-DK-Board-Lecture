/*
 * button.c
 *
 *  Created on: 2023. 5. 1.
 *      Author: xowls
 */


#include "button.h"
#include "adc.h"


typedef struct
{
  uint16_t adc_min;
  uint16_t adc_max;

}button_adc_t;


static const uint8_t adc_ch = _DEF_CH1;
static const button_adc_t button_adc[BUTTON_MAX_CH] =
    {
        {0,   20},  // Select 0v ~ 2v
        {40,  87},  // Left   0.4v ~ 0.87v
        {122, 252}, // Down   1.22v ~ 2.52v
        {180, 220}, // Up     1.8v ~ 2.2v
        {245, 285}, // Right  2.45v ~ 2.85v
    };

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
  uint32_t adc_voltage;

  if (ch >= BUTTON_MAX_CH)
  {
    return false;
  }

  adc_voltage = adcReadVoltage(adc_ch);


  if (adc_voltage >= button_adc[ch].adc_min  &&  adc_voltage <= button_adc[ch].adc_max)
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
