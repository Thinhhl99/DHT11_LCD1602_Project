#ifndef __MAIN_H__
#define __MAIN_H__

#include<stdint.h>
#include<stdio.h>
#include "stm32f10x.h"
#include "lcd_1602.h"
#include "timer.h"

#define LCD_Data_Dir (GPIOB->)
/*1. Set 1 bit at offset "n" of the register to 1*/
#define SET_1_BIT_AT_OFFSET(reg, offset) ((reg)|(1 << (offset)))

/*2. Clear 1 bit at offset "n" of the register*/
#define CLEAR_1_BIT_AT_OFFSET(reg, offset) ((reg)&~ (1 << (offset)))

/*3. Get the state (value) of 1 bit at offset "n" of the register*/
#define GET_BIT_AT_OFFSET(reg, offset) ((reg)>>(offset)&1)

/*4. Toggle 1 bit at offset "n" of the register*/
#define TOGGLE_BIT_AT_OFFSET(reg, offset) ((reg)^(1<<(offset)))

/*5. Clear "m" contiguous bit at offset "n" of the register*/
#define CLEAR_CONTIGUOUS_BIT_AT_OFFSET(reg, m, offset) ((reg)&~(((1<<(m))-1) << (offset)))

/*6. Set "m" contiguous bit at offset "n" of the register*/
#define SET_CONTIGUOUS_BIT_AT_OFFSET(reg, m, offset) ((reg)|(((1<<(m))-1) << (offset)))

/*7. Set "m" contiguous bit at offset "n" of the register to a given value*/
#define SET_CONTIGUOUS_BIT_AT_OFFSET_TO_VALUE(reg, m,offset,value) ((CLEAR_CONTIGUOUS_BIT_AT_OFFSET(reg, m, offset))| ((value)<<(offset)))

/*8. Get the value of "m" contiguous bit at offset "n" of the register*/
#define GET_VALUE_CONTIGUOUS_BIT_AT_OFFSET(reg, m, offset) (((reg)>>(offset)) & ((1<<(m))-1))

/************************/
/************************/
__asm(".global __ARM_use_no_argv");
#endif /* __MAIN_H__*/
