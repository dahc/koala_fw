#include <avr/io.h>

#include "spi.h"
#include "expio.h"

int main()
{
	unsigned int a;

	spi_init();
	expio_init(EXPIO_DATA);
	expio_init(EXPIO_LADDR);
	expio_widewrite(EXPIO_LADDR, EXPIO_IODIRA, 0x00);

	for (;;) {
		a = expio_wideread(EXPIO_DATA, EXPIO_GPIOA);
		expio_widewrite(EXPIO_LADDR, EXPIO_GPIOA, a);
	}

	return 0;
}
