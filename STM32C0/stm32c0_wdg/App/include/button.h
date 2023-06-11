/*
 * button.h
 *
 *  Created on: 2023. 5. 1.
 *      Author: xowls
 */

#ifndef INCLUDE_BUTTON_H_
#define INCLUDE_BUTTON_H_

#include "def.h"


#define BUTTON_MAX_CH          5 // Select, Left, Down, Up, Right



bool buttonInit(void);
bool buttonGetPressed(uint8_t ch);
uint32_t buttonGetData(uint8_t ch);


#endif /* INCLUDE_BUTTON_H_ */
