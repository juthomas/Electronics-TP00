#include <avr/io.h>
#define PIN3 3

int main()
{
    DDRB |= (1 << PIN3);
    PORTB |= (1 << PIN3);
    return (0);
}