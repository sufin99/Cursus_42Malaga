#include "libftprintf.h"

int	main(void)
{
	char	car = 'f';
	char	str[20] = "auxilio";
	char	*ptr = "si";
	int		dec = 10;
	int		inte = 10;
	int		unsign = 123;
	int		hexlow = 343;
	int		hexupp = 453;

	printf("Este es un caracter: %c\n", car);
	printf("Este es una string: %s\n", str);
	printf("Este es un puntero: %p\n", ptr);
	printf("Este es un numero decimal: %d\n", dec);
	printf("Este es un entero: %i\n", inte);
	printf("Este es un numero decimal sin signo: %u\n", unsign);
	printf("Este es un hexadecimal minuscula: %x\n", hexlow);
	printf("Este es un hexadecimal mayuscula: %X\n", hexupp);
	printf("Este es un porcentaje: %%\n");
}
