/* expio_test.c
 *	This tests the I/O expansion facilities in expio.h by setting
 * up the AVR in a tight loop forwarding all the GPIO inputs from one
 * MCP23S17 (EXPIO_DATA) to the corresponding outputs on another
 * (EXPIO_LADDR).
 *	The test assumes there are two MCP23S17s on the SPI bus with
 * chip selects configured as defined in expio.h with all address
 * pins tied low and RESET tied to the RESET on the AVR (allowing an
 * ISP programmer to remain attached to the AVR and reset everything
 * at once).
 */

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
