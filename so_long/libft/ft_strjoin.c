/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:16:53 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/01 22:16:53 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char	str[] = "Auxilio";
	char	str2[] = "medesmayo";
	char	*sx;

	sx = ft_strjoin(str, str2);
	printf("La nueva cadena se convierte en: %s", sx);
	free (sx);
}*/
/* La función strjoin sirve para concatenar 2 strings y
la nueva cadena que se ha formado */