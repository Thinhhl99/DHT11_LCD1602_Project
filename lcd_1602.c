#include "lcd_1602.h"

void LCD_Init(void) {
    delay_ms_TIM2(20);               // Ch? LCD kh?i d?ng
    LCD_SendNibble(0x03);            // G?i l?nh kh?i t?o ch? d? 8-bit
    delay_ms_TIM2(5);
    LCD_SendNibble(0x03);
    delay_ms_TIM2(1);
    LCD_SendNibble(0x03);
    LCD_SendNibble(0x02);            // Switch to  4-bit mod

	LCD_Command(0x28);                 // Mode: 4-bit, 2 lines, 5x8 font
		LCD_Command(0x0C);               // Display: ON, Pointer: OFF
		LCD_Command(0x01);               // Clear: on the monitor
    LCD_Command(0x06);               // Tang dia chi DDRAM, không d?ch màn hình
}

void LCD_SendNibble(uint8_t nibble) {
    // ->> nibble to PA7-PA4
    GPIOA->ODR = (GPIOA->ODR & ~DATA_PINS) | ((nibble & 0x0F) << 4);
    // Create clock (pulse) to E pin
    GPIOB->ODR |= E_PIN;             // E = 1
    delay_ms_TIM2(1);
    GPIOB->ODR &= ~E_PIN;             // E = 0
}

void LCD_Command(uint8_t cmd) {
    GPIOB->ODR &=~ RS_PIN;            // RS = 0
    LCD_SendNibble(cmd >> 4);        // Send HIGH nibble
    LCD_SendNibble(cmd);             // Send LOW nibble
    delay_ms_TIM2(2);                // Waiting for execution
}

void LCD_Data(uint8_t data) {
    GPIOB->ODR |=  RS_PIN;            // RS = 1
    LCD_SendNibble(data >> 4);       // Send HIGH nibble
    LCD_SendNibble(data);            // Send LOW nibble
    delay_ms_TIM2(2);                // Waiting for execution
}

void LCD_String(char *str) {
    while (*str) {
        LCD_Data(*str);  // G?i t?ng ký t? trong chu?i
        str++;
    }
}
void LCD_Clear(void) {
	LCD_Command(0x01); 			// Clear: Monitor
	delay_ms_TIM2(2);       // Waiting: LCD execute clear
}
void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x80 : 0xC0;
    address += col;
    LCD_Command(address);
}
void LCD_Scroll(uint8_t direction) {
    if (direction == LEFT_SCROLL) {
        LCD_Command(0x18); // Cu?n trái
    } else if (direction == RIGHT_SCROLL) {
        LCD_Command(0x1C); // Cu?n ph?i
    }
}
void LCD_GPIO_Config(void){
	  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN; // Enable Clock cho GPIOA and GPIOB

	// Configure: GPIO cho LCD- 4bit// Clear config: PA4-PA7// PA4-PA7 Output Mode, Push-Pull// PB0-PB1 Output Mode, Push-Pull
	GPIOA->CRL &= ~0xFFFF0000;  	// Clear config: PA4-PA7
  GPIOA->CRL |= 0x33330000;  		// PA4-PA7 Output Mode, Push-Pull
	GPIOB->CRL &= ~0x000000FF; 		// Clear config PB0-PB1 (RS: PB0 ; E: PB1 )
  GPIOB->CRL |= 0x00000033;  		// PB0-PB1 Output Mode, Push-Pull
}