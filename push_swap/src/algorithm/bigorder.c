/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:04:55 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/17 00:15:10 by szaghdad         ###   ########.fr       */
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

void	ft_addtargetpos(t_stack **sa, t_stack **sb, t_data *data)
{
	t_stack	*current_sa;
	t_stack	*current_sb;

	current_sa = *sa;
	while (current_sa != NULL)
	{
		current_sb = *sb;
		while (current_sb != NULL)
		{
			if ((current_sa->index - 1) == current_sb->index)
			{
				current_sb->target_pos = current_sa->pos;
				break ;
			}
			current_sb = current_sb->next;
		}
		if ((current_sa->index - 1) == 0)
		{
			current_sb = *sb;
			while (current_sb != NULL)
			{
				if (current_sb->index == data->num_count)
				{
					current_sb->target_pos = current_sa->pos;
					break ;
				}
				current_sb = current_sb->next;
			}
		}
		current_sa = current_sa->next;
	}
}

void	ft_bigorder(t_stack	**sa, t_stack **sb, t_data *data)
{
	ft_send2sb(sa, sb, data);
	ft_order3(sa, data);
	ft_addcostb(sb);
	ft_addcosta(sa);
	print_stack(*sa, "SA");
	print_stack(*sb, "SB");
	while (ft_sizestack(sb) > 0)
	{
		ft_addpos(sa, sb);
		ft_addtargetpos(sa, sb, data);
		ft_addcostb(sb);
		ft_addcosta(sa);
		print_stack(*sa, "SA");
		print_stack(*sb, "SB");
		ft_costtotal(sa, sb);
		ft_choosenode(sa, sb);
	}
	print_stack(*sa, "SA");
	print_stack(*sb, "SB");
	ft_printf("num_max: %d\n", data->num_count);
}
