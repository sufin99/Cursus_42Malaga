/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:57:39 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/09 18:00:19 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_parsing(int argc, char *argv[], t_stack **a)
{
	char	**nums;
	int		*nums2;
	int		i;
	int		j;
	int		num_count;

	(void) a;
	num_count = 0;
	i = 0;
	j = 0;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (nums == NULL)
			ft_error();
		while (nums[i])
		{
			j = 0;
			while (nums[i][j] != '\0')
			{
				if (ft_isdigit(nums[i][j]) == 0)
					ft_error();
				ft_printf("numero: %c\n", nums[i][j]);
				j++;
			}
			ft_printf("numero entero: %s\n", nums[i]);
			i++;
		}
		i = 0;
		j = 0;
		while (nums[num_count])
			num_count++;
		nums2 = (int *)malloc(sizeof(int) * (num_count));
		if (!nums2)
			ft_error();
		while (i < num_count)
		{
			nums2[i] = ft_atoi(nums[j]);
			ft_printf("Num[%i]: %i\n", j, nums2[i]);
			i++;
			j++;
		}
	}
	/* else if (argc > 2)
	{} */
}

