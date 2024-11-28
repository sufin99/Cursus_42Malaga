/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:46:54 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/23 10:59:50 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new;

	new = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			new = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		new = (char *)s;
	return (new);
}

/* int	main(void)
{
	const char	phrse[] = "Auxixlio";
	const char	letter = 'x';
	char		*b;

	b = ft_strrchr(phrse, letter);
	printf("La función ha encontrado: %s", b);
} */
/* La función imprrime el string desde que encuentra la ultima
letra que se busca */