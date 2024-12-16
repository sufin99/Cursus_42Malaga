/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:32:37 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/12 12:32:37 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_printstack(t_stack *sipollo)
{
	while (sipollo)
	{
		ft_printf("add: %p, value: %d, index: %d, next: %p\n",
			sipollo, sipollo->value, sipollo->index, sipollo->next);
		ft_printf("pos: %d\n", sipollo->pos);
		sipollo = sipollo->next;
	}
	ft_printf("\n");
}

void	print_stack(t_stack *stack, const char *name)
{
	t_stack	*current;

	ft_printf("Stack %s:\n", name);
	current = stack;
	while (current)
	{
		ft_printf("Value: %d, Index: %d, Pos: %d, TarPos: %d, CostB: %d, CostA: %d, CostTot: %d\n", current->value, current->index, current->pos, current->target_pos, current->cost_b, current->cost_a, current->cost_tot);
		current = current->next;
	}
	ft_printf("\n");
}
