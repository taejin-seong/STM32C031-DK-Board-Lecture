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

static void infoCli(uint8_t argc, const char **argv);


/*****************************************************************************
* Function Name : ledISR
* Brief         : led swtimer control function.
* Inputs        : void
* Outputs       :
* Return        : void
*****************************************************************************/
void ledISR(void *arg)
{
	ledToggle(_DEF_CH1);
}

/*****************************************************************************
* Function Name : apInit
* Brief         : Application initialization.
* Inputs        : void
* Outputs       :
* Return        : void
*****************************************************************************/
void apInit(void)
{
	cliInit();
	swtimerInit();
	rtcInit();
  ledInit();
  pwmInit();
  adcInit();
  buttonInit();
  uartInit();

  //cli command - info add
  cliAdd("info", infoCli);

  uint8_t timer_ch;

  if (swtimerGetCh(&timer_ch) == true)
  {
  	//0.5s
  	swtimerSet(timer_ch, ledISR, NULL, SWTIMER_LOOP, 500);
  	swtimerStart(timer_ch);
  }
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

    //Non-Blocking & Encapsulation & Modularization
    if (millis() - pre_time >= 500)
    {
      pre_time = millis();
     // ledToggle(_DEF_CH1);
    }

    cliMain();
  }

}

/*****************************************************************************
* Function Name : infoCli
* Brief         : CLI test command operation.
* Inputs        : uint8_t,  const char
* Outputs       :
* Return        : void
*****************************************************************************/
void infoCli(uint8_t argc, const char **argv)
{
	bool ret = false;

	//1.1. info - test
	if (argc == 1 && cliIsStr(argv[0], "test") == 0)
	{
		cliPrintf("infoCli run test\n");
		ret = true;
	}


	//1.2. info - print
	if (argc == 2 && cliIsStr(argv[0], "print"))
	{
		uint8_t count;

		count = (uint8_t)cliGetData(argv[1]);
		for (int i = 0; i < count; i++)
		{
			cliPrintf("print %d/%d\n", i+1, count);
		}

		ret= true;
	}


	//1.3. info - button
	if (argc == 1 && cliIsStr(argv[0], "button"))
	{
		while (cliKeepLoop())
		{
			for (int i = 0; i < BUTTON_MAX_CH; i++)
			{
				cliPrintf("%d", buttonGetPressed(i));
			}

			cliPrintf("\n");
			delay(100);
		}
		ret = true;
	}



	if (ret == false)
	{
		cliPrintf("info test\n");
		cliPrintf("info print 0~10\n");
		cliPrintf("info button\n");
	}

}
