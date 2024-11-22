/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:31:11 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/18 11:46:40 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/* int	main(void)
{
	char src2[] = "Auxiliomedesmayo";
	char dst2[] = "34534";
	int a = ft_strlen(dst2);

	printf("Origen antes del strlcpy: %s\n", src2);
	printf("Destino antes del strlcpy: %s\n", dst2);
	printf("Longitud cadena antes del strlcpy: %i\n", a);
	a = ft_strlcpy(dst2, src2, 3);
	printf("\n");
	printf("Origen después del strlcpy: %s\n", src2);
	printf("Destino después del strlcpy: %s\n", dst2);
	printf("Longitud cadena después del strlcpy: %i", a);
}
 */
/* La función ft_strlcpy copia hasta dstsize - 1 (tamaño - 1) caracteres del
String de origen al string de destino gasarntizando que el final sea nulo '\0' */