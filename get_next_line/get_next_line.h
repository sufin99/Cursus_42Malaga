/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:05:04 by szaghdad          #+#    #+#             */
/*   Updated: 2024/07/09 20:11:27 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	3
# endif

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t num, size_t size);

#endif