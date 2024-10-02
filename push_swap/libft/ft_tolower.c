/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:30:48 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:49:41 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 0101 && c <= 0132)
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}

/* int	main(void)
{
	char	a;
	char	b;

	a = 'P';
	printf("Letra antes del tolower: %c\n", a);
	b = ft_tolower(a);
	printf("Letra después del tolower: %c\n", b);
}
 */
