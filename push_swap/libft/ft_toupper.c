/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:03:38 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:49:35 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 0141 && c <= 0172)
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}

/* int	main(void)
{
	char	a;
	char	b;

	a = 's';
	printf("Letra antes del toupper: %c\n", a);
	b = ft_toupper(a);
	printf("Letra después del toupper: %c\n", b);
}
 */
