/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:48:34 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/12 11:48:34 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_init_stack(t_data *data)
{
	t_stack	*aux;
	int		i;

	i = 0;
	while (i < data->num_count)
	{
		aux = ft_newnode(data->numbers[i], data);
		ft_connectstack(&data->sa, aux);
		i++;
	}
}

int	ft_isordered(t_data	*data)
{
	t_stack	*first;
	int		i;
	int		count;

	i = 0;
	count = 0;
	first = data->sa;
	while (data->sa != NULL)
	{
		if (data->sa->value == data->numbers[i])
			count++;
		if (count == data->num_count)
		{
			data->sa = first;
			return (1);
		}
		i++;
		data->sa = data->sa->next;
	}
	data->sa = first;
	return (0);
}

void	ft_add_index(t_data *data)
{
	t_stack	*first;
	int		i;

	i = 0;
	first = data->sa;
	while (data->sa != NULL)
	{
		while (i < data->num_count)
		{
			if (data->sa->value == data->numbers[i])
			{
				data->sa->index = i + 1;
				i = 0;
				break ;
			}
			i++;
		}
		data->sa = data->sa->next;
	}
	data->sa = first;
}

void	ft_algorithm(t_data *data)
{
	ft_init_stack(data);
	ft_bubbleshort(data);
	if (ft_isordered(data))
		return ;
	ft_add_index(data);
	if (data->num_count == 2)
		swap_a(&data->sa);
	else if (data->num_count == 3)
		ft_order3(data);
	else if (data->num_count > 3)
	{}
	ft_printstack(data->sa);
}
