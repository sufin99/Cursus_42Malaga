/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:39:28 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/10 11:39:28 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = strlen(s);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*str = "auxilio";
	char	*str2 = ft_strmapi(str, ft_tolower);

	if (str2 != NULL)
	{
		printf("La cadena original es: %s\n", str);
		printf("La cadena transformada es: %s\n", str2);
	}
	else
	{
		printf("Error al transformar la cadena.\n");
	}
	free(str2);
	return (0);
}*/
/* Sirve para aplicar una función a cada caracter de una
string creando un nuevo string con los resultados */