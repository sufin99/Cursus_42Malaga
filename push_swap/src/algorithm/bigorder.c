/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:04:55 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/14 11:41:34 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_send2sb(t_stack **sa, t_stack **sb, t_data *data)
{
	int		mid_index;
	int		count;
	int		moved;

	mid_index = data->num_count / 2;
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

void	ft_bigorder(t_stack	*sa, t_stack *sb, t_data *data)
{
	ft_send2sb(&sa, &sb, data);
	print_stack(sa, "SA");
	print_stack(sb, "SB");
	ft_order3(&sa, data);
	ft_addpos(&sa, &sb);
	print_stack(sa, "SA");
	print_stack(sb, "SB");
}
