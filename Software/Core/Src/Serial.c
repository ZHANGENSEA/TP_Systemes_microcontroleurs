/*
 * Serial.c
 *
 *  Created on: Mar 14, 2024
 *      Author: jingzhan96
 */

#include "Serial.h"
#include "usart.h"

uint8_t SerialTransmit(char * pData, uint16_t Size)
{
	for(int i = 0; i < Size; i++)
	{
		LL_USART_TransmitData8(USART2,pData[i]);
		while(LL_USART_IsActiveFlag_TXE(USART2)==0);
	}
	return 0;
}

char SerialReceiveChar(void)
{
	while(LL_USART_IsActiveFlag_RXNE(USART2)==0);
	return LL_USART_ReceiveData8(USART2);
}
