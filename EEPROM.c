/*
 * eeprom.c
 *
 *  Created on: Mar 27, 2021
 *      Author: DELL
 */

#include <avr/io.h>
#include "IIC.h"
#include "EEPROM.h"



void EEPROM_Init(void)
{
  I2C_Init();
}

unsigned char EEPROM_WriteByte(unsigned int addr, unsigned char data)
{
  unsigned char state = 0;
  unsigned char _3_MSB_Addr = 0;

  // Start TWI
  TWIStart();
  // Get State
  state = TWIGetStatus();
  // Check if TWI Start --- 0x08
  if (state != TW_START)
  {
    //  PORTA |= 0x02;
    return 0;
  }

  _3_MSB_Addr = ((unsigned char) ((addr & 0x0700) >> 7));
  // TWIWrite(0xA0|_3MSBAddr);
  TWIWrite(0xA0);
  // Get Status
  state = TWIGetStatus();
  // Check if it is TW_MT_SLA_ACK  /* 0x18 */
  if (state != TW_MT_SLA_ACK)
  {
    PORTA |= 0x02;
    return 0;
  }

  // Write the Rest of Location Address(8 Bits)
  TWIWrite((unsigned char) addr);

  // Get State
  state = TWIGetStatus();

  // check if it is TW_MT_DATA_ACK  /* 0x28 */
  if (state != TW_MT_DATA_ACK)
  {
//    PORTA |= 0x02;
    return 0;
  }

  // Send Data
  TWIWrite(data);

  // Get Status
  state = TWIGetStatus();

  // Check if it is TW_MT_DATA_ACK  /* 0x28 */
  if (state != TW_MT_DATA_ACK)
  {
    //   PORTA |= 0x02;
    return 0;
  }

  // TWI Stop
  TWIStop();
  // Return Done
  return 1;
}

unsigned char EEPROM_ReadByte(unsigned int addr, unsigned char *data)
{
  unsigned char state = 0;
  unsigned char _3_MSB_Addr = 0;

  // Start TWI
  TWIStart();

  // Get State
  state = TWIGetStatus();

  // Check if TWI Start
  if (state != TW_START)
    return 0;

  _3_MSB_Addr = ((unsigned char) ((addr & 0x0700) >> 7));
  // TWIWrite(0xA0|_3_MSB_Addr);
  TWIWrite(0xA0);

  // Get Status
  state = TWIGetStatus();

  // Check if it is TW_MT_SLA_ACK
  if (state != TW_MT_SLA_ACK)
    return 0;

  // Write the Rest of Location Address(8 Bits)
  TWIWrite((unsigned char) addr);

  // Get State
  state = TWIGetStatus();

  // check if it is TW_MT_DATA_ACK /* 0x28 */
  if (state != TW_MT_DATA_ACK)
    return 0;

  // Now The Master Will Be Master Reciever

  // Now we need to Send Start Bit Again
  // Start TWI
  TWIStart();

  // Get State
  state = TWIGetStatus();

  // Check if TW_REP_START
  if (state != TW_REP_START)
    return 0;

  _3_MSB_Addr = ((unsigned char) ((addr & 0x0700) >> 7));
//    TWIWrite(0xA0|_3_MSB_Addr|1);
  TWIWrite(0xA0 | 1);
  // Get Status
  state = TWIGetStatus();

  // Check if it is TW_MR_SLA_ACK  */ 0x18 */
  if (state != TW_MR_SLA_ACK)
    return 0;

  // Read Data
  // *data = TWIReadNACK();
  *data = TWIReadACK();

  // Get Status
  state = TWIGetStatus();

  // Check if it is
  if (state != TW_MR_DATA_ACK)
  {
    PORTA |= 0x04;
    return 0;
  }
  // TWI Stop
  TWIStop();

  // Return Done
  return 1;
}
