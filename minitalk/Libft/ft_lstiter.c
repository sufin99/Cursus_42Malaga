/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:34:36 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/14 18:25:43 by szaghdad         ###   ########.fr       */
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

/* Sirve para aplicar una función dada
a cada elemento de una lista enlazada */