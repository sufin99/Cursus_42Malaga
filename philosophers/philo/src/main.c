/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:14:42 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 12:24:12 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo	philos[200];
	t_list	program;

	if (argc != 5 && argc != 6)
		return (ft_error("Number of arguments\n"));
	if (parseo(argv))
		return (1);
	init_program(&program, philos, argv);
	return (0);
}
