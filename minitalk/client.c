/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:16:20 by szaghdad          #+#    #+#             */
/*   Updated: 2024/11/27 18:01:56 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(2000);
}

void	ft_con2bit(int pid, char carac)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((carac >> i) & 1)
			ft_sendbit(pid, 1);
		else
			ft_sendbit(pid, 0);
		i--;
	}
}

void	confirm_handler(int signum)
{
	static int	count = 0;

	if (signum == SIGUSR1 && !count)
	{
		ft_printf("Recibido👌\n");
		count = 1;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;
	int		i;	

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		if (pid <= 0 || message[0] == '\0')
		{
			ft_printf("Error: Introduce un PID y un mensaje válidos\n");
			return (1);
		}
		signal(SIGUSR1, confirm_handler);
		while (message[i] != '\0')
			ft_con2bit(pid, message[i++]);
		if (message[i] == '\0')
			ft_con2bit(pid, 0);
	}
	else
		ft_printf("Error de sintaxis: %s <PID> <mensaje>\n", argv[0]);
	return (0);
}
