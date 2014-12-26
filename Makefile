all:
	avr-gcc -O2 -mmcu=atmega1284p -Wall -o fw.elf spi.c expio.c main.c
install:
	avrdude -p m1284p -P usb -c avrisp2 -U flash:w:fw.elf:e
expio_test:
	avr-gcc -O2 -mmcu=atmega1284p -Wall -o fw.elf spi.c expio.c expio_test.c
clean:
	rm -f fw.elf
