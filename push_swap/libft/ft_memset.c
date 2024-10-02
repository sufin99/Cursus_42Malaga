/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:35:25 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:50:48 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;

	x = (unsigned char *)b;
	while (len--)
		*x++ = (unsigned char)c;
	return (b);
}

/* int	main(void)
{
	char	a[50] = "Auxilio";

	printf("String antes del memset: %s\n", a);
	ft_memset(a, '.', 5);
	printf("String despues del memset: %s\n", a);
}
 */
