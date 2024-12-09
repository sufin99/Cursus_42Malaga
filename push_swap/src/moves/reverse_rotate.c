/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:37:36 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/09 16:51:05 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second = *stack;
	while (second->next->next != NULL)
		second = second->next;
	last = second->next;
	second->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
