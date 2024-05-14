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

/* Sirve para crear un nuevo elemento de una lista enlazada y asignarle
un contenido. Será inicializado para que su contenido sea el
puntero content proporcionado y su
puntero next será NULL */