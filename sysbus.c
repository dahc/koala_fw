#include <avr/io.h>

#include "config.h"
#include "expio.h"
#include "spi.h"
#include "sysbus.h"

void sysbus_init()
{
	spi_init();
	expio_init(EXPIO_LADDR);
	expio_init(EXPIO_DATA);
	HADDR_CTRL_DDR |= (1 << HADDR_DIR) | (1 << HADDR_OE);
	sysbus_yieldaddr();
	sysbus_yielddata();
}

void sysbus_setaddr(unsigned long addr)
{
	expio_widewrite(EXPIO_LADDR, EXPIO_IODIRA, 0x0000);
	HADDR_DDR = 0xFF;
	HADDR_PORT = addr >> 16;
	HADDR_CTRL_PORT &= ~((1 << HADDR_DIR) | (1 << HADDR_OE));
	expio_widewrite(EXPIO_LADDR, EXPIO_GPIOA, (unsigned int) addr);
}

void sysbus_yieldaddr()
{
	expio_widewrite(EXPIO_LADDR, EXPIO_IODIRA, 0xFFFF);
	HADDR_CTRL_PORT |= 1 << HADDR_OE;
}

unsigned long sysbus_getaddr()
{
	unsigned long addr;

	HADDR_DDR = 0x00;
	HADDR_CTRL_PORT |= 1 << HADDR_DIR;
	HADDR_CTRL_PORT &= ~(1 << HADDR_OE);
	addr = expio_wideread(EXPIO_LADDR, EXPIO_GPIOA);
	addr |= (unsigned long) HADDR_PIN << 16;

	return addr;
}

void sysbus_setdata(unsigned int data)
{
	expio_widewrite(EXPIO_DATA, EXPIO_IODIRA, 0x0000);
	expio_widewrite(EXPIO_DATA, EXPIO_GPIOA, data);
}

void sysbus_yielddata()
{
	expio_widewrite(EXPIO_DATA, EXPIO_IODIRA, 0xFFFF);
}

unsigned int sysbus_getdata()
{
	return expio_wideread(EXPIO_DATA, EXPIO_GPIOA);
}
