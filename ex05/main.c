#include <avr/io.h>
#define CPU_CLOCK 2000000

void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

void	custom_delay(int32_t milli)
{
	//milli = 0,001s
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}

int		main()
{
	DDRB |= (1 << 3);
	//Reverse led
	// DDRB |= (1 << PIN2);
	DDRD = 0b00000000;


	for(;;)
	{
		if ((PIND & (1 << 3)))
		{
			//Reverse led
			// PORTB ^= (1 << PIN2);
			while ((PIND & (1 << 3)));
			PORTB ^= (1 << 3);
			custom_delay(200);
		}
		
	}
	return (0);
}