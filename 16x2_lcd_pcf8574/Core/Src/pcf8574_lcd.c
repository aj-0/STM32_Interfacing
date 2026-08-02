#include "pcf8574_lcd.h"

static I2C_HandleTypeDef *lcd_hi2c;
static uint8_t backlight_state = 0x08;   // PCF8574 P3 = backlight

// PCF8574 -> LCD mapping (standard I2C backpack):
// P0=RS  P1=RW  P2=EN  P3=BL  P4=D4 P5=D5 P6=D6 P7=D7

static void LCD_I2C_Write(uint8_t data)
{
    HAL_I2C_Master_Transmit(lcd_hi2c, LCD_I2C_ADDR, &data, 1, 100);
}

static void LCD_EnablePulse(uint8_t data)
{
    LCD_I2C_Write(data | 0x04);   // EN = 1
    HAL_Delay(1);
    LCD_I2C_Write(data & ~0x04);  // EN = 0
    HAL_Delay(1);
}

static void LCD_Write4Bits(uint8_t nibble)
{
    uint8_t data = (nibble & 0xF0) | backlight_state;
    LCD_I2C_Write(data);
    LCD_EnablePulse(data);
}

void LCD_SendCmd(uint8_t cmd)
{
    LCD_Write4Bits(cmd & 0xF0);          // upper nibble, RS=0
    LCD_Write4Bits((cmd << 4) & 0xF0);   // lower nibble
}

void LCD_SendData(uint8_t data)
{
    uint8_t upper = (data & 0xF0) | 0x01 | backlight_state;
    uint8_t lower = ((data << 4) & 0xF0) | 0x01 | backlight_state;

    LCD_I2C_Write(upper);
    LCD_EnablePulse(upper);
    LCD_I2C_Write(lower);
    LCD_EnablePulse(lower);
}

void LCD_Init(I2C_HandleTypeDef *hi2c)
{
    lcd_hi2c = hi2c;
    HAL_Delay(50);

    // Init sequence per HD44780 datasheet, 4-bit mode
    LCD_Write4Bits(0x30);
    HAL_Delay(5);
    LCD_Write4Bits(0x30);
    HAL_Delay(1);
    LCD_Write4Bits(0x30);
    HAL_Delay(1);
    LCD_Write4Bits(0x20);   // set 4-bit mode
    HAL_Delay(1);

    LCD_SendCmd(0x28);   // 4-bit, 2 line, 5x8 font
    LCD_SendCmd(0x0C);   // display on, cursor off, blink off
    LCD_SendCmd(0x06);   // entry mode: increment cursor
    LCD_SendCmd(0x01);   // clear display
    HAL_Delay(2);
}

void LCD_Clear(void)
{
    LCD_SendCmd(0x01);
    HAL_Delay(2);
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    static const uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    LCD_SendCmd(0x80 | (col + row_offsets[row]));
}

void LCD_Print(char *str)
{
    while (*str)
        LCD_SendData((uint8_t)*str++);
}

void LCD_PrintChar(char c)
{
    LCD_SendData((uint8_t)c);
}

void LCD_Backlight(uint8_t state)
{
    backlight_state = state ? 0x08 : 0x00;
    LCD_I2C_Write(backlight_state);
}
