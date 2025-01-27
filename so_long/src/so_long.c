/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:00:31 by szaghdad          #+#    #+#             */
/*   Updated: 2025/01/27 19:20:48 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**save_map(char **argv, int map_sz)
{
	int		fd;
	char	**map;
	char	*line;
	int		map_ct;

	map_ct = 10;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (map_ct + 1));
	if (!map)
	{
		ft_putstr_fd("Error\n", 2);
		close (fd);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map_sz >= map_ct)
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			close(fd);
			while (map_sz > 0)
			{
				map_sz--;
				free (map[map_sz]);
			}
			free(map);
			return (NULL);
		}
		map[map_sz] = line;
		map_sz++;
		line = get_next_line(fd);
	}
	map[map_sz] = NULL;
	close (fd);
	return (map);
}

int	main(int argc, char *argv[])
{
	char	**map;
	int		map_sz;
	int		i;

	map_sz = 0;
	if (argc == 2)
	{
		map = save_map(&argv[1], map_sz);
		i = 0;
		while (i < map_sz)
		{
			ft_printf(map[i]);
			free(map[i]);
			i++;
		}
		free(map);
	}
	else
	{
		ft_putstr_fd("Usa: ./so_long <*.ber>\n", 2);
		return (1);
	}
	return (0);
}
