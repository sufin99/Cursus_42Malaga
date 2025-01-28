/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:13:15 by szaghdad          #+#    #+#             */
/*   Updated: 2025/01/28 21:30:36 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static char	*read_line(int fd, char *left_c, char *buffer)
{
	ssize_t	line_re;
	char	*loc_buffer;

	line_re = 1;
	while (line_re > 0)
	{
		line_re = read(fd, buffer, BUFFER_SIZE);
		if (line_re == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (line_re == '\0')
			break ;
		buffer[line_re] = '\0';
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

static char	*sep_line(char *line_buffer)
{
	ssize_t	i;
	char	*left_c;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[1] == '\0')
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen1(line_buffer) - i);
	if (*left_c == '\0')
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (left_c);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*left_c;
	char		*re_line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(left_c);
		buffer = NULL;
		left_c = NULL;
		return (NULL);
	}
	re_line = read_line(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!re_line)
		return (NULL);
	left_c = sep_line(re_line);
	return (re_line);
}
