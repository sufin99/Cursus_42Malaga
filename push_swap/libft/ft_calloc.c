/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:17:59 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/24 14:17:59 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	int	*arr = (int *)ft_calloc(10, sizeof(int));
	if (arr == NULL)
	{
		printf("Falló para asignar memoria\n");
		return (1);
	}	
	free(arr);
	return (0);
}*/
