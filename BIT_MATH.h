/*
 * BIT_MATH.h
 *
 *  Created on: Dec 12, 2020
 *      Author: Al Badr
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Byte,Bit_index) Byte=((Byte) | ((1)<<(Bit_index)))
#define CLEAR_BIT(Byte,Bit_index) Byte=((Byte) & (~(1<<(Bit_index))))
#define READ_BIT(Byte,Bit_index) ((Byte>>Bit_index)&1)
#define TOGGLE_BIT(Byte,Bit_index) Byte=((Byte) ^ (~(1<<(Bit_index))))

#define ROR_BIT(Byte,Bit_index) Byte=(((Byte)<<(Bit_index))|((Byte)>>(8-Bit_index)))
#define ROL_BIT(Byte,Bit_index) Byte=(((Byte)>>(Bit_index))|((Byte)<<(8-Bit_index)))
#define BIT_IS_SET(Byte,Bit_index) ((Byte) &   (1<<(Bit_index)))
#define BIT_IS_CLEAR(Byte,Bit_index) ((Byte) |   ((1<<Bit_index)))

#define GET_BIT(Byte,Bit_index) (((Byte)>>(Bit_index))&1)


#endif /* BIT_MATH_H_ */
