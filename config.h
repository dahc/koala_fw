/* config.h
 *	This file defines configuration items like clock settings,
 * pin assignments, and other configurable hardware details. It can
 * also be relied upon for inclusion of util/delay.h (this makes it
 * simple to guarantee F_CPU is defined before delay.h is read).
 *	As a clarification of scope: things specified in datasheets
 * do not belong here.
 */

#ifndef _CONFIG_H
#define _CONFIG_H

#include <avr/io.h>

/* Clock frequency to be assumed by delay code */
#define F_CPU 1e6
#include <util/delay.h>

/* I/O expansion chip-select configuration */
#define EXPIO_PORT	PORTB
#define EXPIO_DDR	DDRB
#define EXPIO_DATA	PB1
#define EXPIO_LADDR	PB2

/* LCD pin assignments */
#define LCD_DATA_DDR	DDRA
#define LCD_DATA_PORT	PORTA
#define LCD_CTRL_DDR	DDRC
#define LCD_CTRL_PORT	PORTC
#define LCD_ENABLE	PC7
#define LCD_REGSEL	PC6

#endif /* _CONFIG_H */
