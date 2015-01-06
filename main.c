#include <avr/io.h>

#include "config.h"
#include "lcd.h"
#include "sysbus.h"

unsigned int mem_read(unsigned long addr);
void mem_write(unsigned long addr, unsigned int data);

int main()
{
	int i;

	lcd_init();
	sysbus_init();
	MEM_CTRL_DDR |= (1 << MEM_CS) | (1 << MEM_OE) | (1 << MEM_WE);

	for (i = 0; i < 0x1000; i += 2)
		mem_write(i, i+1);

	for (i = 0; i < 0x1000; i += 2) {
		lcd_clear();
		lcd_printf("R 0x%06X: 0x%04X\n", i, mem_read(i));
		_delay_ms(1000);
	}

	return 0;
}

unsigned int mem_read(unsigned long addr)
{
	unsigned int data;

	sysbus_yielddata();
	sysbus_setaddr(addr);
	MEM_CTRL_PORT &= ~((1 << MEM_CS) | (1 << MEM_OE));
	data = sysbus_getdata();
	MEM_CTRL_PORT |= (1 << MEM_CS) | (1 << MEM_OE);

	return data;
}

void mem_write(unsigned long addr, unsigned int data)
{
	sysbus_setaddr(addr);
	sysbus_setdata(data);
	MEM_CTRL_PORT &= ~((1 << MEM_CS) | (1 << MEM_WE));
	MEM_CTRL_PORT |= (1 << MEM_CS) | (1 << MEM_WE);
}
