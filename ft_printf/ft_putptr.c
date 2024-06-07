/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:02:32 by szaghdad          #+#    #+#             */
/*   Updated: 2024/06/07 12:22:49 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long int	valptr;
	int						hex;

	valptr = (unsigned long long int)ptr;
	ft_putstr("0x");
	hex = ft_puthex(valptr, 1);
	return (hex + 2);
}
