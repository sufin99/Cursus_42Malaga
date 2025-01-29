/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:11:22 by szaghdad          #+#    #+#             */
/*   Updated: 2025/01/29 19:24:31 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

char	**make_area(char **zone, t_point size)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	new = (char **)malloc(sizeof(char *) * size.y + 1);
	if (!new)
		return (NULL);
	while (i < size.y)
	{
		j = 0;
		new[i] = (char *)malloc(size.x + 1);
		/* if (!new[i])
		{
			while (i > 0)
			{
				i--;
				free(new);
			}
			free(new);
			return (NULL);
		} */
		while (j < size.x)
		{
			new[i][j] = zone[i][j];
			j++;
		}
		new[i][size.x] = '\0';
		i++;
	}
	new[size.y] = NULL;
	return (new);
}
