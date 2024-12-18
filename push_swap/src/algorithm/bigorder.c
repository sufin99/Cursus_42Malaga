/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:04:55 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/18 13:53:40 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_send2sb(t_stack **sa, t_stack **sb, t_data *data)
{
	int		count;
	int		moved;

	count = 0;
	moved = 0;
	while (data->num_count > 6 && count < data->num_count && moved < data->num_count / 2)
	{
		if ((*sa)->index <= data->num_count / 2)
		{
			push_b(sa, sb);
			moved++;
		}
		else
			rotate_a(sa);
		count++;
	}
	while (data->num_count - moved > 3)
	{
		push_b(sa, sb);
		moved++;
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

int	ft_searchlow(t_stack *stack, t_data *data)
{
	t_stack	*current;
	int		low;

	current = stack;
	low = data->num_count;
	while (current)
	{
		if (current->index < low)
			low = current->index;
		current = current->next;
	}
	return (low);
}

int	ft_isbigger(t_stack *stack, t_stack *stack_comp)
{
	t_stack	*current_stack;
	t_stack	*current_comp;
	int		bigger;

	bigger = stack->index;
	current_stack = stack;
	current_comp = stack_comp;
	if (current_stack)
	{
		while (current_comp)
		{
			if (current_stack->index < current_comp->value)
			{
				bigger = current_comp->value;
				return (bigger);
			}
			current_comp = current_comp->next;
		}
	}
	return (bigger);
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
			else if ((*sb)->index == data->num_count)
			{
				/*ft_printf("%d, pos: %d\n", ft_searchlow(current_sa, data), sa->pos);*/
				if (sa->index == ft_searchlow(current_sa, data))
					(*sb)->target_pos = sa->pos;
			}
			else if ((*sb)->index != data->num_count)
			{
				if (sa->index == ft_searchlow(current_sa, data))
					(*sb)->target_pos = sa->pos;
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
	/*if (ft_sizestack(sa) == 2 && !ft_isordered(*sa))
		swap_a(sa);*/
	if (ft_sizestack(sa) == 3 && !ft_isordered(*sa))
		ft_order3(sa, data);
	/*print_stack(*sa, "SA");
	print_stack(*sb, "SB");*/
	while (ft_sizestack(sb) > 0)
	{
		ft_addpos(sa, sb);
		ft_addtargetpos(*sa, sb, 0, data);
		ft_addcostb(sb);
		ft_addcosta(sa);
		ft_costtotal(sa, sb);
		/*ft_printf("llego\n");*/
		/*print_stack(*sa, "SA");
		print_stack(*sb, "SB");*/
		ft_choosenode(sa, sb);
	}
	ft_addpos(sa, sb);
	ft_addcosta(sa);
	ft_ordersa(sa);
	/*print_stack(*sa, "SA");
	print_stack(*sb, "SB");*/
	/*ft_printf("num_max: %d\n", data->num_count);*/
}
