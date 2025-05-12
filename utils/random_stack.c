/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:48:42 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/17 20:06:20 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

void	init_stack(int argc, char **argv, t_stack *stack)
{
	if (argc == 2)
	{
		(*stack).size_a = ft_count_words(argv[1], ' ');
		(*stack).stack_a = ft_split_int(argv[1], ' ');
		(*stack).stack_b = (int *)malloc(((*stack).size_a + 1) * sizeof(int));
	}
	else
	{
		(*stack).size_a = argc - 1;
		(*stack).stack_a = (int *)malloc(((*stack).size_a + 1) * sizeof(int));
		(*stack).stack_b = (int *)malloc(((*stack).size_a + 1) * sizeof(int));
		copy_stack(argv, argc, (*stack).stack_a);
	}
	(*stack).size_b = 0;
}

void	copy_stack(char **argv, int argc, int *temp)
{
	int		i;

	i = -1;
	if (!temp)
	{
		free(temp);
		return ;
	}
	while (++i < argc - 1)
		temp[i] = ft_atoi(argv[i + 1]);
}

void	free_stack(t_stack *stack)
{
	if ((*stack).stack_a)
		free((*stack).stack_a);
	if ((*stack).stack_b)
		free((*stack).stack_b);
}
