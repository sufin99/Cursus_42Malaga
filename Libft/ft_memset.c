/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:35:25 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/16 12:51:45 by szaghdad         ###   ########.fr       */
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
/*Esta función sirve para llenar un bloque de memoria con un valor específico
sin sobreescribir el original:
void *b: este es el puntero que señala al bloque de memoriq que quiero llenar
int c: este es lo que quiero poner en el bloque de memoria
size_t len: este es el número de bytes que quiero llenar del bloque de memoria*/