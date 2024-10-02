/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:07:04 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/14 09:07:04 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node2;

	node2 = malloc(sizeof(t_list));
	if (!node2)
		return (NULL);
	node2->content = content;
	node2->next = NULL;
	return (node2);
}

/* int main()
{
    int data = 1;

    t_list *node = ft_lstnew(&data);

    if (node != NULL)
    {
        printf("El nodo tiene el contenido: %d\n", node->content);
    }

    return 0;
} */