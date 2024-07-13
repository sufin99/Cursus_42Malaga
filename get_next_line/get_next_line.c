/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:02:09 by szaghdad          #+#    #+#             */
/*   Updated: 2024/07/13 18:13:55 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*declare_line(char *line_buffer)
{
	ssize_t	i;
	char	*left_c;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || !(line_buffer[1] == 0))
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}

static char	*read_line(int fd, char *left_c, char *buffer)
{
	ssize_t	re_line;
	char	*loc_buffer;

	re_line = 1;
	while (re_line > 0)
	{
		re_line = read(fd, buffer, BUFFER_SIZE);
		if (re_line == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (re_line == 0)
			break ;
		buffer[re_line] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		loc_buffer = left_c;
		left_c = ft_strjoin(loc_buffer, buffer);
		free(loc_buffer);
		loc_buffer = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*re_line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	re_line = read_line(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!re_line)
		return (NULL);
	left_c = declare_line(re_line);
	return (re_line);
}
