/*
 * ap.h
 *
 *  Created on: Apr 15, 2023
 *      Author: xowls
 */

#ifndef AP_H_
#define AP_H_

#include "utils.h"
#include "led.h"
#include "pwm.h"
#include "adc.h"
#include "button.h"
#include "uart.h"
#include "cli.h"
#include "swtimer.h"
#include "rtc.h"


void apInit(void);
void apMain(void);

#endif /* AP_H_ */
