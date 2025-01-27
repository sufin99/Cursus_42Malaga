/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:24:28 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/16 17:12:00 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 0040 && c <= 0176)
		return (1);
	return (0);
}

/* int	main(void)
{
	char	a;

	a = ft_isprint('%');
	printf("%d", a);
}
 */
/* Imprime los caracteres imprimibles de ascii */