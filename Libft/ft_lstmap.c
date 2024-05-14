/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:48:49 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/14 18:52:40 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void), void (*del)(void *))
{
	
}

/* Sirve para crear una nueva lista enlazada que es
el resultado de aplicar una función específica a cada elemento
de una lista existente */