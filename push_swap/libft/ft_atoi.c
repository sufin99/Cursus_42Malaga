/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:18:12 by szaghdad          #+#    #+#             */
/*   Updated: 2024/05/15 12:52:02 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

/* int	main(void)
{
	char str1[] = "   -42";
	char str2[] = "123abc";
	char str3[] = "   +789";
	char str4[] = "   -2147483648";
	char str5[] = "   2147483647";

	printf("ft_atoi(\"%s\") = %d\n", str1, ft_atoi(str1));
	printf("ft_atoi(\"%s\") = %d\n", str2, ft_atoi(str2));
	printf("ft_atoi(\"%s\") = %d\n", str3, ft_atoi(str3));
	printf("ft_atoi(\"%s\") = %d\n", str4, ft_atoi(str4));
	printf("ft_atoi(\"%s\") = %d\n", str5, ft_atoi(str5));

	return (0);
} */
