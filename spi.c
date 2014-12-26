#include <avr/io.h>

#include "spi.h"

void spi_init()
{
	SPI_DDR |= (1 << SPI_SCLK) | (1 << SPI_MOSI) | (1 << SPI_SS);
	SPCR = (1 << SPE) | (1 << MSTR);
	SPSR |= 1 << SPI2X;
}
