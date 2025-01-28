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

void	ft_freeall(t_data *data)
{
	if (data->map)
		free_ar(data->map);
	/*if (data->numbers)
		free(data->numbers);*/
}

/*void	ft_freestacks(t_data *data)
{
	t_stack	*aux;

	while (data->sa)
	{
		aux = data->sa;
		data->sa = data->sa->next;
		free(aux);
	}
	while (data->sb)
	{
		aux = data->sb;
		data->sb = data->sb->next;
		free(aux);
	}
}*/

int	ft_error(t_data	*data, char *str)
{
	ft_freeall(data);
	/*ft_freestacks(data);*/
	ft_putstr_fd(str, 2);
	exit(1);
}
