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
#define F_CPU 8e6
#include <util/delay.h>

/* I/O expansion chip-select configuration */
#define EXPIO_PORT	PORTB
#define EXPIO_DDR	DDRB
#define EXPIO_DATA	PB1
#define EXPIO_LADDR	PB2
#define EXPIO_LCD	PB3

/* LCD pin assignments on GPIOB of EXPIO_LCD */
#define LCD_EN	0
#define LCD_RW	1
#define LCD_RS	2

/* Delay in milliseconds after clearing LCD */
#define LCD_CLRWAIT	5

#endif /* _CONFIG_H */
