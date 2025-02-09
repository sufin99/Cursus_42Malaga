/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:00:31 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/09 22:24:12 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	int		i;

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
	i = 0;
	while (i < data->map_sz)
	{
		ft_printf(data->map[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*ext;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 2)
	{
		ext = ft_strrchr(argv[1], '.');
		if (ext && strcmp(ext, ".ber") == 0)
		{
			save_map(argv[1], &data);
			ft_parsing(&data);
			ft_init_mlx(&data);
			ft_draw_map(&data);
			mlx_loop(data.mlx.init);
			/*ft_plays(&data);*/
			ft_freeall(&data);
		}
		else
			ft_error(&data, "Error: Sólo <*.ber> permitido.\n");
	}
	else
		ft_error(&data, "Usa: ./so_long <*.ber>\n");
	return (0);
}
