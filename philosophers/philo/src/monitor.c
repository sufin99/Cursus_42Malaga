/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:21:43 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 12:31:14 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_died(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->monitor_lock);
	if (ft_get_time() - philos->last_meal >= philos->time_to_die)
	{
		printph("died", philos, philos->id);
		pthread_mutex_unlock(&philos->table->monitor_lock);
		return (1);
	}
	pthread_mutex_unlock(&philos->table->monitor_lock);
	return (0);
}

int	ft_count_meal(t_philo *philos, t_list *program)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	if (philos->n_times_to_eat == -1)
		return (0);
	while (i < program->num_philo)
	{
		ft_usleep(4);
		pthread_mutex_lock(&philos->table->monitor_lock);
		if (philos[i].times_eaten >= philos->n_times_to_eat)
			counter++;
		pthread_mutex_unlock(&philos->table->monitor_lock);
		if (counter == program->num_philo)
			return (1);
		i++;
	}
	return (0);
}

void	ft_monitor(t_philo *philos, t_list *program)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == program->num_philo)
		{
			i = 0;
		}
		if (ft_died(&philos[i]) || ft_count_meal(&philos[i], program))
		{
			pthread_mutex_lock(&philos->table->print_lock);
			program->end_flag = 1;
			break ;
		}
		ft_usleep(1);
		i++;
	}
	pthread_mutex_unlock(&philos->table->print_lock);
}
