/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:27:18 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 19:10:30 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_forks(pthread_mutex_t	*forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_values(t_philo *philos, t_params *params, int i)
{
	philos->id = i + 1;
	philos->table = params->program;
	philos->time_to_die = ft_atol(params->argv[2]);
	philos->time_to_eat = ft_atol(params->argv[3]);
	philos->time_to_sleep = ft_atol(params->argv[4]);
	philos->last_meal = ft_get_time();
	philos->first_meal = ft_get_time();
	philos->times_eaten = 0;
	philos->left_fork = &params->forks[i];
	if (philos->id == 1)
		philos->right_fork = &params->forks[params->program->num_philo - 1];
	else
		philos->right_fork = &params->forks[i - 1];
	if (params->argv[5])
		philos->n_times_to_eat = ft_atol(params->argv[5]);
	else
		philos->n_times_to_eat = -1;
}

void	set_philos(char **argv, t_list *program, t_philo *philos,
	pthread_mutex_t *forks)
{
	t_params	params;
	int			i;

	i = 0;
	params.argv = argv;
	params.program = program;
	params.forks = forks;
	while (i < program->num_philo)
	{
		init_values(&philos[i], &params, i);
		i++;
	}
}

void	create_philos(t_list *program, pthread_mutex_t *forks,
	t_philo *philos)
{
	int	i;

	i = 0;
	while (i < program->num_philo)
	{
		ft_usleep(5);
		if (pthread_create(&philos[i].thread, NULL,
				&routine, &philos[i]) != 0)
			ft_destroy(program, forks);
		i++;
	}
	ft_monitor(philos, program);
	i = 0;
	while (i < program->num_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			ft_destroy(program, forks);
		i++;
	}
}
