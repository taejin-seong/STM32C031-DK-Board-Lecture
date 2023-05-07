/*
 * pwm.h
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */

#ifndef INCLUDE_PWM_H_
#define INCLUDE_PWM_H_


#include "def.h"


bool pwmInit(void);
void pwmWrite(uint8_t ch, uint16_t duty);
uint16_t pwmRead(uint8_t ch);



#endif /* INCLUDE_PWM_H_ */
