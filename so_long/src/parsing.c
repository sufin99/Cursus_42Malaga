/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:57:36 by szaghdad          #+#    #+#             */
/*   Updated: 2025/01/28 20:57:36 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_parsing(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	/*ft_printf("%d %d\n", data->len_line, data->map_sz);*/
	while (i < data->map_sz)
	{
		j = 0;
		while (j < data->len_line - 1)
		{
			/*ft_printf("Checking character at [%d][%d]: %c\n", i, j, data->map[i][j]);*/
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E' && data->map[i][j] != 'C' && data->map[i][j] != '1' && data->map[i][j] != '0')
			{
				ft_error(data, "Error\n");
				/*ft_printf("si%d\n", i);*/
			}
			j++;
		}
		i++;
	}
	ft_printf("si\n");
}
