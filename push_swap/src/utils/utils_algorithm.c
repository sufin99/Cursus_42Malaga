/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:50:27 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/12 11:50:27 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_newnode(int value, t_data *data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		ft_error(data, "Error\n");
	ft_memset(node, 0, sizeof(t_stack));
	node->value = value;
	node->target_pos = -1;
	node->next = NULL;
	return (node);
}

t_stack	*ft_stacklast(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node -> next;
	return (node);
}

void	ft_connectstack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_stacklast(*lst);
		last->next = new;
	}
}

int	ft_sizestack(t_stack **stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
