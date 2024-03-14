/*
 * Serial.h
 *
 *  Created on: Mar 14, 2024
 *      Author: jingzhan96
 */

#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

#include <stdint.h>

// Cette fonction pourra être utilisée par le Shell v0.4
uint8_t SerialTransmit(char * pData, uint16_t Size);
// Dans cet exemple, on fait du polling, et c'est pas très grave
char SerialReceiveChar(void);

#endif /* INC_SERIAL_H_ */
