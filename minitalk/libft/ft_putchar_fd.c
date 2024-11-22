/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:54:24 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/10 12:54:24 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 0) == -1)
		return ;
	write(fd, &c, 1);
}

/*int	main(void)
{
	char	c = 'a';

	ft_putchar_fd(c, 1);
	ft_putchar_fd(c, 2);
	return (0);
}*/
/* Sirve para escribir el caracter c en el descriptor de archivo
proporcionado (fd). El descriptor del archivo tiene que ser válido
y disponible para escritura */