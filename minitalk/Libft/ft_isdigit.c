/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:52:24 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/16 12:32:04 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 0060 && c <= 0071)
		return (1);
	return (0);
}

/* int	main(void)
{
	char	a;

	a = ft_isdigit('!');
	printf("%d", a);
}
 */
/* Imprime los números */