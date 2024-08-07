/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:11 by szaghdad          #+#    #+#             */
/*   Updated: 2024/08/06 21:29:27 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	car = 'f';
	char	*str = "auxilio";
	char	*ptr = "si";
	int		dec = 10;
	int		inte = 10;
	int		unsign = 123;
	int		hexlow = 185;
	int		hexupp = 453;
	char	porcent = '%';

	ft_printf("Este es un caracter: %c\n", car);
	ft_printf("Este es una string: %s\n", str);
	ft_printf("Este es un puntero: %p\n", ptr);
	ft_printf("Este es un numero decimal: %d\n", dec);
	ft_printf("Este es un entero: %i\n", inte);
	ft_printf("Este es un numero decimal sin signo: %u\n", unsign);
	ft_printf("Este es un hexadecimal minuscula: %x\n", hexlow);
	ft_printf("Este es un hexadecimal mayuscula: %X\n", hexupp);
	ft_printf("Este es un porcentaje: %%\n", porcent);
}
