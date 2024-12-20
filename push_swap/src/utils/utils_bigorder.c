/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bigorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:00:04 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/20 01:00:04 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_addpos(t_stack **sa, t_stack	**sb)
{
	t_stack	*current;
	int		pos;

	current = *sa;
	pos = 0;
	while (current)
	{
		current->pos = pos;
		pos++;
		current = current->next;
	}
	current = *sb;
	pos = 0;
	while (current)
	{
		current->pos = pos;
		pos++;
		current = current->next;
	}
}

void	ft_ordersa(t_stack **sa)
{
	t_stack	*current_sa;
	int		csa;

	current_sa = *sa;
	csa = 0;
	while (current_sa)
	{
		if (current_sa->index == 1)
		{
			csa = current_sa->cost_a;
			break ;
		}
		current_sa = current_sa->next;
	}
	while (csa > 0)
	{
		rotate_a(sa);
		csa--;
	}
	while (csa < 0)
	{
		reverse_rotate_a(sa);
		csa++;
	}
}
