/*
 * ap.c
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */


#include "ap.h"


static void jumpToAddr(uint32_t addr);



/*****************************************************************************
* Function Name : apInit
* Brief         : Application initialization.
* Inputs        : void
* Outputs       :
* Return        : void
*****************************************************************************/
void apInit(void)
{
	wdgInit();
  buttonInit();

  if (buttonGetPressed(_DEF_CH1) == true)
  {
  	wdgBegin(2000); //2s
  	jumpToAddr(0x1FFF0000); // Jump to System Bootloader
  }

  else
  {
  	jumpToAddr(0x8000800); // Jump to Firware (12K + 2K)

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

  while(1)
  {
  }

}


/*****************************************************************************
* Function Name : jumpToAddr
* Brief         : Jump to FW address.
* Inputs        : uint32_t
* Outputs       :
* Return        : void
*****************************************************************************/
void jumpToAddr(uint32_t addr)
{
	void (**jump_addr)(void) = (void (**)(void))(addr + 4);

	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;

	for (volatile int i = 0; i < 8; i++)
	{
		NVIC->ICER[i] = 0xFFFFFFFF;
		NVIC->ICPR[i] = 0xFFFFFFFF;
		__DSB();
		__ISB();
	}

	__set_MSP(*(uint32_t *)(addr));
	(*jump_addr)();
}

