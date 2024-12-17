/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:48:09 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/12 11:48:09 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_bubbleshort(t_data *data)
{
	int	tmp;
	int	i;
	int	j;
	int	notswap;

	j = 1;
	notswap = 0;
	while (j < data->num_count)
	{
		i = j - 1;
		if (data->numbers[i] > data->numbers[j])
		{
			tmp = data->numbers[i];
			data->numbers[i] = data->numbers[j];
			data->numbers[j] = tmp;
			j = 0;
			notswap = 0;
		}
		else if (notswap == (data->num_count - 1))
			break ;
		else
			notswap++;
		j++;
	}
	i = 0;
	while (i < data->num_count)
	{
		/*ft_printf("tmp: %d ", data->numbers[i]);*/
		i++;
	}
	/*ft_printf("\n");*/
}
