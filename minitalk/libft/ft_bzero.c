/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:51:16 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/17 09:57:36 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*x;

	i = 0;
	x = (unsigned char *)s;
	while (i < n)
	{
		*x = 0;
		i++;
		x++;
	}
}

/* int	main(void)
{
	char	a[20] = "Auxilio";

	printf("Cadena antes del bzero: %s\n", a);
	ft_bzero(a, 3);
	printf("Cadena después del bzero: %s\n", a);
}
 */
/* Esta función sustituye n bytes por 0 */