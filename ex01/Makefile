FILENAME	= main
PORT		= /dev/cu.SLAB_USBtoUART
DEVICE		= atmega328p
PROGRAMMER	= arduino
BAUD		= 115200
F_CPU		= 16000000 #16 Mhz quartz
COMPILE		= avr-gcc -Wall -mmcu=$(DEVICE) -DF_CPU=${F_CPU}
COLOR		= \0033[1;35m

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
	@echo "\0033[1;32m\033[3C    Take Your Coffee"
	@echo "\0033[1;32m\033[3CAnd Your Microcontroller"
	@echo "\0033[1;37m"

hex:
	@$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@$(COMPILE) -o $(FILENAME).bin $(FILENAME).o
	@echo "$(COLOR)Binary \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@avr-objcopy -j .text -j .data -O ihex $(FILENAME).bin $(FILENAME).hex
	@echo "$(COLOR)Satanic Circle \033[100D\033[40C\0033[1;32m[D̴̮̬͊̾r̶̟̫̿a̴̬̟͛̈́w̴̻̍̌ê̶̤̚d̴̛̟̺]\0033[1;37m"
	@avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).bin
	@echo "$(COLOR)Black Magic \033[100D\033[40C\0033[1;32m[I̶̢͇͎͉͙͒̉n̸̛͖̣͒̓͒̊͆̉͜v̶̰̉̀́̓͠ǒ̵̜̰̝̼̤͉k̴͎̠̪͙̐̈́̔͑̇e̶̖̰͘d̸̻͛͊̎̀͒̚]\0033[1;37m"

flash:
	@avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i
	@echo "$(COLOR)$(DEVICE) \033[100D\033[40C\0033[1;32m[Flashed]\0033[1;37m"

clean:
	@rm $(FILENAME).o
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Removed]\0033[1;37m"
	@rm $(FILENAME).bin
	@echo "$(COLOR)Binaries \033[100D\033[40C\0033[1;32m[Removed]\0033[1;37m"
	@rm $(FILENAME).hex
	@echo "$(COLOR)f̴̨͇̬͔̹̹͎̪͐͛̍̎͒͗̽̇̽ȯ̵̢̱̻̭̤̬̥̯̿̅̌͋̈̔̊́͝r̸͕͔̘̎̓͒b̵̡̡͇͖̭͎̭̪̱̻̻̻͖̑́ì̴̟̭̠͍͓̈͂d̷͚̰̟͎͕͓̠̪̳̲͎̫͌̐̎̈̔̀̎̃͝ḍ̴̪̦̻͕̠̒̀̈͆̂̚ͅe̴̩̺̍͌́ͅͅn̵̛͖͓̣̜̻̫̔͛̓̾̈̓̀́͝ ̴̟͉̎̏̏͌͌̒̃̈́̓̂̐̓͂̀̕k̶̨̭̱̲̞̪͓̟̗̼͍̦̗̦̏́͜ǹ̷͆͐̀̀͆̓͘̕͜͠͝o̴̡̡̨͉͔̬̪̪͚̝̎̐̈́̌̅͒̂w̸͉̗̣̅̔̐̏͆͌̈l̵̡̻̹͕͓̱̠͚̺͗̈́̽̅̔ͅę̴̧̛̰̞̙̯̝̖̠̻̣̖̹̺̦͒͗̎̔̈͊͊̈́́̔ḍ̸̨̺̟̲̗̠͈̭͎͖͖̰̠̽g̵̡̨͎̲̃̈́͋e̷̬̺̤̳̰̰̍̍͛̓͘ \033[100D\033[40C\0033[1;32m[Exortized]\0033[1;37m"