/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:20:07 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 13:16:11 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tempo;

	while (*lst)
	{
		tempo = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tempo;
	}
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

    ft_lstclear(&head, del);

    if (head == NULL)
    {
        printf("La lista está vacía\n");
    }

    return 0;
} */