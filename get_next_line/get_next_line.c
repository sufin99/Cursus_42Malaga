/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:02:09 by szaghdad          #+#    #+#             */
/*   Updated: 2024/07/02 19:12:30 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	char	*strest;
	char			*fstr;
	char			buff[BUFFER_SIZE + 1];


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}
