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
	DDRB |= (1 << 2);
	DDRB |= (1 << 1);
	DDRB |= (1 << 0);

	DDRD = 0b00000000;
	PORTB = 0b00000000;

	for(;;)
	{
		if (!(PIND & (1 << 3)))
		{
			while (!(PIND & (1 << 3)));
			PORTB = (PORTB & 0b00001111) == 0b00001111 ? PORTB & (0b11110000) : PORTB + 1;
			custom_delay(200);
		}
	}
	return (0);
}