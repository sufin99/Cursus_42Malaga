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

void	ft_compare_and_path(t_data *data, t_point *size, t_point *start)
{
	if (data->count_p != 1)
		ft_error(data, "Error\n");
	if (data->count_e != 1)
		ft_error(data, "Error\n");
	if (data->count_c <= 0)
		ft_error(data, "Error\n");
	/* ft_printf("si\n"); */
	if (data->count_p == 1)
	{
		size->x = data->len_line - 1;
		size->y = data->map_sz;
		if (!check_path(data->map, *size, *start, data))
			ft_error(data, "Error\n");
	}
}

void	count_char(t_data *data, t_point *start, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		data->count_p++;
		start->x = j;
		start->y = i;
	}
	else if (data->map[i][j] == 'E')
		data->count_e++;
	else if (data->map[i][j] == 'C')
		data->count_c++;
}

void	error_otherchar(t_data *data, int i, int j)
{
	if (data->map[i][j] != 'P' && data->map[i][j] != 'E' && data->map[i][j] != 'C' && data->map[i][j] != '1' && data->map[i][j] != '0')
		ft_error(data, "Error\n");
	if (data->map[0][j] != '1' || data->map[data->map_sz - 1][j] != '1')
		ft_error(data, "Error\n");
	if (data->map[i][0] != '1' || data->map[i][data->len_line - 2] != '1')
		ft_error(data, "Error\n");
}

void	ft_parsing(t_data *data)
{
	int			i;
	int			j;
	t_point		size;
	t_point		start;

	ft_memset(&size, 0, sizeof(t_point));
	ft_memset(&start, 0, sizeof(t_point));
	i = 0;
	ft_printf("%d %d\n", data->len_line, data->map_sz);
	while (i < data->map_sz)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			/* ft_printf("Checking character at [%d][%d]: %c\n", i, j, data->map[i][j]); */
			error_otherchar(data, i, j);
			count_char(data, &start, i, j);
			j++;
		}
		/* ft_printf("%d\n", j); */
		if (data->len_line - 1 != j)
			ft_error(data, "Error\n");
		i++;
	}
	ft_compare_and_path(data, &size, &start);
}
