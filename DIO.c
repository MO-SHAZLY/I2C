/*

 * DIO.c
 *
 *  Created on: Dec 12, 2020
 *      Author: Mohamed Elshazly
  /*********************************************************************/

/************************************************************************/
/*			       			INCLUDES             	                    */
/************************************************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "DIO_config.h"
#include "DIO_reg.h"


/*#define PORTA ((uint8)0)
#define PORTB ((uint8)1)
#define PORTC ((uint8)2)
#define PORTD ((uint8)4)
 */
uint8 i;
uint8 ret;
uint8 ret_ReadChannel;
extern uint8 DIO_PinConfiguration[LAST_PIN];
void DIO_Init(void)
{
	for( i=0;i<LAST_PIN;i++)
	{
		uint8 divide=i/8;
		switch (DIO_PinConfiguration[i])
		{
		
		case OUTPUT:
			switch(divide)
			{
			case 0:SET_BIT(DDRA,i%8);break;
			case 1:SET_BIT(DDRB,i%8);break;
			case 2:SET_BIT(DDRC,i%8);break;
			case 3:SET_BIT(DDRD,i%8);break;
			
			default:
				break;
			}
			break;

			case INPUT_PULLUP:
				switch(divide)
				{
				case 0:CLEAR_BIT(DDRA,i%8);
					   SET_BIT(PORTA,i%8);break;
				case 1:CLEAR_BIT(DDRB,i%8);
					   SET_BIT(PORTB,i%8);break;
				case 2:CLEAR_BIT(DDRC,i%8);
	                   SET_BIT(PORTC,i%8);break;
				case 3:CLEAR_BIT(DDRD,i%8);
		               SET_BIT(PORTD,i%8);break;

				}
				break;
				case INPUT_FLOATING:
					switch(divide)
					{
					case 0:CLEAR_BIT(DDRA,i%8);
						   CLEAR_BIT(PORTA,i%8);break;
					case 1:CLEAR_BIT(DDRB,i%8);
						   CLEAR_BIT(PORTB,i%8);break;
					case 2:CLEAR_BIT(DDRC,i%8);
						   CLEAR_BIT(PORTC,i%8);break;
					case 3:CLEAR_BIT(DDRD,i%8);
						   CLEAR_BIT(PORTD,i%8);break;
					}
					break;
		}
	}
}


void DIO_WriteChannel(DIO_enuChannel Channel_ID , uint8 value )
{
	if(value==0)
	{
		switch(Channel_ID)
		{
		case PORTA0:CLEAR_BIT(PORTA,0);break;
		case PORTA1:CLEAR_BIT(PORTA,1);break;
		case PORTA2:CLEAR_BIT(PORTA,2);break;
		case PORTA3:CLEAR_BIT(PORTA,3);break;
		case PORTA4:CLEAR_BIT(PORTA,4);break;
		case PORTA5:CLEAR_BIT(PORTA,5);break;
		case PORTA6:CLEAR_BIT(PORTA,6);break;
		case PORTA7:CLEAR_BIT(PORTA,7);break;
		
		case PORTB0:CLEAR_BIT(PORTB,0);break;
		case PORTB1:CLEAR_BIT(PORTB,1);break;
		case PORTB2:CLEAR_BIT(PORTB,2);break;
		case PORTB3:CLEAR_BIT(PORTB,3);break;
		case PORTB4:CLEAR_BIT(PORTB,4);break;
		case PORTB5:CLEAR_BIT(PORTB,5);break;
		case PORTB6:CLEAR_BIT(PORTB,6);break;
		case PORTB7:CLEAR_BIT(PORTB,7);break;
		
		case PORTC0:CLEAR_BIT(PORTC,0);break;
		case PORTC1:CLEAR_BIT(PORTC,1);break;
		case PORTC2:CLEAR_BIT(PORTC,2);break;
		case PORTC3:CLEAR_BIT(PORTC,3);break;
		case PORTC4:CLEAR_BIT(PORTC,4);break;
		case PORTC5:CLEAR_BIT(PORTC,5);break;
		case PORTC6:CLEAR_BIT(PORTC,6);break;
		case PORTC7:CLEAR_BIT(PORTC,7);break;
		
		case PORTD0:CLEAR_BIT(PORTD,0);break;
		case PORTD1:CLEAR_BIT(PORTD,1);break;
		case PORTD2:CLEAR_BIT(PORTD,2);break;
		case PORTD3:CLEAR_BIT(PORTD,3);break;
		case PORTD4:CLEAR_BIT(PORTD,4);break;
		case PORTD5:CLEAR_BIT(PORTD,5);break;
		case PORTD6:CLEAR_BIT(PORTD,6);break;
		case PORTD7:CLEAR_BIT(PORTD,7);break;

		}
	}
	else if(value==1)
	{
		switch(Channel_ID)
		{
		case PORTA0:SET_BIT(PORTA,0);break;
		case PORTA1:SET_BIT(PORTA,1);break;
		case PORTA2:SET_BIT(PORTA,2);break;
		case PORTA3:SET_BIT(PORTA,3);break;
		case PORTA4:SET_BIT(PORTA,4);break;
		case PORTA5:SET_BIT(PORTA,5);break;
		case PORTA6:SET_BIT(PORTA,6);break;
		case PORTA7:SET_BIT(PORTA,7);break;
		
		case PORTB0:SET_BIT(PORTB,0);break;
		case PORTB1:SET_BIT(PORTB,1);break;
		case PORTB2:SET_BIT(PORTB,2);break;
		case PORTB3:SET_BIT(PORTB,3);break;
		case PORTB4:SET_BIT(PORTB,4);break;
		case PORTB5:SET_BIT(PORTB,5);break;
		case PORTB6:SET_BIT(PORTB,6);break;
		case PORTB7:SET_BIT(PORTB,7);break;
		
		case PORTC0:SET_BIT(PORTC,0);break;
		case PORTC1:SET_BIT(PORTC,1);break;
		case PORTC2:SET_BIT(PORTC,2);break;
		case PORTC3:SET_BIT(PORTC,3);break;
		case PORTC4:SET_BIT(PORTC,4);break;
		case PORTC5:SET_BIT(PORTC,5);break;
		case PORTC6:SET_BIT(PORTC,6);break;
		case PORTC7:SET_BIT(PORTC,7);break;
		
		case PORTD0:SET_BIT(PORTD,0);break;
		case PORTD1:SET_BIT(PORTD,1);break;
		case PORTD2:SET_BIT(PORTD,2);break;
		case PORTD3:SET_BIT(PORTD,3);break;
		case PORTD4:SET_BIT(PORTD,4);break;
		case PORTD5:SET_BIT(PORTD,5);break;
		case PORTD6:SET_BIT(PORTD,6);break;
		case PORTD7:SET_BIT(PORTD,7);break;
		}
	}

}

