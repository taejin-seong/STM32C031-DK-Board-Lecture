/*
 * cli.h
 *
 *  Created on: 2023. 5. 28.
 *      Author: xowls
 */

#ifndef INCLUDE_CLI_H_
#define INCLUDE_CLI_H_

#include "def.h"

bool    cliInit(void);
bool    cliAdd(const char *cmd_str, void (*cmd_func)(uint8_t argc, const char **argv));
void    cliPrintf(const char *fmt, ...);
bool    cliIsStr(const char *p_arg, const char *p_str);
int32_t cliGetData(const char *p_arg);
bool    cliKeepLoop(void);
bool    cliMain(void);


#endif /* INCLUDE_CLI_H_ */
