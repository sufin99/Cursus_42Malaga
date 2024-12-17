/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:04:55 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/17 14:48:46 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_send2sb(t_stack **sa, t_stack **sb, t_data *data)
{
	int		mid_index;
	int		count;
	int		moved;

	mid_index = (data->num_count + 1) / 2;
	count = data->num_count;
	moved = 0;
	while (count > mid_index)
	{
		if ((*sa)->index <= mid_index)
		{
			push_b(sa, sb);
			moved++;
		}
		else
			rotate_a(sa);
		count--;
	}
	count = data->num_count;
	while (count - moved > 3)
	{
		push_b(sa, sb);
		count--;
	}
}

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

void	ft_addtargetpos(t_stack *sa, t_stack **sb, int intex)
{
	t_stack	*current_sb;
	t_stack	*current_sa;

	current_sb = *sb;
	current_sa = sa;
	while (*sb)
	{
		sa = current_sa;
		(*sb)->target_pos = -1;
		while (sa)
		{
			if (sa->index > (*sb)->index)
			{
				if ((*sb)->target_pos == -1)
				{
					intex = sa->index;
					(*sb)->target_pos = sa->pos;
				}
				if (sa->index < intex)
				{
					(*sb)->target_pos = sa->pos;
					intex = sa->index;
				}
			}
			sa = sa->next;
		}
		(*sb) = (*sb)->next;
	}
	*sb = current_sb;
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

void	ft_bigorder(t_stack	**sa, t_stack **sb, t_data *data)
{
	ft_send2sb(sa, sb, data);
	ft_order3(sa, data);
	/*print_stack(*sa, "SA");
	print_stack(*sb, "SB");*/
	while (ft_sizestack(sb) > 0)
	{
		ft_addpos(sa, sb);
		ft_addtargetpos(*sa, sb, 0);
		ft_addcostb(sb);
		ft_addcosta(sa);
		ft_costtotal(sa, sb);
		/*print_stack(*sa, "SA");
		print_stack(*sb, "SB");*/
		ft_choosenode(sa, sb);
	}
	ft_addpos(sa, sb);
	ft_addcosta(sa);
	ft_ordersa(sa);
/*	print_stack(*sa, "SA");
	print_stack(*sb, "SB");*/
	/*ft_printf("num_max: %d\n", data->num_count);*/
}
