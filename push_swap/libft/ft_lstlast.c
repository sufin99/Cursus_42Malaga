/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:28:49 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 13:20:12 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}

/* int main()
{
    t_list *head = NULL;
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = 1;
    new_node->next = NULL;

    head = new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = 2;
    new_node->next = NULL;

    head->next = new_node;

    t_list *last_node = ft_lstlast(head);

    if (last_node != NULL)
    {
        printf("El último nodo tiene el dato: %d\n", last_node->data);
    }

    return 0;
} */