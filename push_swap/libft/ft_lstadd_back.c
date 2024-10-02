/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:40:51 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 13:12:37 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/* int main()
{
    t_list *head = NULL;
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = 1;
    new_node->next = NULL;

    ft_lstadd_back(&head, new_node);

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = 2;
    new_node->next = NULL;

    ft_lstadd_back(&head, new_node);

    t_list *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
} */