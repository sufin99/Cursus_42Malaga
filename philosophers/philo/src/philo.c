/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:14:18 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 13:28:25 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_program(t_list *program, t_philo *philos, char **argv)
{
	pthread_mutex_t	forks[200];

	program->num_philo = ft_atol (argv[1]);
	program->end_flag = 0;
	pthread_mutex_init(&program->monitor_lock, NULL);
	pthread_mutex_init(&program->print_lock, NULL);
	pthread_mutex_init(&program->eat_lock, NULL);
	init_forks(forks, program->num_philo);
	set_philos(argv, program, philos, forks);
	program->philos = philos;
	if (program->num_philo == 1)
	{
		printph("has taken a fork", philos, philos->id);
		ft_usleep(ft_atol(argv[2]));
		printph("died", philos, philos->id);
		return ;
	}
	create_philos(program, forks, philos);
	ft_destroy(program, forks);
}
