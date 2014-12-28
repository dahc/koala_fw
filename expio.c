#include <avr/io.h>

#include "config.h"
#include "expio.h"

/* Fixed, hidden MCP23S17 details */
#define READ_OPCODE	0x41
#define WRITE_OPCODE	0x40
#define IOCON_SEQOP	0x05
#define DONTCARE	0x00

/* Not in spi.h for performance reasons: needs to be inlined */
static inline unsigned char spi_transceive(unsigned char out);

void expio_init(unsigned char cs)
{
	EXPIO_DDR |= 1 << cs;
	EXPIO_PORT |= 1 << cs;
	expio_write(cs, EXPIO_IOCON, 1 << IOCON_SEQOP);
}

unsigned char expio_read(unsigned char cs, unsigned char reg)
{
	unsigned char data;

	EXPIO_PORT &= ~(1 << cs);
	spi_transceive(READ_OPCODE);
	spi_transceive(reg);
	data = spi_transceive(DONTCARE);
	EXPIO_PORT |= 1 << cs;

	return data;
}

void expio_write(unsigned char cs, unsigned char reg, unsigned char data)
{
	EXPIO_PORT &= ~(1 << cs);
	spi_transceive(WRITE_OPCODE);
	spi_transceive(reg);
	spi_transceive(data);
	EXPIO_PORT |= 1 << cs;
}

unsigned int expio_wideread(unsigned char cs, unsigned char reg)
{
	unsigned int data;

	EXPIO_PORT &= ~(1 << cs);
	spi_transceive(READ_OPCODE);
	spi_transceive(reg);
	data = spi_transceive(DONTCARE);
	data |= spi_transceive(DONTCARE) << 8;
	EXPIO_PORT |= 1 << cs;

	return data;
}

void expio_widewrite(unsigned char cs, unsigned char reg, unsigned int data)
{
	EXPIO_PORT &= ~(1 << cs);
	spi_transceive(WRITE_OPCODE);
	spi_transceive(reg);
	spi_transceive((unsigned char) data);
	spi_transceive((unsigned char) (data >> 8));
	EXPIO_PORT |= 1 << cs;
}

static inline unsigned char spi_transceive(unsigned char out)
{
	SPDR = out;
	while (!(SPSR & (1 << SPIF)))
		/* do nothing */;

	return SPDR;
}
