/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:23:34 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/18 14:25:36 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_addcostb(t_stack **sb)
{
	t_stack	*current;
	int		mid_size;
	int		stack_size;

	stack_size = ft_sizestack(sb);
	mid_size = stack_size / 2;
	current = *sb;
	while (current)
	{
		if (current->pos <= mid_size)
			current->cost_b = current->pos;
		else if (current->pos > mid_size)
			current->cost_b = current->pos - stack_size;
		current = current->next;
	}
}

void	ft_addcosta(t_stack **sa)
{
	t_stack	*current;
	int		mid_size;
	int		stack_size;

	stack_size = ft_sizestack(sa);
	mid_size = stack_size / 2;
	current = *sa;
	while (current)
	{
		if (current->pos <= mid_size)
			current->cost_a = current->pos;
		else if (current->pos > mid_size)
			current->cost_a = current->pos - stack_size;
		current = current->next;
	}
}

void	ft_costtotal(t_stack **sa, t_stack **sb)
{
	t_stack	*current_sa;
	t_stack	*current_sb;
	int		sign_sa;
	int		sign_sb;

	current_sb = *sb;
	sign_sa = 1;
	sign_sb = 1;
	while (current_sb)
	{
		if (current_sb->cost_b < 0)
			sign_sb = -1;
		current_sa = *sa;
		while (current_sa)
		{
			if (current_sb->target_pos == current_sa->pos)
			{
				if (current_sa->cost_a < 0)
					sign_sa = -1;
				current_sb->cost_tot = (current_sa->cost_a * sign_sa) + (current_sb->cost_b * sign_sb);
				break ;
			}
			current_sa = current_sa->next;
		}
		current_sb = current_sb->next;
	}
}

int	ft_mincost(t_stack *sb)
{
	t_stack	*current;
	int		min;

	current = sb;
	min = current->cost_tot;
	while (current)
	{
		if (current->cost_tot < min)
			min = current->cost_tot;
		current = current->next;
	}
	return (min);
}

void	ft_movestacks(t_stack **sa, t_stack **sb, int csa, int csb)
{
	/* print_stack(*sa, "SA");
	print_stack(*sb, "SB"); */
	/* printf("CostA: %d, CostB: %d\n", (*sa)->cost_a, (*sb)->cost_b); */
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
	/*print_stack(*sa, "SA");
	print_stack(*sb, "SB");*/
	/* if (csb == 0 && (*sa)->cost_a == 0)
		push_a(sa, sb); */
	/* print_stack((*sa), "SA");
	print_stack((*sb), "SB"); */
}

void	ft_choosenode(t_stack **sa, t_stack **sb)
{
	t_stack	*current_sa;
	t_stack	*current_sb;
	int		min;

	min = ft_mincost(*sb);
	/*ft_printf("%d\n", min);*/
	current_sb = *sb;
	while (current_sb)
	{
		if (current_sb->cost_tot == min)
		{
			/*ft_printf("%d, value: %d\n", current_sb->cost_tot, current_sb->value);*/
			current_sa = *sa;
			while (current_sa)
			{
				if (current_sb->target_pos == current_sa->pos)
				{
					/*ft_printf("value: %d, tarposb: %d, posa: %d\n", current_sb->value, current_sb->target_pos, current_sa->pos);*/
					ft_movestacks(sa, sb, current_sa->cost_a, current_sb->cost_b);
					/* print_stack(*sa, "SA");
					print_stack(*sb, "SB"); */
					push_a(sa, sb);
					return ;
				}
				current_sa = current_sa->next;
			}
		}
		current_sb = current_sb->next;
	}
}