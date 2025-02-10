/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:02:17 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 18:54:32 by szaghdad         ###   ########.fr       */
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
# include "./MLX42/include/MLX42/MLX42.h"
# define T_SIZE 48

typedef struct s_mlx_data
{
	mlx_t			*init;
	mlx_image_t		*img_p;
	mlx_image_t		*img_e;
	mlx_image_t		*img_c;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture_p;
	mlx_texture_t	*texture_e;
	mlx_texture_t	*texture_c;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_wall;
}					t_mlx;

typedef struct s_player
{
	int			player_x;
	int			player_y;
}				t_player;

typedef struct s_data
{
	char		**map;
	int			map_sz;
	int			map_ct;
	int			len_line;
	int			count_p;
	int			count_e;
	int			count_c;
	int			**visited;
	int			rec_c;
	int			count_mov;
	t_player	player;
	t_mlx		mlx;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

void	save_map(char *str, t_data *data);
void	ft_parsing(t_data *data);

int		ft_error(t_data	*data, char *str);
void	ft_freeall(t_data *data);
void	ft_cleanup(t_data *data);
void	ft_close_hook(void *param);

int		check_path(char **map, t_point size, t_point start, t_data	*data);

void	ft_init_mlx(t_data *data);
void	ft_draw_map(t_data *data);
void	draw_cell(t_data *data, char cell, int x, int y);

void	ft_key_hook(mlx_key_data_t keydata, void *param);

#endif
