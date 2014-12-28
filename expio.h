/* expio.h
 * 	The purpose of this API is to hide the frame-level details
 * of SPI communication with the MCP23S17 I/O Expanders, allowing
 * them to be viewed as collections of registers accessible though
 * simple functions.
 */

#ifndef _EXPIO_H
#define _EXPIO_H

/* MCP23S17 register addresses */
#define EXPIO_IOCON	0x0A
#define EXPIO_IODIRA	0x00
#define EXPIO_IODIRB	0x01
#define EXPIO_GPIOA	0x12
#define EXPIO_GPIOB	0x13

void expio_init(unsigned char cs);
unsigned char expio_read(unsigned char cs, unsigned char reg);
unsigned int expio_wideread(unsigned char cs, unsigned char reg);
void expio_write(unsigned char cs, unsigned char reg, unsigned char data);
void expio_widewrite(unsigned char cs, unsigned char reg, unsigned int data);

#endif /* _EXPIO_H */
