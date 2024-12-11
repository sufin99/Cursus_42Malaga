/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghdad <szaghdad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:57:39 by szaghdad          #+#    #+#             */
/*   Updated: 2024/12/11 22:09:04 by szaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_savestr(char **argv, t_data *data)
{
	int	j;

	data->num_count = 1;
	while (argv[data->num_count])
		data->num_count++;
	data->nums_str = (char **)malloc(sizeof(char *) * (data->num_count + 1));
	if (!data->nums_str)
		ft_error(data, "Error\n");
	data->num_count = 1;
	j = 0;
	while (argv[data->num_count])
	{
		data->nums_str[j] = ft_strdup(argv[data->num_count]);
		if (!data->nums_str[j])
			ft_error(data, "Error\n");
		data->num_count++;
		j++;
	}
	data->nums_str[j] = NULL;
}

void	ft_savenum(t_data *data, int i)
{
	data->num_count = i;
	data->numbers = (int *)malloc(sizeof(int) * (data->num_count));
	if (!data->numbers)
		ft_error(data, "Error\n");
	i = 0;
	while (i < data->num_count)
	{
		data->numbers[i] = ft_atops(data->nums_str[i], data);
		ft_printf("Num[%i]: %i\n", i, data->numbers[i]);
		i++;
	}
}

void	ft_checknum(t_data *data)
{
	int		i;
	int		j;

	data->num_count = 0;
	i = 0;
	while (data->nums_str[i])
	{
		j = 0;
		if (data->nums_str[i][j] == '\0')
			ft_error(data, "Error\n");
		while (data->nums_str[i][j] != '\0')
		{
			if (!ft_isdigit(data->nums_str[i][j])
				&& !((data->nums_str[i][j] == '+'
					|| data->nums_str[i][j] == '-')
						&& ft_isdigit(data->nums_str[i][j + 1])))
				ft_error(data, "Error\n");
			ft_printf("numero: %c\n", data->nums_str[i][j]);
			j++;
		}
		ft_printf("numero entero: %s\n", data->nums_str[i]);
		i++;
	}
	ft_savenum(data, i);
}

void	ft_checkrepeat(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->num_count)
	{
		j = i + 1;
		while (j < data->num_count)
		{
			if (data->numbers[j] == data->numbers[i])
				ft_error(data, "Error\n");
			j++;
		}
		i++;
	}
}

void	ft_parsing(int argc, char *argv[], t_data *data)
{
	if (argc == 2)
	{
		data->nums_str = ft_split(argv[1], ' ');
		if (data->nums_str == NULL)
			ft_error(data, "Error\n");
		ft_checknum(data);
		ft_checkrepeat(data);
	}
	else if (argc > 2)
	{
		ft_savestr(argv, data);
		if (data->nums_str == NULL)
			ft_error(data, "Error\n");
		ft_checknum(data);
		ft_checkrepeat(data);
	}
}
