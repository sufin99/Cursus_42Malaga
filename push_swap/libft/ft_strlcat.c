/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:42:43 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:50:16 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] != '\0' && i < dstsize - dst_len - 1)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}

/* int	main(void)
{
	char src2[] = "Auxiliomedesmayo";
	char dst2[] = "34534";
	int	a = ft_strlen(dst2);

	printf("Origen antes del strlcpy: %s\n", src2);
	printf("Destino antes del strlcpy: %s\n", dst2);
	printf("Longitud cadena antes del strlcpy: %i\n", a);
	a = ft_strlcat(dst2, src2, 3);
	printf("\n");
	printf("Origen después del strlcpy: %s\n", src2);
	printf("Destino después del strlcpy: %s\n", dst2);
	printf("Longitud cadena después del strlcpy: %i", a);
} */
