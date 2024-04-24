/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:40:35 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/23 10:59:18 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* int	main(void)
{
	const char	phrse[] = "Auxixlio";
	const char	letter = 'x';
	char		*b;

	b = ft_strchr(phrse, letter);
	printf("La función ha encontrado: %s", b);
} */

/* La función imprrime el string desde que encuentra la primera
letra que se busca */