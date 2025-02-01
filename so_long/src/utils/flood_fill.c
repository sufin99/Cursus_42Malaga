/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:11:22 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/01 21:17:00 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	search_path(char **map, t_point size, t_point pos, t_data *data)
{
	int	i;

	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y
		|| map[pos.y][pos.x] == '1' || data->visited[pos.y][pos.x])
		return (0);
	data->visited[pos.y][pos.x] = 2;
	if (map[pos.y][pos.x] == 'C')
		data->count_c--;
	if (map[pos.y][pos.x] == 'E')
		data->count_e--;
	if (data->count_c == 0 && data->count_e == 0)
		return (1);
	t_point	directions[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	i = 0;
	while (i < 4)
	{
		t_point	new_pos = {pos.x + directions[i].x, pos.y + directions[i].y};
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
