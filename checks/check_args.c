/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:43:09 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/18 22:17:27 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

int	check_num(char **argv, int k)
{
	int	i[2];

	i[0] = -1;
	if (argv[0] && argv[0][0] == '.')
		i[0] = 0;
	while (++(i[0]) < k)
	{
		i[1] = -1;
		while (argv[i[0]][++(i[1])])
		{
			if (!ft_isdigit(argv[i[0]][i[1]]))
			{
				if (argv[i[0]][i[1]] == '-' || argv[i[0]][i[1]] == '+')
				{
					if (!ft_isdigit(argv[i[0]][i[1] + 1]))
						return (0);
				}
				else
					return (0);
			}
		}
		if (!check_min_max(argv[i[0]]))
			return (0);
	}
	return (1);
}

int	check_doubles(char **argv, int k)
{
	int	i;
	int	j;

	i = 0;
	if (argv[0] && argv[0][0] == '.')
		i = 1;
	while (i < k)
	{
		j = i + 1;
		while (j < k)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			if (check_valid_str(argv[i]) == 0 || check_valid_str(argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_empty(char **argv, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		if (ft_strlen(argv[i]) == 0)
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	check_min_max(char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(str) > 11
			|| (ft_strlen(str) == 11 && ft_strcmp(str, "-2147483648") > 0))
			return (0);
	}
	else
	{
		if (ft_strlen(str) > 10
			|| (ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0))
			return (0);
	}
	return (1);
}

int	check_valid_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i > 0)
			{
				if (str[i - 1] != ' ')
					return (0);
			}
			else
			{
				if (!ft_isdigit(str[i + 1]))
					return (0);
			}
		}
		i++;
	}
	return (1);
}
