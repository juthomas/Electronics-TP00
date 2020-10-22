#include <avr/io.h>
#define PIN3 3
#define CPU_CLOCK 16000000

void    wait_x_cpu_clocks(int cpu_clocks)
{
    while (cpu_clocks)
        cpu_clocks--;
}

int     main()
{
    DDRB |= (1 << PIN3);
    PORTB ^= (1 << PIN3);
    return (0);
}