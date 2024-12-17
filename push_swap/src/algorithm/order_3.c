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

void	ft_order3(t_stack **stack, t_data *data)
{
	/* print_stack(*stack, "SA"); */
	if (((*stack)->index > (*stack)->next->index)
		&& ((*stack)->index > (*stack)->next->next->index))
		rotate_a(stack);
	else if (((*stack)->next->index > (*stack)->index)
		&& ((*stack)->next->index > (*stack)->next->next->index))
		reverse_rotate_a(stack);
	else if (((*stack)->index > (*stack)->next->index)
		&& ((*stack)->index < (*stack)->next->next->index))
		swap_a(stack);
	if (!ft_isordered(*stack))
		ft_order3(stack, data);
}
