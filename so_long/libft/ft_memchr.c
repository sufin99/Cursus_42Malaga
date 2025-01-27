/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:14:52 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/23 12:28:58 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	ch;

	i = 0;
	s2 = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (s2[i] == ch)
			return (s2 + i);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char		message[] = "Auxilio";
	const char		letter = 'x';
	char			*a;

	a = ft_memchr(message, letter, 4);
	printf("La letra ha sido: %s", a);
}
 */
/* Esta función busca la letra en el string hasta n caracteres */