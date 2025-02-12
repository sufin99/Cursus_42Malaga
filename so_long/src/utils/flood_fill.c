/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:11:22 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/12 11:58:28 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_valid_move(char **map, t_point size, t_point pos, t_data *data)
{
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y
		|| map[pos.y][pos.x] == '1' || data->visited[pos.y][pos.x])
		return (0);
	data->visited[pos.y][pos.x] = 2;
	if (map[pos.y][pos.x] == 'C')
		data->count_c--;
	if (map[pos.y][pos.x] == 'E')
		data->count_e--;
	return (1);
}

int	search_path(char **map, t_point size, t_point pos, t_data *data)
{
	t_point	directions[4];
	t_point	new_pos;
	int		i;

	directions[0] = (t_point){0, 1};
	directions[1] = (t_point){1, 0};
	directions[2] = (t_point){0, -1};
	directions[3] = (t_point){-1, 0};
	if (!is_valid_move(map, size, pos, data))
		return (0);
	if (data->count_c == 0 && data->count_e == 0)
		return (1);
	else if (data->count_c != 0 && data->count_e == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		new_pos.x = pos.x + directions[i].x;
		new_pos.y = pos.y + directions[i].y;
		if (search_path(map, size, new_pos, data))
			return (1);
		i++;
	}
	return (0);
}

int	check_path(char **map, t_point size, t_point start, t_data	*data)
{
	t_data	data_copy;
	int		**visited;
	int		result;
	int		i;

	visited = (int **)malloc(sizeof(int *) * size.y);
	i = 0;
	while (i < size.y)
	{
		visited[i] = (int *)malloc(sizeof(int) * size.x);
		ft_memset(visited[i], 0, sizeof(int) * size.x);
		i++;
	}
	data->visited = visited;
	data_copy = *data;
	result = search_path(map, size, start, &data_copy);
	i = 0;
	while (i < size.y)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (result);
}
