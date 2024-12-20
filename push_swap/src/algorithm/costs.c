/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:23:34 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/20 02:04:13 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_addcost(t_stack **stack, int is_sa)
{
	t_stack	*current;
	int		mid_size;
	int		stack_size;

	stack_size = ft_sizestack(stack);
	mid_size = stack_size / 2;
	current = *stack;
	while (current)
	{
		if (current->pos <= mid_size)
			current->cost_a = current->pos;
		else if (current->pos > mid_size)
			current->cost_a = current->pos - stack_size;
		if (!is_sa)
		{
			if (current->pos <= mid_size)
				current->cost_b = current->pos;
			else if (current->pos > mid_size)
				current->cost_b = current->pos - stack_size;
		}
		current = current->next;
	}
}

t_stack	*ft_best_node(t_stack *sa, t_stack *sb)
{
	t_stack	*best_node;
	int		min_cost;
	int		cost_a;

	best_node = NULL;
	min_cost = INT_MAX;
	while (sb)
	{
		cost_a = ft_find_cost_a(sa, sb->target_pos);
		if ((cost_a < 0 && sb->cost_b < 0) || (cost_a > 0 && sb->cost_b))
			sb->cost_tot = ft_max(ft_abs(cost_a), ft_abs(sb->cost_b));
		else
			sb->cost_tot = ft_abs(cost_a) + ft_abs(sb->cost_b);
		if (sb->cost_tot < min_cost)
		{
			min_cost = sb->cost_tot;
			best_node = sb;
		}
		sb = sb->next;
	}
	return (best_node);
}

void	ft_movestacks(t_stack **sa, t_stack **sb, int csa, int csb)
{
	while (csa > 0 && csb > 0)
	{
		rotate_r(sa, sb);
		csa--;
		csb--;
	}
	while (csa < 0 && csb < 0)
	{
		reverse_rotate_r(sa, sb);
		csa++;
		csb++;
	}
	ft_moveonlysb(sb, csb);
	ft_moveonlysa(sa, csa);
}

void	ft_choosenode(t_stack **sa, t_stack **sb)
{
	t_stack	*current_sa;
	t_stack	*current_sb;
	t_stack	*min_node;

	min_node = ft_best_node(*sa, *sb);
	current_sb = *sb;
	while (current_sb)
	{
		if (current_sb == min_node)
		{
			current_sa = *sa;
			while (current_sa)
			{
				if (current_sb->target_pos == current_sa->pos)
				{
					ft_movestacks(sa, sb,
						current_sa->cost_a, current_sb->cost_b);
					push_a(sa, sb);
					return ;
				}
				current_sa = current_sa->next;
			}
		}
		current_sb = current_sb->next;
	}
}
