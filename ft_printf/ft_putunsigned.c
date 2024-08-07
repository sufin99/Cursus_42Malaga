/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:42:52 by szaghdad          #+#    #+#             */
/*   Updated: 2024/08/06 21:17:48 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb, int first_moment)
{
	char	c;
	int		i;

	i = 0;
	if (nb == 0)
	{
		if (first_moment)
		{
			ft_putchar('0');
			i++;
		}
		return (i);
	}
	if (nb > 0)
	{
		i += ft_putunsigned(nb / 10, 0);
	}
	c = '0' + nb % 10;
	i += ft_putchar(c);
	return (i);
}
