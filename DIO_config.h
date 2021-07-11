/*

* DIO_config.h
 *
 *  Created on: Dec 12, 2020
 *      Author: Mohamed Elshazly
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/************************************************************************/
/*			       			MACROS   & Enum            	                    */
/************************************************************************/
#define OUTPUT ((uint8)0)
#define INPUT_PULLUP ((uint8)1)
#define INPUT_FLOATING ((uint8)2)

typedef enum
{
    PORTA0=0,PORTA1,PORTA2,PORTA3,PORTA4,PORTA5,PORTA6,PORTA7,
    PORTB0,PORTB1,PORTB2,PORTB3,PORTB4,PORTB5,PORTB6,PORTB7,
    PORTC0,PORTC1,PORTC2,PORTC3,PORTC4,PORTC5,PORTC6,PORTC7,
    PORTD0,PORTD1,PORTD2,PORTD3,PORTD4,PORTD5,PORTD6,PORTD7,
                                                             LAST_PIN }
 
DIO_enuChannel;

typedef enum
{ PORT_A=0,PORT_B,PORT_C,PORT_D,LAST_PORT}

DIO_enuPort;

//extern DIO_PinConfiguration[LAST_PIN];
#endif /* DIO_CONFIG_H_ */

