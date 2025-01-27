/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:50:46 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/01 22:50:46 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*snew;
	char	*start;
	char	*end;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen(s1);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;
	snew = (char *)malloc(end - start + 1);
	if (!snew)
		return (NULL);
	while (start + i < end)
	{
		snew[i] = start[i];
		i++;
	}
	snew[end - start] = '\0';
	return (snew);
}

/*int	main(void)
{
	char	str[] = "Auxilio";
	char	set2[] = "Auxio";
	char	*sx;

	sx = ft_strtrim(str, set2);
	printf("La nueva cadena es: %s", sx);
	free(sx);
}*/
/* Es una función que elimina caracteres
que salen en set de la cadena. Y crea una nueva cadena
sin lo caracteres de set */