/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:02:17 by szaghdad          #+#    #+#             */
/*   Updated: 2025/01/29 19:13:01 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line_bonus.h"

typedef struct s_data
{
	char		**map;
	int			map_sz;
	int			map_ct;
	int			len_line;
	int			count_p;
	int			count_e;
	int			count_c;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;


void	ft_parsing(t_data *data);

int		ft_error(t_data	*data, char *str);
void	flood_fill(char **tab, t_point size, t_point begin);

#endif
