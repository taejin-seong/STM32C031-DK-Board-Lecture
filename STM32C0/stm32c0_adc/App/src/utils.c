/*
 * utils.c
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */


#include "utils.h"





void delay(uint32_t time_ms)
{
  HAL_Delay(time_ms);
}

uint32_t millis(void)
{
  return HAL_GetTick();
}
