/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:35:12 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 12:35:12 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	parseo(char **argv)
{
	if ((ft_atol(argv[1]) > 200) || ft_atol(argv[1]) <= 0)
		return (ft_error("Number of philosophers\n"));
	if (ft_atol(argv[2]) <= 0)
		return (ft_error("Time to die\n"));
	if (ft_atol(argv[3]) <= 0)
		return (ft_error("Time to eat\n"));
	if (ft_atol(argv[4]) <= 0)
		return (ft_error("Time to sleep\n"));
	if (argv[5])
		if (ft_atol(argv[5]) <= 0)
			return (ft_error("Number of meals\n"));
	return (0);
}
