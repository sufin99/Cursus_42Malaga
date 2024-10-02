/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:50:51 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:51:02 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	while (i < n && s1 && s2)
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	if (i < n)
		return (s3[i] - s4[i]);
	return (0);
}

/* int	main(void)
{
	const char		message[] = "Auxilio";
	const char		message2[] = "Socorro";
	int			a;

	a = ft_memcmp(message, message2, 4);
	printf("La letra ha sido: %d", a);
} */
