/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:24:47 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 13:54:59 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_destroy(t_list *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->monitor_lock);
}

int	ft_usleep(size_t milisec)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < milisec)
		usleep(10);
	return (0);
}

size_t	ft_get_time(void)
{
	struct timeval	time;
	long			sec;
	long			usec;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Don't get time of day");
	sec = time.tv_sec;
	usec = time.tv_usec;
	return (sec * 1000 + usec / 1000);
}

int	ft_atol(const char *str)
{
	int			i;
	int			sign;
	int			res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}
