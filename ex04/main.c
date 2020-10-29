#include <avr/io.h>
#define CPU_CLOCK 2000000

void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

void	custom_delay(uint32_t milli)
{
	//milli = 0,001s
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}

int		main()
{
	DDRB |= (1 << 3);
	DDRD = 0b00000000;
	PORTB = 0b00000000;

	for(;;)
	{
		if (!(PIND & (1 << 3)))
		{
			PORTB |= (1 << 3);
		}
		else
		{
			PORTB &= ~(1 << 3);
		}
	}
	return (0);
}