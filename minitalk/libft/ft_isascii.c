/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:26:07 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/16 12:32:23 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && 0177 >= c)
		return (1);
	return (0);
}

/* int	main(void)
{
	char	a;

	a = '?';
	printf("%d", ft_isascii(a));
}
 */
/* Imprime todos losc carácteres ascii */