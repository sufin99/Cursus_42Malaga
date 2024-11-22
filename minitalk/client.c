/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:16:20 by szaghdad          #+#    #+#             */
/*   Updated: 2024/11/22 21:43:34 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(69);
}

void	ft_con2bit(int pid, char car)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((car >> i) & 1)
		{
			ft_printf("1");
			ft_sendbit(pid, 1);
		}
		else
		{
			ft_printf("0");
			ft_sendbit(pid, 0);
		}
		i--;
	}
	ft_printf(" ");
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
			ft_printf("Error\n");
			return (1);
		}
		while (message[i] != '\0')
			ft_con2bit(pid, message[i++]);
		ft_printf("\n");
	}
	else
		ft_printf("Error de sintaxis: %s <PID> <mensaje>\n", argv[0]);
	return (0);
}
