#include <avr/io.h>
#define PIN3 3
#define PIN2 2
#define PIN1 1
#define PIN0 0
#define CPU_CLOCK 2000000

void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

void	custom_delay(int milli)
{
	//milli = 0,001s
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}

int		main()
{
	DDRB |= (1 << PIN3);
	DDRB |= (1 << PIN2);
	DDRB |= (1 << PIN1);
	DDRB |= (1 << PIN0);

	DDRD = 0b00000000;

	PORTB = 0b00000000;

	for(;;)
	{
		if (!(PIND & (1 << PIN3)))
		{
			while (!(PIND & (1 << PIN3)));
			PORTB = (PORTB & 0b00001111) == 0b00001111 ? PORTB & (0b11110000) : PORTB + 1;
			custom_delay(200);
		}
		
	}
	return (0);
}