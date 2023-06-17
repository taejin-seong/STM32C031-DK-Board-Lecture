/*
 * wdg.h
 *
 *  Created on: Jun 11, 2023
 *      Author: xowls
 */

#ifndef INCLUDE_WDG_H_
#define INCLUDE_WDG_H_


#include "def.h"


bool wdgInit(void);
bool wdgBegin(uint32_t time_ms);
bool wdgRefresh(void);



#endif /* INCLUDE_WDG_H_ */
