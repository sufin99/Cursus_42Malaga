/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:30:24 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/16 12:33:13 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((0141 <= c && c <= 0172) || (0101 <= c && 0132 >= c))
		return (1);
	return (0);
}

/* int	main(void)
{
	char	a;

	a = ft_isalpha('3');
	printf("%d", a);
}
 */
/* Imprime el abecedario minuscula y mayuscula */