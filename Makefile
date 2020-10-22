FILENAME   = main
PORT       = /dev/cu.usbserial-00000000
DEVICE     = atmega328p
PROGRAMMER = arduino
BAUD       = 115200
F_CPU      = 16000000 #16 Mhz quartz
COMPILE    = avr-gcc -Wall -Os -mmcu=$(DEVICE) -DF_CPU=${F_CPU}

all: hex flash

coffee: hex flash clean
	@echo ""
	@echo "         {"
	@echo "      {   }"
	@echo "       }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "    \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "   \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "   \0033[1;34m| -.._____..- |"
	@echo "   |             ;--."
	@echo "   |            (__  \ "
	@echo "   |             | )  )"
	@echo "   |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "   |             /  / "
	@echo "   |            (  / "
	@echo "   \             | "
	@echo "     -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3CTake Your Coffee"
	@echo "\0033[1;37m"

hex:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).bin $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).bin $(FILENAME).hex 
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).bin

flash:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).bin
	rm $(FILENAME).hex