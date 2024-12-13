/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:53:21 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/13 10:53:21 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_order3(t_data *data)
{
	if ((data->sa->index > data->sa->next->index)
		&& (data->sa->index > data->sa->next->next->index))
		rotate_a(&data->sa);
	else if ((data->sa->next->index > data->sa->index)
		&& (data->sa->next->index > data->sa->next->next->index))
		reverse_rotate_a(&data->sa);
	else if ((data->sa->index > data->sa->next->index)
		&& (data->sa->index < data->sa->next->next->index))
		swap_a(&data->sa);
	if (!ft_isordered(data))
		ft_order3(data);
}
