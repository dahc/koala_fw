/* lcd_test.c
 *	This file tests the the interface in lcd.h for an HD44780
 * LCD connected as defined in config.h by simply writing "Hello,
 * World!" to the display.
 */
#include "lcd.h"

int main()
{
	lcd_init();
	lcd_printf("Hello, World!");

	return 0;
}
