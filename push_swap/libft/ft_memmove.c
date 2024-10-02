/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:14:48 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:50:51 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src2;
	unsigned char	*dst2;
	size_t			i;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	i = 0;
	if (dst2 < src2 && (src != NULL || dst != NULL))
	{
		while (i < len)
		{
			dst2[i] = src2 [i];
			i++;
		}
	}
	else if (dst2 > src2 && (src != NULL || dst != NULL))
	{
		i = len;
		while (i != 0)
		{
			dst2[i - 1] = src2[i - 1];
			i--;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char	src2[50] = "Auxilio";
	char	dst2[50] = "socorro";

	printf("String original antes de memmove: %s\n", src2);
	printf("String de destino antes del memmove: %s\n", dst2);
	ft_memmove(dst2, src2, 3);
	printf("String original después de memmove: %s\n", src2);
	printf("String de destino después del memmove: %s\n", dst2);
}
 */
