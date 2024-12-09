/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:30:38 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/09 16:51:00 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b != NULL)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
		ft_printf("pa\n");
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
		ft_printf("pb\n");
	}
}
