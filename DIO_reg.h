/*

* DIO_reg.h
 *
 *  Created on: Dec 12, 2020
 *      Author: Mohamed Elshazly
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

/************************************************************************/
/*			       			MACROS              	                    */
/************************************************************************/

//DDRD DEFINAtion
#define DDRA *((volatile uint8*)0x3A)
#define DDRB *((volatile uint8*)0x37)
#define DDRC *((volatile uint8*)0x34)
#define DDRD *((volatile uint8*)0x31)

//PORTS DEFINAtion
#define PORTA *((volatile uint8*)0x3B)
#define PORTB *((volatile uint8*)0x38)
#define PORTC *((volatile uint8*)0x35)
#define PORTD *((volatile uint8*)0x32)

//PINS DEFINAtion
#define PINA *((volatile uint8*)0x39)
#define PINB *((volatile uint8*)0x36)
#define PINC *((volatile uint8*)0x33)
#define PIND *((volatile uint8*)0x30)

#define  UCSRC *((volatile uint8*)0x40)
#define  UCSRB *((volatile uint8*)0x2A)
#define  UCSRA *((volatile uint8*)0x2B)


#endif /* DIO_REG_H_ */
