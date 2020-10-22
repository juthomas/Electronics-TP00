#include <avr/io.h>
#define PIN3 3
#define CPU_CLOCK 16000000

void    wait_x_cpu_clocks(int cpu_clocks)
{
	while (cpu_clocks)
		cpu_clocks-=2;
}

void	custom_delay(int milli)
{
	//milli = 0,001s
	milli = milli *	16000;
	wait_x_cpu_clocks(milli - 2);
}

int		main()
{
	DDRB |= (1 << PIN3);
	while (true)
	{
		PORTB ^= (1 << PIN3);
		custom_delay(500);
	}
	return (0);
}