/*
 * eeprom.h
 *
 *  Created on: Mar 27, 2021
 *      Author: DELL
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_Init(void);
unsigned char EEPROM_WriteByte(unsigned int addr, unsigned char data);
unsigned char EEPROM_ReadByte(unsigned int addr, unsigned char *data);

#endif /* EEPROM_H_ */
