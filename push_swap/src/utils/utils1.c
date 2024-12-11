/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:21 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/11 20:53:25 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	if (data->nums_str)
		free_ar(data->nums_str);
	if (data->numbers)
		free(data->numbers);
}

int	ft_error(t_data	*data, char *str)
{
	ft_freeall(data);
	ft_printf("%s", str);
	exit(1);
}
