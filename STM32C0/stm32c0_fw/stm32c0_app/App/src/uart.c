/*
 * uart.c
 *
 *  Created on: May 7, 2023
 *      Author: xowls
 */


#include "uart.h"


#define UART_Q_BUF_MAX    256

extern UART_HandleTypeDef huart1;

static uint16_t q_in = 0;
static uint16_t q_out = 0;
static uint8_t q_buf[UART_Q_BUF_MAX];


/*****************************************************************************
* Function Name : uartInit
* Brief         : UART initialization.
* Inputs        : bool
* Outputs       : true/false
* Return        : bool
*****************************************************************************/
bool uartInit(void)
{
	HAL_UART_Receive_DMA(&huart1, &q_buf[0], UART_Q_BUF_MAX);
	return true;
}

/*****************************************************************************
* Function Name : uartWrite
* Brief         : Performs polling UART write operations.
* Inputs        : void
* Outputs       : ret
* Return        : uint32_t
*****************************************************************************/
uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
	uint32_t ret = 0;
	HAL_StatusTypeDef hal_ref;

	switch(ch)
	{
		case _DEF_CH1:
			//Write operation, Polling
			hal_ref = HAL_UART_Transmit(&huart1, p_data, length, 100);
			if (hal_ref == HAL_OK)
			{
				ret = length;
			}
			break;
	}


	return ret;
}

/*****************************************************************************
* Function Name : uartAvailable
* Brief         : Determining the availability of uart by checking the number of q_buf.
* Inputs        : uint8_t
* Outputs       : ret
* Return        : uint32_t
*****************************************************************************/
uint32_t uartAvailable(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
		case _DEF_CH1:
			q_in = (UART_Q_BUF_MAX - huart1.hdmarx->Instance->CNDTR) % UART_Q_BUF_MAX;
			// Calculating the number of buffers stored.
			ret = (UART_Q_BUF_MAX + q_in - q_out) % UART_Q_BUF_MAX;
			break;
	}

	return ret;
}

/*****************************************************************************
* Function Name : uartRead
* Brief         : Perform DMA UART Read operations.
*               : cf) uartAvailable, q_in.
* Inputs        : uint8_t
* Outputs       : ret
* Return        : uint8_t
*****************************************************************************/
uint8_t uartRead(uint8_t ch)
{
	uint8_t ret =0;

	switch(ch)
	{
		case _DEF_CH1:
			if (q_out != q_in)
			{
				ret = q_buf[q_out];
				q_out = (q_out + 1) % UART_Q_BUF_MAX;
			}
			break;
	}

	return ret;
}

/*****************************************************************************
* Function Name : uartPrintf
* Brief         : Use the uart write action to output a formatted string.
* Inputs        : uint8_t,  const char, ...
* Outputs       : ret
* Return        : uint32_t
*****************************************************************************/
uint32_t uartPrintf(uint8_t ch, const char *fmt, ...)
{
	uint32_t ret = 0;
	va_list arg;
	char print_buf[256];

	va_start(arg, fmt);

	int len;
	len = vsnprintf(print_buf, 256, fmt, arg);

	va_end(arg);

	if (len > 0)
	{
		ret = uartWrite(ch, (uint8_t *)print_buf, len);
	}

	return ret;
}

/*****************************************************************************
* Function Name : uartVPrintf
* Brief         : Use the uart write action to output a formatted string.(for CLI mode)
* Inputs        : uint8_t,  const char, ...
* Outputs       : ret
* Return        : uint32_t
*****************************************************************************/
uint32_t uartVPrintf(uint8_t ch, const char *fmt, va_list arg)
{
	uint32_t ret = 0;
	char print_buf[256];

	int len;
	len = vsnprintf(print_buf, 256, fmt, arg);

	if (len > 0)
	{
		ret = uartWrite(ch, (uint8_t *)print_buf, len);
	}

	return ret;
}
