/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:24 by szaghdad          #+#    #+#             */
/*   Updated: 2024/06/07 13:01:44 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_convert_var(char format, va_list listvar)
{
	size_t	conversion;

	if (format == 'c')
		conversion = ft_putchar(va_arg(listvar, int));
	else if (format == 's')
		conversion = ft_putstr(va_arg(listvar, char *));
	else if (format == 'p')
		conversion = ft_putptr(va_arg(listvar, void *));
	else if (format == 'd' || format == 'i')
		conversion = ft_putnbr(va_arg(listvar, int));
	else if (format == 'u')
		conversion = ft_putunsigned(va_arg(listvar, int), 1);
	else if (format == 'x')
		conversion = ft_puthex(va_arg(listvar, unsigned int), 0);
	else if (format == 'X')
		conversion = ft_puthex(va_arg(listvar, unsigned int), 1);
	else if (format == '%')
		conversion = ft_putchar('%');
	else
		return (1);
	return (conversion);
}

int	ft_printf(char const *format, ...)
{
	va_list	listvar;
	size_t	i;
	size_t	total;

	i = 0;
	total = 0;
	va_start (listvar, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total += ft_convert_var(format[i], listvar);
			i++;
		}
		else
		{
			total += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(listvar);
	return (total);
}
