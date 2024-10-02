/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:05:17 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 13:17:26 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

/* int main()
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    node->content = 1;
    node->next = NULL;

    ft_lstdelone(node, del);

    if (node == NULL)
    {
        printf("El nodo está vacío\n");
    }

    return 0;
} */