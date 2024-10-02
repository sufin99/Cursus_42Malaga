/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:00:27 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/25 19:00:27 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char *s = "Auxilio";
    unsigned int start = 6;
    size_t len = 5;
    char *substr;

    substr = ft_substr(s, start, len);
    if (substr == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    printf("Subcadena: %s\n", substr);

    free(substr);
    return 0;
}*/
