FILENAME   = main
PORT       = /dev/cu.usbserial-00000000
DEVICE     = atmega328p
PROGRAMMER = arduino
BAUD       = 115200
F_CPU = 16000000
COMPILE    = avr-gcc -Wall -Os -mmcu=$(DEVICE) -DF_CPU=${F_CPU}

all: hex flash

coffee: hex flash clean

hex:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex 
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

flash:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex