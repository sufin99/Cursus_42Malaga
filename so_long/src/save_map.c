/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:34:34 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:37 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_maperror(t_data *data, char *line, int fd)
{
	if (line != NULL)
		free(line);
	close(fd);
	ft_error(data, "Error: No se ha guardado el mapa.\n");
}

char	**resize_map(t_data *data)
{
	char	**new_map;
	int		i;

	data->map_ct *= 2;
	new_map = (char **)malloc(sizeof(char *) * (data->map_ct + 1));
	if (!new_map)
		return (NULL);
	i = -1;
	while (i++ < data->map_sz)
		new_map[i] = data->map[i];
	free(data->map);
	return (new_map);
}

void	ft_loop_aux(t_data *data, int fd, char *line)
{
	while (line != NULL)
	{
		if (data->map_sz >= data->map_ct)
		{
			data->map = resize_map(data);
			if (!data->map)
				free_maperror(data, line, fd);
		}
		data->map[data->map_sz] = line;
		data->map_sz++;
		line = get_next_line(fd);
	}
}

void	save_map(char *str, t_data *data)
{
	int		fd;
	char	*line;

	data->map_ct = 10;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error(data, "Error: No se ha abierto correctamente el archivo.\n");
	data->map = (char **)malloc(sizeof(char *) * (data->map_ct + 1));
	if (!data->map)
		free_maperror(data, NULL, fd);
	line = get_next_line(fd);
	if (line == NULL)
		ft_error(data, "Error: Vacío.\n");
	data->len_line = ft_strlen(line);
	ft_loop_aux(data, fd, line);
	data->map[data->map_sz] = NULL;
	close (fd);
}
