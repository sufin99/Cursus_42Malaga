/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:54:25 by szaghdad          #+#    #+#             */
/*   Updated: 2025/01/28 20:54:25 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_ar(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

void	ft_free_mlx(t_data *data)
{
	if (data->mlx.img_p)
		mlx_delete_image(data->mlx.init, data->mlx.img_p);
	if (data->mlx.img_e)
		mlx_delete_image(data->mlx.init, data->mlx.img_e);
	if (data->mlx.img_c)
		mlx_delete_image(data->mlx.init, data->mlx.img_c);
	if (data->mlx.img_floor)
		mlx_delete_image(data->mlx.init, data->mlx.img_floor);
	if (data->mlx.img_wall)
		mlx_delete_image(data->mlx.init, data->mlx.img_wall);
	if (data->mlx.texture_p)
		mlx_delete_texture(data->mlx.texture_p);
	if (data->mlx.texture_e)
		mlx_delete_texture(data->mlx.texture_e);
	if (data->mlx.texture_c)
		mlx_delete_texture(data->mlx.texture_c);
	if (data->mlx.texture_floor)
		mlx_delete_texture(data->mlx.texture_floor);
	if (data->mlx.texture_wall)
		mlx_delete_texture(data->mlx.texture_wall);
	if (data->mlx.init)
		mlx_terminate(data->mlx.init);
}

void	ft_freeall(t_data *data)
{
	if (data->map)
		free_ar(data->map);
	ft_free_mlx(data);
	/*if (data->numbers)
		free(data->numbers);*/
}

void	ft_cleanup(t_data *data)
{
	ft_freeall(data);
	exit(1);
}

void	ft_close_hook(void *param)
{
	t_data *data;

	data = (t_data *)param;
	ft_cleanup(data);
}

int	ft_error(t_data	*data, char *str)
{
	ft_freeall(data);
	/*ft_freestacks(data);*/
	ft_putstr_fd(str, 2);
	exit(1);
}
