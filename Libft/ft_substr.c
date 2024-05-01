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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= strlen(s))
		return (strdup(""));
	if (start + len > strlen(s))
		len = strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
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
/* Es una función que se utiliza para
obtener una subcadena dada, comenzando desde
un índice específico y de una longitud */