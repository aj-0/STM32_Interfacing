#ifndef PCF8574_LCD_H
#define PCF8574_LCD_H

#include "stm32f4xx_hal.h"

#define LCD_I2C_ADDR   (0x27 << 1)   // change to 0x3F<<1 if that's your module

void LCD_Init(I2C_HandleTypeDef *hi2c);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Print(char *str);
void LCD_PrintChar(char c);
void LCD_Backlight(uint8_t state);   // 1 = on, 0 = off
void LCD_SendCmd(uint8_t cmd);
void LCD_SendData(uint8_t data);

#endif
