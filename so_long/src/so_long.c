/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:00:31 by szaghdad          #+#    #+#             */
/*   Updated: 2025/01/29 18:07:08 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	save_map(char *str, t_data *data)
{
	int		fd;
	char	**new_map;
	char	*line;
	int		i;

	data->map_ct = 10;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	data->map = (char **)malloc(sizeof(char *) * (data->map_ct + 1));
	if (!data->map)
	{
		ft_putstr_fd("Error\n", 2);
		close (fd);
		exit(1);
	}
	line = get_next_line(fd);
	if (line == NULL)
		ft_error(data, "Error\n");
	data->len_line = ft_strlen(line);
	while (line != NULL)
	{
		if (data->map_sz >= data->map_ct)
		{
			data->map_ct *= 2;
			new_map = (char **)malloc(sizeof(char *) * (data->map_ct + 1));
			if (!new_map)
			{
				ft_putstr_fd("Error\n", 2);
				free(line);
				close(fd);
				while (data->map_sz > 0)
				{
					data->map_sz--;
					free (data->map[data->map_sz]);
				}
				free(data->map);
				return ;
			}
			i = -1;
			while (i++ < data->map_sz)
				new_map[i] = data->map[i];
			free(data->map);
			data->map = new_map;
		}
		data->map[data->map_sz] = line;
		data->map_sz++;
		line = get_next_line(fd);
	}
	data->map[data->map_sz] = NULL;
	close (fd);
	i = 0;
	while (i < data->map_sz)
	{
		ft_printf(data->map[i]);
		/*free(data->map[i]);*/
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
			free(data.map);
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	else
	{
		ft_putstr_fd("Usa: ./so_long <*.ber>\n", 2);
		return (1);
	}
	/*ft_printf("%d\n", data.map_sz);*/
	return (0);
}
