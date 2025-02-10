/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:00:31 by szaghdad          #+#    #+#             */
/*   Updated: 2025/02/10 14:35:05 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*ext;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 2)
	{
		ext = ft_strrchr(argv[1], '.');
		if (ext && ft_strncmp(ext, ".ber", 4) == 0 && *(ext - 1) != '/')
		{
			save_map(argv[1], &data);
			ft_parsing(&data);
			ft_init_mlx(&data);
			ft_draw_map(&data);
			mlx_loop(data.mlx.init);
			ft_freeall(&data);
		}
		else
			ft_error(&data, "Error: Sólo <*.ber> permitido.\n");
	}
	else
		ft_error(&data, "Usa: ./so_long <*.ber>\n");
	return (0);
}
