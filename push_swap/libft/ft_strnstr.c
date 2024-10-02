/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:32:02 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:49:56 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	if (*needle == '\0')
		return ((char *)haystack);
	return (NULL);
}

/* int	main(void)
{
	const char	total[] = "Auxiliomedesmayo";
	const char	locator[] = "me";
	char		*a;

	a = ft_strnstr(total, locator, 20);
	printf("La función ha encontrado: %s", a);
} */
