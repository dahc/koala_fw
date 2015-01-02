#include <avr/io.h>

#include "config.h"
#include "expio.h"
#include "lcd.h"
#include "spi.h"

int main()
{
	lcd_init();

	lcd_print("A");

	return 0;
}
