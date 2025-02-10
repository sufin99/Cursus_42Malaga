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
		ft_error(data, "Error: Sólo una 'P' permitida.\n");
	if (data->count_e != 1)
		ft_error(data, "Error: Sólo una 'E' permitida.\n");
	if (data->count_c <= 0)
		ft_error(data, "Error: Mínimo una 'C'.\n");
	if (data->count_p == 1)
	{
		size->x = data->len_line - 1;
		size->y = data->map_sz;
		if (!check_path(data->map, *size, *start, data))
			ft_error(data, "Error: No hay camino válido.\n");
	}
}

void	count_char(t_data *data, t_point *start, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		data->count_p++;
		start->x = j;
		start->y = i;
		data->player.player_x = j;
		data->player.player_y = i;
	}
	else if (data->map[i][j] == 'E')
		data->count_e++;
	else if (data->map[i][j] == 'C')
		data->count_c++;
}

void	error_otherchar(t_data *data, int i, int j)
{
	if (data->map[i][j] != 'P' && data->map[i][j] != 'E'
		&& data->map[i][j] != 'C' && data->map[i][j] != '1'
			&& data->map[i][j] != '0')
		ft_error(data, "Error: Carácteres Prohibidos.\n");
	if (data->map_sz - 1 == data->len_line - 2)
		ft_error(data, "Error: Tiene que ser rectángulo.\n");
	if (i == 0 || i == data->map_sz - 1)
	{
		if (data->map[i][j] != '1')
			ft_error(data, "Error: Muros no rodeados.\n");
	}
	if (j == 0 || j == data->len_line - 2)
	{
		if (data->map[i][j] != '1')
			ft_error(data, "Error: Muros no rodeados.\n");
	}
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
			error_otherchar(data, i, j);
			count_char(data, &start, i, j);
			j++;
		}
		if (data->len_line - 1 != j)
			ft_error(data, "Error: Las líneas no son del mismo tamaño.\n");
		i++;
	}
	ft_compare_and_path(data, &size, &start);
}
