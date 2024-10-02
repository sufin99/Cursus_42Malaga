/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:34:36 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 13:18:59 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tempo;

	while (lst)
	{
		tempo = lst->next;
		f(lst->content);
		lst = tempo;
	}
}

/* int main()
{
    t_list *head = NULL;
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = 1;
    new_node->next = NULL;

    head = new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = 2;
    new_node->next = NULL;

    head->next = new_node;

    ft_lstiter(head, increment);

    t_list *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->content);
        temp = temp->next;
    }

    return 0;
} */