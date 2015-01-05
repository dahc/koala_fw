all:
	avr-gcc -O2 -mmcu=atmega1284p -Wall -o fw.elf spi.c expio.c sysbus.c lcd.c main.c
install:
	avrdude -p m1284p -P usb -c avrisp2 -U flash:w:fw.elf:e
fuses:
	avrdude -p m1284p -P usb -c avrisp2 -U hfuse:w:0b11011001:m
expio_test:
	avr-gcc -O2 -mmcu=atmega1284p -Wall -o fw.elf spi.c expio.c expio_test.c
lcd_test:
	avr-gcc -O2 -mmcu=atmega1284p -Wall -o fw.elf lcd.c lcd_test.c
clean:
	rm -f fw.elf
