/*
 * adc.h
 *
 *  Created on: Apr 23, 2023
 *      Author: xowls
 */

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

#include "def.h"



bool adcInit(void);
uint16_t adcRead(uint8_t ch);
uint32_t adcReadVoltage(uint8_t ch);

#endif /* INCLUDE_ADC_H_ */
