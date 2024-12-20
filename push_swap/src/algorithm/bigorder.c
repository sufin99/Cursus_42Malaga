/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:04:55 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/20 01:54:12 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_sendallsavethree(t_stack **sa, t_stack **sb, t_data *data, int count)
{
	while (count > 3)
	{
		if ((*sa)->index <= (data->num_count - 3))
			push_b(sa, sb);
		else
		{
			rotate_a(sa);
			count++;
		}
		count--;
	}
}

void	ft_send2sb(t_stack **sa, t_stack **sb, t_data *data)
{
	int		count;
	int		moved;

	count = data->num_count;
	moved = 0;
	while (count > (data->num_count / 2))
	{
		if ((*sa)->index <= (data->num_count / 2))
		{
			push_b(sa, sb);
			moved++;
		}
		else
			rotate_a(sa);
		count--;
	}
	count = data->num_count - moved;
	ft_sendallsavethree(sa, sb, data, count);
}

void	ft_auxaddtarget(t_stack *sa, t_stack **sb, int intex, t_data *data)
{
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
		else if ((*sb)->value == data->num_count)
		{
			if (sa->index == 1)
				(*sb)->target_pos = sa->pos;
		}
		sa = sa->next;
	}
}

void	ft_addtargetpos(t_stack *sa, t_stack **sb, int intex, t_data *data)
{
	t_stack	*current_sb;
	t_stack	*current_sa;

	current_sb = *sb;
	current_sa = sa;
	while (*sb)
	{
		sa = current_sa;
		(*sb)->target_pos = -1;
		ft_auxaddtarget(sa, sb, intex, data);
		(*sb) = (*sb)->next;
	}
	*sb = current_sb;
}

void	ft_bigorder(t_stack	**sa, t_stack **sb, t_data *data)
{
	ft_send2sb(sa, sb, data);
	if (ft_sizestack(sa) == 3 && !ft_isordered(*sa))
		ft_order3(sa, data);
	while (ft_sizestack(sb) > 0)
	{
		ft_addpos(sa, sb);
		ft_addtargetpos(*sa, sb, 0, data);
		ft_addcost(sb, 0);
		ft_addcost(sa, 1);
		ft_choosenode(sa, sb);
	}
	ft_addpos(sa, sb);
	ft_addcost(sa, 1);
	ft_ordersa(sa);
}
