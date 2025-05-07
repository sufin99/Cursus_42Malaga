/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:24:12 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 13:41:42 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	printph(char *str, t_philo *philos, int id)
{
	size_t	time;

	time = ft_get_time() - philos->first_meal;
	pthread_mutex_lock(&philos->table->print_lock);
	if (!philos->table->end_flag)
		printf("%zu-> %d %s\n", time, id, str);
	pthread_mutex_unlock(&philos->table->print_lock);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	return (1);
}
