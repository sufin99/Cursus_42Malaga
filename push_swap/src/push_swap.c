/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:57:41 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/09 16:57:22 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	/* t_stack	*b; */

	if (argc >= 2)
		ft_parsing(argc, argv, &a);
	return (0);
}
