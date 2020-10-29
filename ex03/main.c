#include <avr/io.h>
#define CPU_CLOCK 2000000 // 16Mhz -> / 8 2Mhz

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
	//On set la 3eme pin de DDRB sur output (Data DiRection B) 
	DDRB |= (1 << 3);
	// DDRB |= (1 << 2);

	//On set la valeur de sortie de la 3eme pin de PORTB sur l'etat logique 0
	PORTB &= !(1 << 3);
	// PORTB |= (1 << 2);

	//Valeur de PORTB
	//PORTB = 0b00001000;

	for(;;)
	{
		custom_delay(500);
		// wait_x_cpu_clocks(1000000);
		//On inverse l'etat de la 3eme pin de PORTB a chaque passage
	 	PORTB ^= (1 << 3);
	}
	return (0);
}