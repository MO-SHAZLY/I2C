/*
 *
 DIO.h
 *
 *  Created on: Dec 12, 2020
 *      Author: Mohamed Elshazly
  /*********************************************************************/

#ifndef DIO_H_
#define DIO_H_

/************************************************************************/
/*			       			INCLUDES             	                    */
/************************************************************************/
#include "STD_Types.h"
#include "DIO_config.h"

/************************************************************************/
/*				           FUNCTION PROTOTYPES	                        */
/************************************************************************/

extern void DIO_Init(void);

extern void DIO_WriteChannel(DIO_enuChannel Channel_ID , uint8 value);
extern void DIO_WritePort(DIO_enuPort Port_ID , uint8 value);

extern uint8 DIO_ReadChannel(DIO_enuChannel PinChannel);
extern uint8 DIO_ReadPort( DIO_enuPort PortID);


#endif /* DIO_H_ */
