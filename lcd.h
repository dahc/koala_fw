/* lcd.h
 *	This file provides an interface to HD44780 character LCD
 * connected in 8-bit mode according to the pin configuration
 * specified in config.h.
 */

#ifndef _LCD_H
#define _LCD_H

/* HD77480 register addresses */
#define LCD_CTRL	0
#define LCD_DISP	1

void lcd_init();
void lcd_printf(const char *fmt, ...);
void lcd_print(const char *str);
void lcd_clear();
void lcd_cmd(unsigned char rs, unsigned char data);

#endif /* _LCD_H */
