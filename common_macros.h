 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/* UPPER of a register -> pins 0 1 2 3
 * LOWER of a register -> pins 4 5 6 7
 */
#define SET_UPPER(REG) 		REG |=0x0F
#define CLEAR_UPPER(REG) 	REG &=0xF0
#define SET_LOWER(REG) 		REG |=0xF0
#define CLEAR_LOWER(REG) 	REG &=0x0F

#define PUT_UPPER_IN_UPPER(REG,VALUE)		(REG = (VALUE &0x0F)|(REG & 0xF0))
#define PUT_UPPER_IN_LOWER(REG,VALUE)		(REG = ((VALUE &0xF0) >> 4)|(REG & 0x0F))
#define PUT_LOWER_IN_UPPER(REG,VALUE)		(REG = (VALUE >> 4)|(REG & 0xF0))
#define PUT_LOWER_IN_LOWER(REG,VALUE)		(REG = (VALUE &0xF0)|(REG & 0x0F))

#endif
