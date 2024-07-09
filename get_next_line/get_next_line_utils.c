/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:38:13 by szaghdad          #+#    #+#             */
/*   Updated: 2024/07/09 19:44:42 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;

	x = (unsigned char *)b;
	while (len--)
		*x++ = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total;
	void	*reserve;

	total = num * size;
	reserve = malloc(total);
	if (!reserve)
		return (NULL);
	ft_memset(reserve, 0, total);
	return (reserve);
}
