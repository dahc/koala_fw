/* sysbus.h
 *	TODO: stuff... Note get/put versus read/write...
 */

#ifndef _SYSBUS_H
#define _SYSBUS_H

void sysbus_init();
void sysbus_setaddr(unsigned long addr);
void sysbus_yieldaddr();
unsigned long sysbus_getaddr();
void sysbus_setdata(unsigned int data);
void sysbus_yielddata();
unsigned int sysbus_getdata();

#endif /* _SYSBUS_H */
