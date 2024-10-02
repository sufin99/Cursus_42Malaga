/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:23:11 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:54:31 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = (long)n;
	len = get_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (--len >= 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	return (str);
}

/* int	main(void)
{
	int		numbers[] = {0, 123, -123, 2147483647, -2147483648};
	char	*str;
	int		i;

	for (i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		str = ft_itoa(numbers[i]);
		if (str)
		{
			printf("Number: %d, String: %s\n", numbers[i], str);
			free(str);
		}
		else
		{
			printf("Failed to convert number: %d\n", numbers[i]);
		}
	}

	return (0);
} */
