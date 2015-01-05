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

/* Memory control pin assignments */
#define MEM_CTRL_DDR	DDRD
#define MEM_CTRL_PORT	PORTD
#define MEM_CS		PD4
#define MEM_OE		PD3
#define MEM_WE		PD2

/* I/O expansion chip-select configuration */
#define EXPIO_PORT	PORTB
#define EXPIO_DDR	DDRB
#define EXPIO_DATA	PB1
#define EXPIO_LADDR	PB2

/* High address byte (A17+) configuration */
#define HADDR_DDR	DDRA
#define HADDR_PORT	PORTA
#define HADDR_PIN	PINA
#define HADDR_CTRL_DDR	DDRC
#define HADDR_CTRL_PORT	PORTC
#define HADDR_DIR	PC2
#define HADDR_OE	PC3

/* LCD pin assignments */
#define LCD_DATA_DDR	DDRA
#define LCD_DATA_PORT	PORTA
#define LCD_CTRL_DDR	DDRC
#define LCD_CTRL_PORT	PORTC
#define LCD_ENABLE	PC7
#define LCD_REGSEL	PC6

#endif /* _CONFIG_H */
