/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:35:43 by szaghdad          #+#    #+#             */
/*   Updated: 2024/04/25 19:35:43 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char *s = "Auxilio";
    char *reserve = ft_strdup(s);
    if (reserve == NULL)
    {
        printf("Failed to duplicate string\n");
        return 1;
    }
    printf("Duplicated string: %s\n", reserve);
    free(reserve);
    return (0);
}*/
