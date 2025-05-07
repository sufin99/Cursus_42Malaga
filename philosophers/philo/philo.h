/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:20:32 by szaghdad          #+#    #+#             */
/*   Updated: 2025/05/07 14:11:14 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_list
{
	pthread_mutex_t		monitor_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		eat_lock;
	int					num_philo;
	int					end_flag;
	t_philo				*philos;
}						t_list;

typedef struct s_philo
{
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_t			thread;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				last_meal;
	size_t				first_meal;
	int					id;
	int					times_eaten;
	int					n_times_to_eat;
	t_list				*table;
}						t_philo;

typedef struct s_params
{
	char				**argv;
	t_list				*program;
	pthread_mutex_t		*forks;
}						t_params;

int		parseo(char **argv);

void	init_program(t_list *program, t_philo *philos, char **argv);

void	init_forks(pthread_mutex_t	*forks, int philo_num);
void	set_philos(char **argv, t_list *program, t_philo *philos,
			pthread_mutex_t *forks);
void	create_philos(t_list *program, pthread_mutex_t *forks,
			t_philo *philos);

void	ft_monitor(t_philo *philos, t_list *program);

void	*routine(void *p);

void	printph(char *str, t_philo *philos, int id);
int		ft_error(char *str);
void	ft_destroy(t_list *program, pthread_mutex_t *forks);
int		ft_usleep(size_t milisec);
size_t	ft_get_time(void);
int		ft_atol(const char *str);

#endif