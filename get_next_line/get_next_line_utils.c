/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:38:13 by szaghdad          #+#    #+#             */
/*   Updated: 2024/07/13 16:29:53 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*reserve;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	reserve = (char *)malloc(len);
	if (!reserve)
		return (NULL);
	while (i < len)
	{
		reserve[i] = s[i];
		i++;
	}
	return (reserve);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	snew = (char *)malloc(sizeof(*snew) * (s1_len + s2_len + 1));
	if (!snew)
		return (NULL);
	while (s1[i])
	{
		snew[i] = s1[i];
		i++;
	}
	while (s2[j])
		snew[i++] = s2[j++];
	snew[i] = '\0';
	return (snew);
}

static	char	*loop(char *substr, char const *s,
		unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*substr2;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > lens)
		len = lens - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	substr2 = loop(substr, s, start, len);
	return (substr2);
}
