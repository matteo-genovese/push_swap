/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:23:54 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/17 19:23:06 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

int	final_check(int argc, char **argv)
{
	char	**temp;
	int		i;

	i = argc;
	if (i == 2)
	{
		if (check_valid_str(argv[1]) == 0)
			return (0);
		temp = ft_split(argv[1], ' ');
		i = 0;
		while (temp[i])
			i++;
	}
	else
	{
		temp = (char **)malloc((i + 1) * sizeof(char *));
		copy_argv(argv, argc, temp);
	}
	if (!check_empty(temp, i) || !check_doubles(temp, i) || !check_num(temp, i))
	{
		free_split(temp, i);
		return (0);
	}
	free_split(temp, i);
	return (1);
}

void	print_argv(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_putstr_fd(argv[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	free_split(char **split, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	copy_argv(char **argv, int argc, char **temp)
{
	int		i;

	i = argc;
	if (!temp)
	{
		free(temp);
		return ;
	}
	while (i--)
	{
		temp[i] = (char *)malloc((ft_strlen(argv[i]) + 1) * sizeof(char));
		if (!temp[i])
		{
			free_split(temp, argc);
			return ;
		}
		ft_strlcpy(temp[i], argv[i], ft_strlen(argv[i]) + 1);
	}
}
