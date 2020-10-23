#include <avr/io.h>
#define PIN3 3
#define PIN2 2
#define CPU_CLOCK 2000000


void	wait_x_cpu_clocks2(int cpu_clocks)
{
	while (cpu_clocks > 0)
	{

		// NOP();
		cpu_clocks-=1;
		//wait_x_cpu_clocks(10000);
	}
}

void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{

		// NOP();
		cpu_clocks-=3;
		// wait_x_cpu_clocks2(10000);
	}
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
	// DDRD &= (0 << PIN3);
	DDRD = 0b00000000;

	// DDRB |= (1 << PIN2);
	PORTB &= (0 << PIN3);
	// PORTB |= (1 << PIN2);

	// PORTD = 0b00000000;

	for(;;)
	{
		if (!(PIND & (1 << PIN3)))
		{
			// PORTB = 0b00000000;
			PORTB ^= (1 << PIN3);
			wait_x_cpu_clocks(500000);
		}

		
	}
	return (0);
}