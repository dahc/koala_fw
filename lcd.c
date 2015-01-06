#include <stdarg.h>
#include <stdio.h>

#include "config.h"
#include "expio.h"
#include "lcd.h"

void lcd_init()
{
	LCD_DATA_DDR = 0xFF;
	LCD_CTRL_DDR |= (1 << LCD_ENABLE) | (1 << LCD_REGSEL);
	LCD_DATA_PORT = 0x00;
	LCD_CTRL_PORT &= ~((1 << LCD_ENABLE) | (1 << LCD_REGSEL));

	_delay_ms(100);
	lcd_cmd(LCD_CTRL, 0x38); /* 8-bit, 2-line display, 5x8 dot font */
	lcd_cmd(LCD_CTRL, 0x0E); /* display on with non-blinking cursor */
	lcd_cmd(LCD_CTRL, 0x06); /* entry mode: auto-increment */
	lcd_clear();
}

void lcd_printf(const char *fmt, ...)
{
	va_list values;
	char buf[92];

	va_start(values, fmt);
	vsnprintf(buf, 91, fmt, values);
	va_end(values);
	lcd_print(buf);
}

void lcd_print(const char *str)
{
	while (*str) {
		if (*str == '\n')
			lcd_cmd(LCD_CTRL, 0xC0);
		else
			lcd_cmd(LCD_DISP, *str);
		str++;
	}
}

void lcd_clear()
{
	lcd_cmd(LCD_CTRL, 0x01);
	_delay_ms(2);
}

void lcd_cmd(unsigned char rs, unsigned char data)
{
	_delay_us(25);
	if (rs)
		LCD_CTRL_PORT |= 1 << LCD_REGSEL;
	else
		LCD_CTRL_PORT &= ~(1 << LCD_REGSEL);
	LCD_DATA_PORT = data;
	LCD_CTRL_PORT |= 1 << LCD_ENABLE;
	_delay_us(1);
	LCD_CTRL_PORT &= ~(1 << LCD_ENABLE);
}
