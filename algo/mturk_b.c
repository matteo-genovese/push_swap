/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mturk_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:21:25 by mgenoves          #+#    #+#             */
/*   Updated: 2024/09/20 18:17:53 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/push_swap.h"

int	move_correct_index_b(t_stack *stack, int num)
{
	int	i;
	int	n;
	int	i_n;

	i = -1;
	while (++i < stack->size_b)
	{
		if (num > stack->stack_b[i])
			break ;
	}
	if (i == stack->size_b)
		return (get_n_min_stack_b(stack) + 1);
	n = stack->stack_b[i];
	i_n = i;
	while (++i < stack->size_b)
	{
		if (stack->stack_b[i] > n && stack->stack_b[i] < num)
		{
			n = stack->stack_b[i];
			i_n = i;
		}
	}
	return (i_n);
}

void	rotate_to_sort_b(t_stack *stack)
{
	int	max;
	int	i;
	int	i_max;

	i = 0;
	max = stack->stack_b[0];
	i_max = 0;
	while (++i < stack->size_b)
	{
		if (stack->stack_b[i] > max)
		{
			max = stack->stack_b[i];
			i_max = i;
		}
	}
	while (stack->stack_b[0] != max)
	{
		if (i_max <= stack->size_b / 2)
			rb(stack);
		else
			rrb(stack);
	}
}

void	move_to_top_b(t_stack *stack, int index)
{
	if (index <= stack->size_b / 2)
		while (index-- > 0)
			rb(stack);
	else
		while (index++ < stack->size_b)
			rrb(stack);
}

int	get_n_min_stack_b(t_stack *stack)
{
	int	i;
	int	min;
	int	i_min;

	i = 0;
	min = stack->stack_b[0];
	i_min = 0;
	while (++i < stack->size_b)
	{
		if (stack->stack_b[i] < min)
		{
			min = stack->stack_b[i];
			i_min = i;
		}
	}
	return (i_min);
}
