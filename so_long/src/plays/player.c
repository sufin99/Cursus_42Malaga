/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:17:10 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/09 22:17:10 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_end_game(t_data *data)
{
	ft_printf("¡Has ganado!\n");
	ft_freeall(data);
	exit(1);
}

void	ft_move_player(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] != '1')
	{
		if (data->map[new_y][new_x] == 'C')
		{
			data->rec_c++;
			ft_printf("Te faltan %d coleccionables.\n", data->count_c - data->rec_c);
		}
		if (data->map[new_y][new_x] == 'E')
		{
			if (data->rec_c == data->count_c)
				ft_end_game(data);
			else
			{
				ft_printf("Todavía te faltan coleccionables.\n");
				return ;
			}
		}
		data->map[data->player.player_y][data->player.player_x] = '0';
		data->player.player_x = new_x;
		data->player.player_y = new_y;
		data->map[data->player.player_y][data->player.player_x] = 'P';
		data->count_mov++;
		ft_printf("Número de movimientos: %d.\n", data->count_mov);
		ft_draw_map(data);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_cleanup(data);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_move_player(data, data->player.player_x, data->player.player_y - 1);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_move_player(data, data->player.player_x - 1, data->player.player_y);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_move_player(data, data->player.player_x, data->player.player_y + 1);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_move_player(data, data->player.player_x + 1, data->player.player_y);
}
