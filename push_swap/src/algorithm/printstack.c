/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:32:37 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/12 12:32:37 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_printstack(t_stack *sipollo)
{
	while (sipollo)
	{
		ft_printf("add: %p, value: %d, index: %d, next: %p\n",
			sipollo, sipollo->value, sipollo->index, sipollo->next);
		sipollo = sipollo->next;
	}
}
