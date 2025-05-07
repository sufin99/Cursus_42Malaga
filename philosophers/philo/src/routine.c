/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:34:00 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 14:04:14 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_fork);
		printph("has taken a fork", philos, philos->id);
		pthread_mutex_lock(philos->left_fork);
		printph("has taken a fork", philos, philos->id);
	}
	else
	{
		pthread_mutex_lock(philos->left_fork);
		printph("has taken a fork", philos, philos->id);
		pthread_mutex_lock(philos->right_fork);
		printph("has taken a fork", philos, philos->id);
	}
}

void	ft_eat(t_philo *philos)
{
	take_forks(philos);
	pthread_mutex_lock(&philos->table->monitor_lock);
	philos->last_meal = ft_get_time();
	philos->times_eaten++;
	pthread_mutex_unlock(&philos->table->monitor_lock);
	printph("is eating", philos, philos->id);
	ft_usleep(philos->time_to_eat);
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
}

void	ft_sleep_or_think(t_philo *philos, int aux)
{
	if (aux == 1)
	{
		printph("is sleeping", philos, philos->id);
		ft_usleep(philos->time_to_sleep);
	}
	else
	{
		printph("is thinking", philos, philos->id);
		ft_usleep (1);
	}
}

int	ft_loop(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->print_lock);
	if (philos->table->end_flag)
	{
		pthread_mutex_unlock(&philos->table->print_lock);
		return (1);
	}
	pthread_mutex_unlock(&philos->table->print_lock);
	return (0);
}

void	*routine(void *p)
{
	t_philo	*philos;

	philos = (t_philo *)p;
	if (philos->id % 2 == 0)
		ft_usleep(10);
	while (!ft_loop(philos))
	{
		ft_eat(philos);
		ft_sleep_or_think(philos, 1);
		ft_sleep_or_think(philos, 0);
	}
	return (p);
}
