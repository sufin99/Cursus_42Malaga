/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:57:41 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/11 20:48:31 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.nums_str = NULL;
	data.numbers = NULL;
	if (argc >= 2)
		ft_parsing(argc, argv, &data);
	ft_freeall(&data);
	return (0);
}
