/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:55:01 by szaghdad          #+#    #+#             */
/*   Updated: 2024/06/07 00:41:32 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long int nb, int upperlowercase)
{
	char	*hexa;
	int		i;

	i = 0;
	if (!upperlowercase)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nb == 0)
	{
		ft_putchar('0');
		i++;
		return (i);
	}
	if (nb >= 16)
	{
		i += ft_puthex(nb / 16, upperlowercase);
	}
	i += ft_putchar(hexa[nb % 16]);
	return (i);
}
