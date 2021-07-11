/*

 * DIO_Config.c
 *
 *  Created on: Dec 12, 2020
 *      Author: Mohamed ELshazly
  /*********************************************************************/

/************************************************************************/
/*			       			INCLUDES             	                    */
/************************************************************************/


#include "STD_Types.h"
#include "DIO_config.h"

/************************************************************************/
/*			       			MACROS              	                    */
/************************************************************************/

#define OUTPUT ((uint8)0)
#define INPUT_PULLUP ((uint8)1)
#define INPUT_FLOATING ((uint8)2)

uint8 DIO_PinConfiguration[LAST_PIN]=	{OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,
                                         OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,
                                         OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,
                                         OUTPUT,OUTPUT,OUTPUT,OUTPUT,INPUT_PULLUP,INPUT_PULLUP,INPUT_PULLUP,INPUT_PULLUP};

