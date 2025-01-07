#ifndef __LCD_1602_H__
#define __LCD_1602_H__
#include "main.h"

// Ð?nh nghia th? công các chân GPIO
#define RS_PIN (1U << 0)  // PB0 - Chân RS
#define E_PIN  (1U << 1)  // PB1 - Chân E
#define D4_PIN (1U << 4)  // PA4
#define D5_PIN (1U << 5)  // PA5
#define D6_PIN (1U << 6)  // PA6
#define D7_PIN (1U << 7)  // PA7
#define DATA_PINS (D4_PIN | D5_PIN | D6_PIN | D7_PIN) // PA7-PA4
#define LEFT_SCROLL  0
#define RIGHT_SCROLL 1

void LCD_Command(uint8_t cmd);
void LCD_Data(uint8_t data);
void LCD_Init(void);
void LCD_SendNibble(uint8_t nibble);
void LCD_String(char *str);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);  
void LCD_Scroll(uint8_t direction);
void LCD_GPIO_Config(void);
#endif /*__LCD_1602_H__*/