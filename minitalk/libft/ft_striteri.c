/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:10:17 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/10 12:10:17 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	ft2_tolower(unsigned int i, char *c)
{
	i = 1;

	if (i % 2 != 0 && *c >= 'A' && *c <= 'Z')
		*c = *c + 32;
	else
		return ;
}

int	main(void)
{
	char	str[] = "AUXILIO";

	if (str != NULL)
	{
		printf("La cadena original es: %s\n", str);
		ft_striteri(str, ft2_tolower);
		printf("La cadena transformada es: %s\n", str);
	}
	else
	{
		printf("Error al transformar la cadena.\n");
	}
	return (0);
}*/
/* Sirve para aplicar la función en cada caracter
del string directamente sin crear una nueva string */