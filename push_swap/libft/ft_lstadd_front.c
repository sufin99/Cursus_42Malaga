/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:39:32 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 13:13:55 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int main()
{
    t_list *head = NULL;
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = 1;
    new_node->next = NULL;

    ft_lstadd_front(&head, new_node);

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = 2;
    new_node->next = NULL;

    ft_lstadd_front(&head, new_node);

    t_list *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
} */