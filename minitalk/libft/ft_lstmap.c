/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:48:49 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:41:00 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*node2;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		node2 = ft_lstnew(new_content);
		if (!node2)
		{
			del(new_content);
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, node2);
		lst = lst->next;
	}
	return (lst2);
}

/* Sirve para crear una nueva lista enlazada que es
el resultado de aplicar una función específica a cada elemento
de una lista existente */