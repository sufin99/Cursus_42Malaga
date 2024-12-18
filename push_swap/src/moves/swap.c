/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:36 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/13 10:49:36 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack **letter)
{
	t_stack	*temp;

	if (*letter != NULL && (*letter)->next != NULL)
	{
		temp = (*letter)->next;
		(*letter)->next = (temp)->next;
		(temp)->next = (*letter);
		(*letter) = temp;
	}
}

void	swap_a(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
