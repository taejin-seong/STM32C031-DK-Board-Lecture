/*
 * led.h
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */

#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_


#include "def.h"


bool ledInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);
void ledSetDuty(uint8_t ch, uint16_t duty_data);




#endif /* INCLUDE_LED_H_ */
