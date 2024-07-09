/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:02:09 by szaghdad          #+#    #+#             */
/*   Updated: 2024/07/09 20:12:27 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd)
{
	int			read_bytes;
	char		*loc_buffer;
	static int	count;

	count = 1;
	printf("ft_calloc#[%d]---", count++);
	loc_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!loc_buffer)
		return (NULL);
	read_bytes = read(fd, loc_buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(loc_buffer);
		return (NULL);
	}
	return (loc_buffer);
}

char	*get_next_line(int fd)
{
	char	*bas_buffer;

	bas_buffer = read_file(fd);
	return (bas_buffer);
}