void DIO_WritePort(DIO_enuPort Port_ID , uint8 value )
{
	switch(Port_ID)
	{
	case PORT_A:PORTA=value;break;
	case PORT_B:PORTB=value;break;
	case PORT_C:PORTC=value;break;
	case PORT_D:PORTD=value;break;
	default:break;
	}
}

uint8 DIO_ReadChannel(DIO_enuChannel PinChannel)
{
	switch(PinChannel)
	{
	case PORTA0:ret_ReadChannel= GET_BIT(PINA,0);break;
	case PORTA1:ret_ReadChannel= GET_BIT(PINA,1);break;
	case PORTA2:ret_ReadChannel= GET_BIT(PINA,2);break;
	case PORTA3:ret_ReadChannel= GET_BIT(PINA,3);break;
	case PORTA4:ret_ReadChannel= GET_BIT(PINA,4);break;
	case PORTA5:ret_ReadChannel= GET_BIT(PINA,5);break;
	case PORTA6:ret_ReadChannel= GET_BIT(PINA,6);break;
	case PORTA7:ret_ReadChannel= GET_BIT(PINA,7);break;
	
	case PORTB0:ret_ReadChannel= GET_BIT(PINB,0);break;
	case PORTB1:ret_ReadChannel= GET_BIT(PINB,1);break;
	case PORTB2:ret_ReadChannel= GET_BIT(PINB,2);break;
	case PORTB3:ret_ReadChannel= GET_BIT(PINB,3);break;
	case PORTB4:ret_ReadChannel= GET_BIT(PINB,4);break;
	case PORTB5:ret_ReadChannel= GET_BIT(PINB,5);break;
	case PORTB6:ret_ReadChannel= GET_BIT(PINB,6);break;
	case PORTB7:ret_ReadChannel= GET_BIT(PINA,7);break;
	
	case PORTC0:ret_ReadChannel= GET_BIT(PINC,0);break;
	case PORTC1:ret_ReadChannel= GET_BIT(PINC,1);break;
	case PORTC2:ret_ReadChannel= GET_BIT(PINC,2);break;
	case PORTC3:ret_ReadChannel= GET_BIT(PINC,3);break;
	case PORTC4:ret_ReadChannel= GET_BIT(PINC,4);break;
	case PORTC5:ret_ReadChannel= GET_BIT(PINC,5);break;
	case PORTC6:ret_ReadChannel= GET_BIT(PINC,6);break;
	case PORTC7:ret_ReadChannel= GET_BIT(PINC,7);break;
	
	case PORTD0:ret_ReadChannel= GET_BIT(PIND,0);break;
	case PORTD1:ret_ReadChannel= GET_BIT(PIND,1);break;
	case PORTD2:ret_ReadChannel= GET_BIT(PIND,2);break;
	case PORTD3:ret_ReadChannel= GET_BIT(PIND,3);break;
	case PORTD4:ret_ReadChannel= GET_BIT(PIND,4);break;
	case PORTD5:ret_ReadChannel= GET_BIT(PIND,5);break;
	case PORTD6:ret_ReadChannel= GET_BIT(PIND,6);break;
	case PORTD7:ret_ReadChannel= GET_BIT(PIND,7);break;

	}
	return ret_ReadChannel;
}
uint8 DIO_ReadPort(DIO_enuPort PortID)

{
	switch(PortID)
	{
	case PORT_A:ret= PINA;break;
	case PORT_B:ret= PINB;break;
	case PORT_C:ret= PINC;break;
	case PORT_D:ret= PIND;break;
	}
	return ret;
}
