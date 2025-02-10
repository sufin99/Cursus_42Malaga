/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx42.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:51:33 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/08 19:51:33 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_close_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_cleanup(data);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx.init = mlx_init(data->len_line * T_SIZE,
			data->map_sz * T_SIZE, "so_long", true);
	if (!data->mlx.init)
		ft_error(data, "Error: No se ha iniciado MLX.\n");
	data->mlx.texture_p = mlx_load_png("./img/p_sp.png");
	data->mlx.texture_e = mlx_load_png("./img/e_sp.png");
	data->mlx.texture_c = mlx_load_png("./img/c_sp.png");
	data->mlx.texture_floor = mlx_load_png("./img/f_sp.png");
	data->mlx.texture_wall = mlx_load_png("./img/w_sp.png");
	data->mlx.img_p = mlx_texture_to_image(data->mlx.init, data->mlx.texture_p);
	data->mlx.img_e = mlx_texture_to_image(data->mlx.init, data->mlx.texture_e);
	data->mlx.img_c = mlx_texture_to_image(data->mlx.init, data->mlx.texture_c);
	data->mlx.img_floor = mlx_texture_to_image(data->mlx.init,
			data->mlx.texture_floor);
	data->mlx.img_wall = mlx_texture_to_image(data->mlx.init,
			data->mlx.texture_wall);
	mlx_close_hook(data->mlx.init, ft_close_hook, data);
	mlx_key_hook(data->mlx.init, ft_key_hook, data);
}

void	draw_cell(t_data *data, char cell, int x, int y)
{
	if (cell == '1')
		mlx_image_to_window(data->mlx.init,
			data->mlx.img_wall, x, y);
	else if (cell == '0')
		mlx_image_to_window(data->mlx.init,
			data->mlx.img_floor, x, y);
	else if (cell == 'P')
		mlx_image_to_window(data->mlx.init,
			data->mlx.img_p, x, y);
	else if (cell == 'E')
		mlx_image_to_window(data->mlx.init,
			data->mlx.img_e, x, y);
	else if (cell == 'C')
		mlx_image_to_window(data->mlx.init,
			data->mlx.img_c, x, y);
}

void	ft_draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_sz)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			draw_cell(data, data->map[i][j], j * T_SIZE, i * T_SIZE);
			j++;
		}
		i++;
	}
}
