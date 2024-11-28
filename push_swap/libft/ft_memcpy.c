/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:01:44 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/23 08:16:31 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dst2;
	size_t			i;

	if (src != NULL || dst != NULL)
	{
		src2 = (unsigned char *)src;
		dst2 = (unsigned char *)dst;
		i = 0;
		while (i < n)
		{
			dst2[i] = src2 [i];
			i++;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char	src2[50] = "Auxilio";
	char	dst2[50] = "socorro";

	printf("String original antes de memcpy: %s\n", src2);
	printf("String de destino antes del memcpy: %s\n", dst2);
	ft_memcpy(dst2, src2, 3);
	printf("String original después de memcpy: %s\n", src2);
	printf("String de destino después del memcpy: %s\n", dst2);
} */

/* La función memcpy copia n bytes de la memoria apuntada del origen 
(src) a la memoria apuntada del destino (dst) */
/*  {*dst2 = *src2;
	dst2++;
	src2++;
	i++;}     
	es igual a: 
	{dst2[i] = src[i];
	i++;}*/