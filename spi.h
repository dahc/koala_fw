/* spi.h
 *	This file simply provides macros for the SPI hardware layout
 * on the ATmega1284P and similar AVR MCUs and a generic SPI master
 * initialization function.
 */
#ifndef _SPI_H
#define _SPI_H

#include <avr/io.h>

#define SPI_DDR		DDRB
#define SPI_SS		PB4
#define SPI_MOSI	PB5
#define SPI_SCLK	PB7

void spi_init();

#endif /* _SPI_H */
