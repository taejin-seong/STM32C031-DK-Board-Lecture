/*
 * def.h
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */

#ifndef DEF_H_
#define DEF_H_


#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

#include "main.h"


#define _DEF_CH1         0
#define _DEF_CH2         1
#define _DEF_CH3         2
#define _DEF_CH4         3
#define _DEF_CH5         4


#define _BUTTON_CH_SEL    _DEF_CH1
#define _BUTTON_CH_LEFT   _DEF_CH2
#define _BUTTON_CH_DOWN   _DEF_CH3
#define _BUTTON_CH_UP     _DEF_CH4
#define _BUTTON_CH_RIGHT  _DEF_CH5



void delay(uint32_t time_ms);
uint32_t millis(void);


#endif /* DEF_H_ */
