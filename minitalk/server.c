/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:58:08 by szaghdad          #+#    #+#             */
/*   Updated: 2024/11/23 11:58:08 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	signal_handler(int signum, siginfo_t *info, void *param)
{
	static int	count_bits = 0;
	static char	current_char = 0;

	(void) param;
	if (signum == SIGUSR2)
		current_char = (current_char << 1) | 1;
	else if (signum == SIGUSR1)
		current_char = (current_char << 1) | 0;
	count_bits++;
	if (count_bits == 8)
	{
		if (current_char == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &current_char, 1);
		count_bits = 0;
		current_char = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	siga;

	pid = getpid();
	ft_printf("Bienvenido al server de Sufián \n");
	ft_printf("PID: %i\n", pid);
	siga.sa_sigaction = signal_handler;
	siga.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&siga.sa_mask);
	if (sigaction(SIGUSR1, &siga, NULL) == -1
		|| sigaction(SIGUSR2, &siga, NULL) == -1)
	{
		ft_printf("Error: sigaction failure");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
