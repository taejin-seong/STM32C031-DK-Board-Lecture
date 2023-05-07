/*
 * ap.c
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */


#include "ap.h"



float adc_vol  = 0;
float adc_vol_vref = 0;

bool button_data[BUTTON_MAX_CH];


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
  buttonInit();
  uartInit();

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

  pre_time = millis();

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

      //uartWrite(_DEF_CH1, (uint8_t *)"test\n", 5);
      //uartPrintf(_DEF_CH1, "test %d\n", millis());
      //uartPrintf(_DEF_CH1, "adc_vol %d.%d\n", (int)adc_vol, ((int)(adc_vol * 100)) % 100);
      //uartPrintf(_DEF_CH1, "rx cnt %d\n", uartAvailable(_DEF_CH1));

    }

    adc_vol = (float)adcReadVoltage(_DEF_CH1) / 100.0f;
    adc_vol_vref = (float)adcReadVoltage(_DEF_CH3) / 100.0f;

    button_data[_BUTTON_CH_SEL  ]   =  buttonGetPressed(_BUTTON_CH_SEL  );
    button_data[_BUTTON_CH_UP   ]   =  buttonGetPressed(_BUTTON_CH_UP   );
    button_data[_BUTTON_CH_DOWN ]   =  buttonGetPressed(_BUTTON_CH_DOWN );
    button_data[_BUTTON_CH_LEFT ]   =  buttonGetPressed(_BUTTON_CH_LEFT );
    button_data[_BUTTON_CH_RIGHT]   =  buttonGetPressed(_BUTTON_CH_RIGHT);


    if (uartAvailable(_DEF_CH1) > 0)
    {
    	uint8_t rx_data;

    	rx_data = uartRead(_DEF_CH1);
    	uartPrintf(_DEF_CH1, "rx data : 0x%02X (%c)\n", rx_data, rx_data );
    }

  }
}
