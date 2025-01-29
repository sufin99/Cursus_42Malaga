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
	ft_printf("%d %d\n", data->len_line, data->map_sz);
	while (i < data->map_sz)
	{
		j = 0;
		while (data->map[i][j] != '\n')
		{
			/* ft_printf("Checking character at [%d][%d]: %c\n", i, j, data->map[i][j]); */
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E' && data->map[i][j] != 'C' && data->map[i][j] != '1' && data->map[i][j] != '0')
			{
				/* ft_printf("si%d\n", i); */
				ft_error(data, "Error\n");
			}
			if (data->map[0][j] != '1' || data->map[data->map_sz - 1][j] != '1')
				ft_error(data, "Error\n");
			if (data->map[i][0] != '1' || data->map[i][data->len_line - 2] != '1')
				ft_error(data, "Error\n");
			if (data->map[i][j] == 'P')
				data->count_p++;
			else if (data->map[i][j] == 'E')
				data->count_e++;
			else if (data->map[i][j] == 'C')
				data->count_c++;
			j++;
		}
		/* ft_printf("%d\n", j); */
		if (data->len_line - 1 != j)
			ft_error(data, "Error\n");
		i++;
	}
	if (data->count_p != 1)
		ft_error(data, "Error\n");
	if (data->count_e != 1)
		ft_error(data, "Error\n");
	if (data->count_c <= 0)
		ft_error(data, "Error\n");
	/* ft_printf("si\n"); */
}
