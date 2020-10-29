#include <avr/io.h>

int main()
{
	//On set la 3eme pin de DDRB sur output (Data DiRection B) 
	DDRB |= (1 << 3);
	//On set la valeur de sortie de la 3eme pin de DDRB sur l'etat logique 1
	PORTB |= (1 << 3);
	return (0);
}