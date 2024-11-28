/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:43:41 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/23 11:14:19 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/* int	main(void)
{
	char	s3[] = "Auailio";
	char	s4[] = "Socorro";
	char	a;

	a = ft_strncmp(s3, s4, 3);
	printf("El valor de la comparación es: %d", a);
} */
/* Esta función compara 2 cadenas y devuelve un número igual,
mayor que o menos que dependiendo de la comparación hasta n caracteres. */