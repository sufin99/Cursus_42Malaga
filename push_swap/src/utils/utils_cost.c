/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:18:50 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/20 01:18:50 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_moveonlysa(t_stack **sa, int csa)
{
	while (csa < 0)
	{
		reverse_rotate_a(sa);
		csa++;
	}
	while (csa > 0)
	{
		rotate_a(sa);
		csa--;
	}
}

void	ft_moveonlysb(t_stack **sb, int csb)
{
	while (csb < 0)
	{
		reverse_rotate_b(sb);
		csb++;
	}
	while (csb > 0)
	{
		rotate_b(sb);
		csb--;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_find_cost_a(t_stack *sa, int target_pos)
{
	t_stack	*current;
	int		cost;

	current = sa;
	cost = 0;
	while (current)
	{
		if (current->pos == target_pos)
			break ;
		cost++;
		current = current->next;
	}
	if (cost > ft_sizestack(&sa) / 2)
		cost -= ft_sizestack(&sa);
	return (cost);
}
